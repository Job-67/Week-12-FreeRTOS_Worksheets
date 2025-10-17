## 📊 การสังเกตและบันทึกผล

### ตารางผลการทดลอง
| ทดลอง | Successful | Failed | Corrupted | Success Rate | สังเกต |
|-------|------------|--------|-----------|-------------|---------|
| 1 (With Mutex) | | | | | |
| 2 (No Mutex) | | | | | |
| 3 (Changed Priority) | | | | | |

## คำถามทบทวน

1.  **เมื่อไม่ใช้ Mutex จะเกิด data corruption หรือไม่?**
    *   **มีโอกาสเกิดขึ้นสูงมาก** เมื่อไม่มีการใช้ Mutex เพื่อป้องกัน Shared Resource (ข้อมูลที่ใช้ร่วมกัน) จะเกิดสภาวะที่เรียกว่า **Race Condition** ซึ่ง Task หลายตัวพยายามเข้าถึงและแก้ไขข้อมูลเดียวกันในเวลาใกล้เคียงกัน ทำให้การแก้ไขข้อมูลจาก Task หนึ่งอาจถูกเขียนทับและสูญหายไปโดย Task อื่น ส่งผลให้ข้อมูลผิดเพี้ยน (Data Corruption) และระบบทำงานผิดพลาดอย่างไม่คาดคิด

2.  **Priority Inheritance ทำงานอย่างไร?**
    *   Priority Inheritance เป็นกลไกใน Mutex ของ FreeRTOS เพื่อแก้ปัญหา **Priority Inversion** (สถานการณ์ที่ Task Priority สูงต้องรอ Task Priority ต่ำ) โดยมีขั้นตอนดังนี้:
        1.  เมื่อ Task Priority สูง (H) พยายามจะเข้าถึง Mutex ที่ถูกถือครองโดย Task Priority ต่ำ (L) อยู่, Task H จะเข้าสู่สถานะ Blocked
        2.  Scheduler จะตรวจพบสถานการณ์นี้ และทำการ **"ยก" Priority ของ Task L ให้สูงขึ้นชั่วคราว** จนมีค่าเท่ากับ Priority ของ Task H
        3.  การทำเช่นนี้จะช่วยให้ Task L (ที่ตอนนี้มี Priority สูง) ทำงานใน Critical Section ของตัวเองให้เสร็จได้อย่างรวดเร็ว โดยไม่ถูก Task Priority ปานกลาง (M) เข้ามาขัดจังหวะ
        4.  เมื่อ Task L ปล่อย Mutex, Priority ของมันจะกลับคืนสู่ระดับปกติตามเดิม และ Task H ก็จะสามารถเข้าถึง Mutex และทำงานต่อไปได้

3.  **Task priority มีผลต่อการเข้าถึง shared resource อย่างไร?**
    *   Task Priority มีผลโดยตรงต่อลำดับและโอกาสในการเข้าถึง Shared Resource ที่มีการป้องกันด้วย Mutex:
        *   **การเข้าคิว:** เมื่อ Mutex ถูกปล่อย และมี Task หลายตัวกำลังรออยู่ Task ที่มี **Priority สูงที่สุด** ในบรรดาตัวที่กำลังรอ จะได้รับสิทธิ์ในการเข้าถึง Mutex นั้นก่อนเสมอ
        *   **การเกิด Priority Inversion:** หากไม่มีกลไก Priority Inheritance, Task Priority สูงอาจจะต้องรอ Task Priority ต่ำที่ถือ Resource อยู่นานผิดปกติ เพราะมี Task Priority ปานกลางเข้ามาวิ่งแทรก
        *   **การทำงานของ Priority Inheritance:** ดังที่อธิบายในข้อ 2, Priority ของ Task ที่กำลังรอ Resource สามารถส่งผลไปถึง Priority ของ Task ที่กำลังถือ Resource อยู่ได้ เพื่อเร่งให้เกิดการปล่อย Resource เร็วขึ้น

## 📋 สรุปผลการทดลอง
