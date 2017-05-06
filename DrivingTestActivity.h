class DrivingTestActivity: public Activity {
    DrivingController* dc;
    DriveAction* currentAction;
    boolean started = false;
  public:
    DrivingTestActivity(DrivingController* d) {
      dc = d;
      currentAction = new DriveAction();
    }

    void update(ms millis) {
      if (!started) {
        started = true;
        currentAction->goBackward(1000);
      }
    }

    void render(ms millis) {
      if (currentAction->active()) {
        dc->render(currentAction, millis);
      }
    }
};
