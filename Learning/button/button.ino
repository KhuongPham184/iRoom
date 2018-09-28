byte ledPin[] = {2,3,4,5,6,7};
byte ledPin2[]= {2,4,6};
byte ledPin1[]= {3,5,7};
byte pinCount;
byte pinCount1;
byte pinCount2;

const int buttonPin = 11;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinCount = sizeof(ledPin);
  pinCount2= sizeof(ledPin2);
  pinCount1= sizeof(ledPin1);
  for (int i=0; i<pinCount; i++){
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i],LOW);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //int buttonStatus = digitalRead(button);
 // Serial.println(buttonStatus);
  buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState){
    if(buttonState == HIGH){
      buttonPushCounter++;
      for (int i=0; i < pinCount; i++){
        digitalWrite(ledPin[i], HIGH);
        delay(100);
      }
      for (int i=pinCount-1; i >= 0; i--){
        digitalWrite(ledPin[i], LOW);
        delay(500);
      }
    }else{}
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0){
    for (int i=0; i < pinCount1; i++){
      digitalWrite(ledPin1[i], HIGH);
      delay(500);
      }
    for (int i=0; i < pinCount2; i++){
      digitalWrite(ledPin2[i], HIGH);
      delay(500);
    }
    
    for (int i=pinCount - 1; i >= 0; i--){
      digitalWrite(ledPin[i], LOW);
      delay(500);
    }  
    }else {}
    
}

  
//  if(buttonStatus == HIGH){
//    for (int i=0; i < pinCount; i++){
//      digitalWrite(ledPin[i], HIGH);
//      delay(22);
//    }
//  }else{
//    for (int i = pinCount-1; i >= 0; i--){
//      digitalWrite(ledPin[i], LOW);
//      delay(22);
//    }
//  }
