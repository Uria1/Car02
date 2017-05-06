#include "typedefs.h"
#include "SteeringDirection.h"
#include "StateMonitor.h"
#include "Action.h"
#include "DrivingDirection.h"
#include "DriveAction.h"
#include "PropultionController.h"
#include "SteeringController.h"
#include "DrivingController.h"
#include "Activity.h"
#include "ProximityFollowing.h"
#include "SystemController.h"

ms frameStart;
const int frameInterval = 100;
SystemController* systemController;

void setup() {
  systemController = new SystemController();
}

void loop() {
  update();
}

void update() {
  frameStart = millis();

  systemController->readState(frameStart);
  systemController->update(frameStart);
  systemController->render(frameStart);

  int sleepTime = frameInterval - (millis() - frameStart);
  if (sleepTime > 0) {
    delay(sleepTime);
  }
}


