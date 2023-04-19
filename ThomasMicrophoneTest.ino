
const int OUT_PIN = A0;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
const int NUM_SAMPLES = 150;
int sampleBufferValue = 0;
int soundData[NUM_SAMPLES];
int sampleIndex = 0;
int i = 0; 

void setup() {
  Serial.begin(9600);
}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) {
    sampleBufferValue++;
  //  soundData[sampleIndex] = sampleBufferValue;
  //  sampleIndex++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    for(int i = 0; i < NUM_SAMPLES; i++) {
    soundData[sampleIndex] = sampleBufferValue;
    sampleIndex++;
    Serial.print(soundData[i]);
    Serial.print(",");
    }
    Serial.println();
    
    
   
    sampleBufferValue = 0;
    millisLast = millisCurrent;
  }
 
  }
