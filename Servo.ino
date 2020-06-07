include <Servo.h> // เรียกใช้ไลบารี่ Servo.h

Servo myservo; // สร้างออปเจค myservo จากคลาส Servo

void setup() {
  myservo.attach(9); // กำหนดต่อเซอร์โวไว้ที่ขา 9
}

void loop() {
  myservo.write(0); // หมุนตามเข็มนาฬิกา
  delay(2000); // หน่วงเวลา 2 วิ
  myservo.write(90); // หยุดนิ่ง
  delay(2000); // หน่วงเวลา 2 วิ
  myservo.write(180); // หมุนทวนเข็มนาฬิกา
  delay(2000); // หน่วงเวลา 2 วิ
}
