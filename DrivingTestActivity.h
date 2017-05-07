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
      //start after 2 seconds
      if (!started && millis > 2000) {
        started = true;
        currentAction->reverse(5000);
      }
    }

    void render(ms millis) {
      dc->render(currentAction, millis);
    }
};
