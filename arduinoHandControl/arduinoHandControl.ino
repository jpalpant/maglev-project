#define DIGITALIO_NO_MIX_ANALOGWRITE
#include <digitalIOPerformance.h>

const int sensEchoPin = 4;
const int sensTrigPin = 5;
const int pwmPin = 3;
const int ledRangePin = 2;

double maxDistCM = 30;

int loopDelay = 20; //ms

void setup() {
  pinMode(sensTrigPin, OUTPUT);
  pinMode(sensEchoPin, INPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(ledRangePin, OUTPUT);
  
  digitalWrite(sensTrigPin, LOW);
}

void loop() {
  //Query sensor
  // pulse low-HIGH-low > 10uS
  digitalWrite(sensTrigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(sensTrigPin, LOW);
  
  //Wait for pin HIGH
  
  while(digitalRead(sensEchoPin) == LOW) {
    delayMicroseconds(1);
  }
  long pulseStart = micros(); //Log time on pin high
  while(digitalRead(sensEchoPin) == HIGH && micros() - pulseStart <= (59 * maxDistCM)) {
    delayMicroseconds(1);
  }
  long pulseEnd = micros(); //Log time when pin goes low again
  
  long pulseTime = pulseEnd - pulseStart; //Calculate total pulse time
  
  double pingDistCM = pulseTime / 58;

  int handHeightVoltage = 128;  //default middle value
  
  if(pingDistCM >= maxDistCM) {
    digitalWrite(ledRangePin, LOW);
  }
  else {
    digitalWrite(ledRangePin, HIGH);
    handHeightVoltage = (pingDistCM/maxDistCM) * 255;
  }
  
  analogWrite(pwmPin, handHeightVoltage);
  
  delay(loopDelay);
}
