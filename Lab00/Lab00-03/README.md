## การทดสอบและเปรียบเทียบ

### การทดสอบ Cooperative System
1. Build และ flash โปรแกรมโดย uncomment `test_cooperative_multitasking()`
2. กดปุ่มหลายครั้งและสังเกตเวลาตอบสนอง
3. บันทึกเวลาตอบสนองสูงสุด

### การทดสอบ Preemptive System
1. แก้ไขโค้ดโดย uncomment `test_preemptive_multitasking()`
2. Build และ flash ใหม่
3. กดปุ่มหลายครั้งและเปรียบเทียบเวลาตอบสนอง

## คำถามสำหรับวิเคราะห์

1. ระบบไหนมีเวลาตอบสนองดีกว่า? เพราะอะไร?
2. ข้อดีของ Cooperative Multitasking คืออะไร?
3. ข้อเสียของ Cooperative Multitasking คืออะไร?
4. ในสถานการณ์ใดที่ Cooperative จะดีกว่า Preemptive?
5. เหตุใด Preemptive จึงเหมาะสำหรับ Real-time systems?