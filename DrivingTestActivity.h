class DrivingTestActivity: public Activity {
    DrivingController* dc;
    DriveAction* currentAction;
    int speed = 50;
    ms duration = 300;
    ms nextRun = 100;
    int count = 0;
    boolean fwd = true;
  public:
    DrivingTestActivity(DrivingController* d) {
      dc = d;
      currentAction = new DriveAction();
    }

    void update(ms millis) {
      //start after 3 seconds
      if (speed > 0 & duration > 0 & millis > nextRun) {
        currentAction->stop();
        //Serial.println("speed:");
        // Serial.println(speed);
        if (count == 2) {
          fwd = !fwd;
          count = 0;
        }
        
        if (fwd) {
          currentAction->advance(duration, speed);
        } else {
          currentAction->reverse(duration, speed);
        }
        //speed -= 5;
        Serial.println("duration:");
        Serial.println(duration);
        //duration += 1;
        nextRun += 1000;
        count += 1;
      }
    }

    void render(ms millis) {
      dc->render(currentAction, millis);
    }
};
