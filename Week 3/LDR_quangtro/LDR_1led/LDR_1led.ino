int quangtro = A5;
//int bientro = A4;
int led = 2;


void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  int giatriQuangTro = analogRead(quangtro);
  //int giatriBienTro = analogRead(bientro);
  Serial.println(giatriQuangTro);

  if(giatriQuangTro <= 80)    //giá trị quang trở đo được sẽ dao động từ 0 - 1024
  {
    digitalWrite(led, HIGH);
  }else {
    digitalWrite(led, LOW);
  }

  Serial.print("Quang Tro: ");
  Serial.print(giatriQuangTro);
  //Serial.print("Bien Tro: ");
  //Serial.print(giatriBienTro);
  //Serial.print(" => ");
  Serial.println((giatriQuangTro <= 300) ? "Sang" : "Tat");
}
