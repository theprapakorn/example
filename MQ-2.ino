/*
การต่ออุปกรณ์ สามารถอ่านเพิ่มได้ที่ Link : https://www.ab.in.th/b/12
*/

int sensorThres = 300;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400

void setup() {
  Serial.begin(9600);
   pinMode(A0, INPUT);
   pinMode(D0, OUTPUT);
}

void loop() {
  int analogSensor = analogRead(A0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor); 

  if (analogSensor > sensorThres)  {
    Serial.print("WARNING");
    digitalWrite(D0,LOW);
    
  }

  else  {
    
    digitalWrite(D0,HIGH);
  }
  delay(100);
}
