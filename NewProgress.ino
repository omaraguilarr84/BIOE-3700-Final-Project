const int OUT_PIN = A0;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;

unsigned long millisLast2 = 0;
unsigned long millisElapsed2 = 0;
const int memoryTime = 1500;

int buttonState=0; 
const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
}

 void loop() {
 
   millisCurrent = millis();
   millisElapsed = millisCurrent - millisLast;

   millisElapsed2 = millisCurrent - millisLast2;

  buttonState = digitalRead(buttonPin);
  
 
   if (digitalRead(OUT_PIN) == LOW) {
     sampleBufferValue++;
   }
   if (millisElapsed > SAMPLE_TIME) {
     //Serial.println(sampleBufferValue);
     sampleBufferValue = 0;
     millisLast = millisCurrent;
   }
  if (buttonState == HIGH){
      millisLast2 = millis();
      millisElapsed2 = millisCurrent - millisLast2;
            if (millisElapsed2 > memoryTime) {
            Serial.println(sampleBufferValue);
            sampleBufferValue = 0;
            millisLast = millisCurrent;
      }
  }
 }  


 
