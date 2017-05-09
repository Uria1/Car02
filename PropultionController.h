class PropultionController {
  private:
    SysConfig* config;
    const float speedToValueRatio = 100.0f / 255.0f;
    const int easeLowValue = 80;
    const ms easeInDuration = 500;
    const ms easeOutDuration = 500;

    void setForward(int value) {
      analogWrite(config->pins->drivingPins->Forward, value);
    }
    void setBackward(int value) {
      analogWrite(config->pins->drivingPins->Backward, value);
    }

    int ease(ms totalDuration, ms elapsedTime, int value) {
      return TimeFunctions::ease(easeLowValue, value, totalDuration, elapsedTime, easeInDuration, easeOutDuration);
    }

    int speedToValue(int speed) {
      return speed / speedToValueRatio;
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
            setForward(this->ease(action->duration, action->elapsedTime(), this->speedToValue(action->speed)));
            break;
          case Backward:
            setForward(0);
            setBackward(this->ease(action->duration, action->elapsedTime(), this->speedToValue(action->speed)));
        }
      } else {
        stop();
      }
    }
};

