## Checklist การทำงาน

- [ ] สร้าง Task พื้นฐานสำเร็จ
- [ ] เข้าใจ Task parameters และ return values
- [ ] ทดสอบ Task priorities
- [ ] ใช้ Task management APIs (suspend/resume)
- [ ] แสดง runtime statistics
- [ ] ทำแบบฝึกหัดครบ

## คำถามทบทวน

1. เหตุใด Task function ต้องมี infinite loop?
2. ความหมายของ stack size ใน xTaskCreate() คืออะไร?
3. ความแตกต่างระหว่าง vTaskDelay() และ vTaskDelayUntil()?
4. การใช้ vTaskDelete(NULL) vs vTaskDelete(handle) ต่างกันอย่างไร?
5. Priority 0 กับ Priority 24 อันไหนสูงกว่า?