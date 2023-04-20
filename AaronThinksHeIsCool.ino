const int OUT_PIN = A0;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

int sampleBufferValue = 0;
int maxSampleBufferValue = 0;
unsigned long millisLast2 = 0;
unsigned long millisElapsed2 = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  millisElapsed2 = millisCurrent - millisLast2;
  

  if (digitalRead(OUT_PIN) == LOW) {
    sampleBufferValue++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    //Serial.println(sampleBufferValue);
    if (sampleBufferValue > maxSampleBufferValue){
          maxSampleBufferValue = sampleBufferValue;
          Serial.println(maxSampleBufferValue);
      }
    sampleBufferValue = 0;
    millisLast = millisCurrent;
  }
  if (millisElapsed2 > 1500){
        maxSampleBufferValue = 0; 
        millisLast2 = millisCurrent;
  }
 

}
