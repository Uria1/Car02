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
      steeringController->render(action);
      propultionController->render(action);
    }
};

