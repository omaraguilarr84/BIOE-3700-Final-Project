const int OUT_PIN1 = A0;
const int OUT_PIN2 = A1;
const int OUT_PIN3 = A2;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

int sampleBufferValue1 = 0;
int maxSampleBufferValue1 = 0;
int sampleBufferValue2 =0;
int maxSampleBufferValue2 = 0;
int sampleBufferValue3 = 0;
int maxSampleBufferValue3 = 0;

unsigned long millisLast2 = 0;
unsigned long millisElapsed2 = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  millisElapsed2 = millisCurrent - millisLast2;
  

  if (digitalRead(OUT_PIN1) == LOW) {
    sampleBufferValue1++;
  }
  if (digitalRead(OUT_PIN2) == LOW) {
    sampleBufferValue2++;
  }
  if (digitalRead(OUT_PIN3) == LOW) {
    sampleBufferValue3++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    
    if (sampleBufferValue1 > maxSampleBufferValue1){
          maxSampleBufferValue1 = sampleBufferValue1;
          Serial.println("Mic 1: ");
          Serial.println(maxSampleBufferValue1);
      }
    if (sampleBufferValue2 > maxSampleBufferValue2){
          maxSampleBufferValue2 = sampleBufferValue2;
          Serial.println("Mic 2: ");
          Serial.println(maxSampleBufferValue2);
      }
    if (sampleBufferValue3 > maxSampleBufferValue3){
          maxSampleBufferValue3 = sampleBufferValue3;
          Serial.println("Mic 3: ");
          Serial.println(maxSampleBufferValue3);
      }

    sampleBufferValue1 = 0;
    sampleBufferValue2 = 0;
    sampleBufferValue3 = 0;
    millisLast = millisCurrent;
  }
  if (millisElapsed2 > 5000){
        maxSampleBufferValue1 = 0; 
        maxSampleBufferValue2 = 0; 
        maxSampleBufferValue3 = 0;
        millisLast2 = millisCurrent;
  }
 

}
