
class SystemController {
    StateMonitor* stateMonitor = new StateMonitor();
    DrivingController* drivingController;
    Activity* act1 = new ProximityFollowing(stateMonitor, drivingController);
    Activity* test1 = new DrivingTestActivity(drivingController);
    
  public:
    SystemController(SysConfig* config) {
      this->drivingController = new DrivingController(config);
    }

    void init() {
      drivingController->init();
    }

    void readState(ms millis) {
      stateMonitor->read(millis);
    }

    void update(ms millis) {
      //act1->update(millis);
      test1->update(millis);
    }

    void render(ms millis) {
      //act1->render(millis);
      test1->render(millis);
    }
};
