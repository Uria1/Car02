class PropultionController {
  private:
    SysConfig* config;
    ms easeIn = 3000;

    void setForward(int value) {
      analogWrite(config->pins->drivingPins->Forward, value);
    }
    void setBackward(int value) {
      analogWrite(config->pins->drivingPins->Backward, value);
    }

    int ease(ms totalDuration, ms elapsedTime, int value) {
      return TimeFunctions::ease(80, value, totalDuration, elapsedTime, 1000, 1000);
    }

  public:
    PropultionController(SysConfig* config) {
      this->config = config;
    }

    void init() {
      stop();
    }

    void stop() {
      setForward(0);
      setBackward(0);
    }

    void render(DriveAction* action) {
      if (action->active()) {
        switch (action->drivingDirection) {
          case Forward:
            setBackward(0);
            setForward(this->ease(action->duration, action->elapsedTime(), 255));
            break;
          case Backward:
            setForward(0);
            setBackward(this->ease(action->duration, action->elapsedTime(), 255));
        }
      } else {
        stop();
      }
    }
};

