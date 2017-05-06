
class SystemController {
    StateMonitor* stateMonitor = new StateMonitor();
    DrivingController* drivingController = new DrivingController();

    Activity* act1 = new ProximityFollowing(stateMonitor, drivingController);

  public:
    void init() {
      drivingController->init();
    }

    void readState(ms millis) {
      stateMonitor->read(millis);
    }

    void update(ms millis) {
      act1->update(millis);
    }

    void render(ms millis) {
      act1->render(millis);
    }
};
