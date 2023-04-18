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

int storedData[6000];

void setup() {
  Serial.begin(115200);
}

void loop() {
 
  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  buttonState = digitalRead(buttonPin);
  
 
   if (digitalRead(OUT_PIN) == LOW) {
     sampleBufferValue++;
   }
   if (millisElapsed > SAMPLE_TIME) {
     //Serial.println(sampleBufferValue);
     sampleBufferValue = 0;
     millisLast = millisCurrent;
   }
   if (millis() < 1500)
 Serial.println(sampleBufferValue);
  
}
