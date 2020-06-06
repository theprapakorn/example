int A = D1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
pinMode (A,INPUT);  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {

 int x = digitalRead(A);
Serial.println(x);

if(x == LOW){ 
  digitalWrite(LED_BUILTIN, LOW); 
delay(2000);
}


}
