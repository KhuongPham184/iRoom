const int RED_PIN = 3;    // led đỏ
const int GREEN_PIN = 5; // led xanh lá
const int BLUE_PIN = 9;  // led xanh dương
const int buttonPin = 11;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 2;


 
// Hằng số đợi giữa mỗi lần đổi trạng thái
 
int DELAY_TIME = 100;  // đơn vị là mili giây nhá - thử thay đổi số này xem sao :3
 
 
void setup()
{
 
  pinMode(buttonPin, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}
 
void loop()
{
    buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState){
    if(buttonState == HIGH){
      buttonPushCounter++;
    }else {
   }
  }
  lastButtonState = buttonState;

  if(buttonPushCounter % 2 == 0){
    displayAllBasicColors();
    }else{
      showSpectrum();}
}
  
  void displayAllBasicColors()
{
  // Tắt toàn bộ các led - cái này dễ mà ha
 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  
  delay(DELAY_TIME);
 
  // Chỉ bật led đỏ
 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);
 
  // Chỉ bật led xanh lá
 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);
 
  // Chỉ bật led xanh dương
 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);
 
  // Bật màu vàng bắng cách bật led đỏ và xanh
 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
 
  delay(DELAY_TIME);
 
  // Xanh lam (Cyan) bằng cách bật led xanh lá và xanh dương
 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);
 
  // Tím (đỏ xanh dương)
 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);
 
  // Màu trắng (tất cả các led)
  // Mình không hiểu nổi vụ con công tô màu cho con quạ :3, đáng lẻ phải ra màu trắng chứ, mà thế quái nào lại ra màu đen :3, chắc do con công pha màu kém quá :D
 
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
 
  delay(DELAY_TIME);
}
 
// Cài đặt hàm showSpectrum
 
 
void showSpectrum()
{
  
  for (int i = 0; i < 768; i++)
  {
    showRGB(i);  // Call RGBspectrum() with our new x
    delay(1);   // Delay 10ms 
  }
}
 
 
// Cài đặt hàm showRGB(int color)
 
// Chúng ta sẽ cài đặt hàm showRGB để mỗi khi nhận một giá trị từ 0 - 767
// nó sẽ chuyển dần dầm các màu của con đèn led rgb thành các màu đỏ - cam - vàng - lục - lam - chàm - tím
 
// mình chia nó thành 3 khu
// đỏ - xanh lục
// xanh lục - xanh lam
// xanh lam - đỏ
 
// gồm có 4 mốc
// 0   = đỏ chét (đỏ 100%)
// 255 = xanh lục 100%
// 511 = xanh dương (100%)
// 767 = lại là đỏ chét
 
// Những con số nằm giữa các màu sẽ được tính toán theo công thức bên dưới (đọc dễ hiểu mà) để ra được các màu cần thiết
 
 
 
void showRGB(int color)
{
  int redPWM;
  int greenPWM;
  int bluePWM;
 
 
 
  if (color <= 255)          // phân vùng 1
  {
    redPWM = 255 - color;    // red đi từ sáng về tắt
    greenPWM = color;        // green đi từ tắt thành sáng
    bluePWM = 0;             // blue luôn tắt
  }
  else if (color <= 511)     // phân vùng 2
  {
    redPWM = 0;                     // đỏ luôn tắt
    greenPWM = 255 - (color - 256); // green đi từ sáng về tắt
    bluePWM = (color - 256);        // blue đi từ tắt thành sáng
  }
  else // color >= 512       // phân vùng 3
  {
    redPWM = (color - 512);         // red tắt rồi lại sáng
    greenPWM = 0;                   // green luôn tắt nhé
    bluePWM = 255 - (color - 512);  // blue sáng rồi lại tắt
  }
 
  // rồi xuất xung ra và chơi thôi :3
 
  analogWrite(RED_PIN, redPWM);
  analogWrite(BLUE_PIN, bluePWM);
  analogWrite(GREEN_PIN, greenPWM);
}
