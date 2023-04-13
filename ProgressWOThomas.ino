const int OUT_PIN = A0;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int sampleBufferValue = 0;
int sampleBufferValue2 = 0;

int buttonState=0; 
const int buttonPin = 2;
const int ledPin = 13;

unsigned long millisLast2 = 0;
unsigned long millisElapsed2 = 0;
const int memoryTime = 1500;

void setup() { 
   Serial.begin(9600);
   pinMode(ledPin,OUTPUT);
   pinMode(buttonPin,INPUT);
 }

 void loop() {

buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  //if (buttonState == HIGH) {
    // turn LED on:
    //Serial.println(sampleBufferValue);
  //}

   millisCurrent = millis();
   millisElapsed = millisCurrent - millisLast;  
   Serial.println(millisCurrent);

  millisElapsed2 = millisCurrent - millisLast2;  


   if (digitalRead(OUT_PIN) == LOW) {
     sampleBufferValue++;
     sample
   }
 
   if (millisElapsed > SAMPLE_TIME) {
     //Serial.println(sampleBufferValue);
     storedSampleBufferValue = sampleBufferValue;
     sampleBufferValue = 0;
     millisLast = millisCurrent;
   }

if (millisElapsed2 > memoryTime) {
     
   }
   
 
   }
