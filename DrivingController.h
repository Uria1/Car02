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
      ms rd = action->remainingDuration();
      if (rd > 0) {
        this->go(Backward, Straight, 50, 500);
      } else {
      }

    }

    void go(DrivingDirection dd, SteeringDirection sd, speed speed, ms duration) {

    }
};

