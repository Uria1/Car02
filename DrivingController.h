class DrivingController {
    SysConfig* config;
    PropultionController* propultionController;
    SteeringController* steeringController;

  public:
    DrivingController(SysConfig* config) {
      this->config = config;
      propultionController = new PropultionController(config);
      steeringController = new SteeringController(config);
    }

    void init() {
      propultionController->init();
      steeringController->init();
    }

    void render(DriveAction* action, ms millis) {
      if (action->active()) {
        steeringController->steer(action->steeringDirection, action->elapsedTime());
        propultionController->go(action->drivingDirection, action->elapsedTime());
      } else {
        steeringController->steer(Straight, action->elapsedTime());
        propultionController->stop();
      }
    }

};

