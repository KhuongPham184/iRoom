int latchPin = 8;
int clockPin = 12;
int dataPin = 11;

//unsigned long time = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;

byte ledStatus;

void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
}

void loop(){
  ledStatus = 0; //0 = 0b00000000 (hệ nhị phân)
  for (int i = 0; i < 8; i++) //0 - 7
  {
    
      ledStatus = (ledStatus << 1) | 1; 
      //Đẩy toàn bộ các bit qua trái 1 bit và thực hiện phép toán OR với 1 
      //0 OR 0 = 0
      //0 OR 1 = 1
      //1 OR 1 = 1
      //1 OR 0 = 1
      
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);
      digitalWrite(latchPin, HIGH);
      delay(100);
  }

  for (int i = 0; i<8; i++){
    ledStatus <<=1;
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);
    digitalWrite(latchPin,HIGH);
    delay(1000);
  }
}
