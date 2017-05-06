class DrivingTestActivity: public Activity {
    DrivingController* dc;
    DriveAction* currentAction;
  public:
    DrivingTestActivity(DrivingController* d) {
      dc = d;
      currentAction = new DriveAction();
    }

    void update(ms millis) {
      if (!currentAction->active) {
        currentAction->active = true;
        currentAction->goBackward(1000);
      }
    }

    void render(ms millis) {
      if (currentAction->active) {
        dc->render(currentAction);
      }
    }
};
