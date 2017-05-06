#include "typedefs.h"
#include "PinConfig.h"
#include "SteeringDirection.h"
#include "DrivingDirection.h"
#include "StateMonitor.h"
#include "DriveAction.h"
#include "PropultionController.h"
#include "SteeringController.h"
#include "DrivingController.h"
#include "Activity.h"
#include "ProximityFollowing.h"
#include "SystemController.h"

const int builtInLed = 13;
const int pinFwd = 4; //brown
const int pinBwd = 5; //blue
const int pinLeft = 3; //white/green
const int pinRight = 2; //red

const int frameInterval = 100;
SystemController* systemController;

void setup() {
  systemController = new SystemController();
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


