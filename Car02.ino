#include "typedefs.h"
#include "DrivingPins.h"
#include "PinConfig.h"
#include "SysConfig.h"
#include "SteeringDirection.h"
#include "DrivingDirection.h"
#include "TimeFunctions.h"
#include "StateMonitor.h"
#include "DriveAction.h"
#include "PropultionController.h"
#include "SteeringController.h"
#include "DrivingController.h"
#include "Activity.h"
#include "ProximityFollowing.h"
#include "DrivingTestActivity.h"
#include "SystemController.h"

/*
   DO NOT REWMOTE:
  const int builtInLed = 13;
  const int pinFwd = 4; //brown
  const int pinBwd = 5; //blue
  const int pinLeft = 3; //white/green
  const int pinRight = 2; //red
*/

const int frameInterval = 40;

SystemController* systemController;

void blinkWait(int times, int interval) {
  for (int i = 0; i < times; i++) {
    digitalWrite(13, 0);
    delay(interval);
    digitalWrite(13, 255);
    delay(interval);
  }
}

void setup() {
  pinMode(13, OUTPUT);

  Serial.begin(9600);
  Serial.println("--- SETUP ---");

  DrivingPins* dp = new DrivingPins();
  dp->builtInLed = 13;
  dp->Forward = 4; //brown
  dp->Backward = 5; //blue
  dp->Left = 3; //white/green
  dp->Right = 2; //red

  PinConfig* pc = new PinConfig(dp);
  SysConfig* sc = new SysConfig(pc);
  systemController = new SystemController(sc);
  systemController->init();
}

void loop() {
  update();
}

void update() {
  ms ms = millis();

  systemController->readState(ms);
  systemController->update(ms);

  systemController->render(ms);

  int sleepTime = frameInterval - (millis() - ms);
  if (sleepTime > 0) {
    Serial.println("frame sleep: " + sleepTime);
    delay(sleepTime);
  }
}


