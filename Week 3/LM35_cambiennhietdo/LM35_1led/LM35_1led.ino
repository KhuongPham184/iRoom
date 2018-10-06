int sensorLM35 = A5;
int led = 2;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  int readingLM35 = analogRead(sensorLM35); //đọc dữ liệu từ cảm biến

  float vol = readingLM35 * 5.0 / 1024;     //tính cường độ dòng điện

  float degree = vol * 100;                 //convert ra nhiệt độ

  Serial.println(degree);
  delay(500);

  if (degree >= 28.00){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
}
