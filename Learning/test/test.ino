byte ledPin[] = {2,3,4,5,6,7,8,9,10,11}; // Mảng lưu vị trí các chân Digital mà các đèn LED sử dụng theo thứ tự từ 1->8. Bạn có thể thêm các LED bằng cách thêm các chân digital vào mảng này
byte ledPin2[] = {3,5,7,9,11};
byte ledPin1[] = {2,4,6,8,10};
byte pinCount; // Khai báo biến pinCount dùng cho việc lưu tổng số chân LED
byte pinCount1;
byte pinCount2;

void setup() {
  pinCount = sizeof(ledPin);  //Xem thêm thông tin về hàm sizeof tại http://arduino.vn/reference/sizeof
  pinCount2 = sizeof(ledPin2);
  pinCount1 = sizeof(ledPin1);
  for (int i=0;i<pinCount;i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}
void loop() {
  /*
    Bật tuần tự các đèn LED
  */
  for (int i=0; i < pinCount; i++) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(500); // Dừng để các đèn LED sáng dần
  }
  /*
    Tắt tuần tự các đèn LED
  */
  for (int i = 0;i < pinCount; i += 1) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
    delay(500); // Dừng để các đèn LED tắt dần
  }

            // CHẴN //
  for (int i=0; i < pinCount2; i++){
    digitalWrite (ledPin2[i], HIGH);
    delay(500);
  }
  for (int i=0; i < pinCount2; i++){
    digitalWrite (ledPin2[i], LOW);
    delay(500);
  }

            // LẺ //
  for (int i=0; i < pinCount1; i++){
    digitalWrite (ledPin1[i], HIGH);
    delay(500);
  }
  for (int i=0; i < pinCount1; i++){
    digitalWrite (ledPin1[i], LOW);
    delay(500);
  }

            // Speed UP//
  for (int y=0; y < 5; y++){
    for (int i=pinCount-1; i >= 0; i--){
      digitalWrite (ledPin[i], HIGH);
      delay(30);
    }
    for (int i=0; i < pinCount; i++){
      digitalWrite (ledPin[i], LOW);
      delay(100);
    }

    for (int i=0; i < pinCount; i++){
      digitalWrite (ledPin[i], HIGH);
      delay(30);
    }
    for (int i=pinCount-1; i >= 0; i--){
      digitalWrite (ledPin[i], LOW);
      delay(100);
    }
 
  }
}
