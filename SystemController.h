
class SystemController {
    StateMonitor* stateMonitor;
    DrivingController* drivingController;
    Activity* act1;
    Activity* test1;

  public:
    SystemController(SysConfig* config) {
      this->stateMonitor = new StateMonitor();
      this->drivingController = new DrivingController(config);

      this->act1 = new ProximityFollowing(stateMonitor, drivingController);
      this->test1 = new DrivingTestActivity(drivingController);
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
