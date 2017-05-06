#include "typedefs.h"
#include "PinConfig.h"
#include "SysConfig.h"
#include "SteeringDirection.h"
#include "DrivingDirection.h"
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

const int frameInterval = 100;

SystemController* systemController;

void setup() {
  PinConfig* pins = new PinConfig();
  pins->builtInLed = 13;
  pins->Forward = 4; //brown
  pins->Backward = 5; //blue
  pins->Left = 3; //white/green
  pins->Right = 2; //red

  SysConfig* c = new SysConfig(pins);

  systemController = new SystemController(c);
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
    delay(sleepTime);
  }
}


