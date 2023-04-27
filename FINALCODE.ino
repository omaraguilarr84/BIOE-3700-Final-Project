

#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

/**
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(2, 3);   // 2:RX 3:TX, you can choose your favourite pins.

uint8_t records[7]; // save record
uint8_t buf[64];

int motor1 = 5;


#define nameHit    (0)


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

int maxVal = 0;
int motor = 5;


void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}


void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup()
{
  /** initialize */
  myVR.begin(9600);

  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)nameHit) >= 0) {
    Serial.println("nameHit loaded");
  }

  
}

void loop()
{

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
          //Serial.println("Mic 1: ");
          //Serial.println(maxSampleBufferValue1);
      }
    if (sampleBufferValue2 > maxSampleBufferValue2){
          maxSampleBufferValue2 = sampleBufferValue2;
          //Serial.println("Mic 2: ");
          //Serial.println(maxSampleBufferValue2);
      }
    if (sampleBufferValue3 > maxSampleBufferValue3){
          maxSampleBufferValue3 = sampleBufferValue3;
          //Serial.println("Mic 3: ");
          //Serial.println(maxSampleBufferValue3);
      }
  }

    sampleBufferValue1 = 0;
    sampleBufferValue2 = 0;
    sampleBufferValue3 = 0;
    millisLast = millisCurrent;

if (millisElapsed2 > 5000){
        maxSampleBufferValue1 = 0; 
        maxSampleBufferValue2 = 0; 
        maxSampleBufferValue3 = 0;
        millisLast2 = millisCurrent;
        maxVal = 0; 
  }


  
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case nameHit:
       
        if (maxSampleBufferValue1 > maxVal) {
        maxVal = maxSampleBufferValue1;
        motor = 12;
    }
    if (maxSampleBufferValue2 > maxVal) {
        maxVal = maxSampleBufferValue2;
        motor = 11;
    }
    if (maxSampleBufferValue3 > maxVal) {
        maxVal = maxSampleBufferValue3;
        motor = 10;
  }
 digitalWrite(motor,HIGH);
 delay(500);
 digitalWrite(motor,LOW);
    
//Serial.println(maxMic);
//Serial.println(maxVal);
   


        break;
      
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}
