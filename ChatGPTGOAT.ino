const int OUT_PIN = A0;
const int SAMPLE_TIME = 10;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
const int NUM_SAMPLES = 150;
int soundData[NUM_SAMPLES];
int sampleIndex = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) {
    soundData[sampleIndex] = analogRead(A0);
    sampleIndex++;
  }

  if (millisElapsed > 1500) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
      Serial.print(soundData[i]);
      Serial.print(",");
    }
    Serial.println();
    sampleIndex = 0;
    memset(soundData, 0, sizeof(soundData));
    millisLast = millisCurrent;
  }
}
