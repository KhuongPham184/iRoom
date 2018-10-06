//Gọi thư viện DHT
#include "DHT.h"            
 
const int DHTPIN = 2;       //Chân đọc dữ liệu
const int DHTTYPE = DHT22;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
//#define DHTPIN 2
//#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  dht.begin();         //Khởi động cảm biến
}
 
void loop() {
  float h = dht.readHumidity();    //Gọi hàm đọc độ ẩm từ thư viện
  float t = dht.readTemperature(); //Gọi hàm đọc nhiệt độ từ thư viện
 
  Serial.print("Nhiet do: ");
  Serial.println(t);               //Xuất nhiệt độ
  Serial.print("Do am: ");
  Serial.println(h);               //Xuất độ ẩm
  
  Serial.println();                //Xuống hàng
  delay(1000);                     //Đợi 1 giây
}
