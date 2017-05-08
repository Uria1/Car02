class SteeringController {
  private:
    SysConfig* config;
    const int easeIn = 1000;
    const int easeOut = 1000;
    const int easeLowValue = 80;
    const int easeHighValue = 240;

    void setRight(int value) {
      analogWrite(config->pins->Right, value);
    }

    void setLeft(int value) {
      analogWrite(config->pins->Left, value);
    }

    int ease(ms totalDuration, ms elapsedTime) {
      return TimeFunctions::ease(easeLowValue, easeHighValue, totalDuration, elapsedTime, easeIn, easeOut);
    }
  public:
    SteeringController(SysConfig* config) {
      this->config = config;
    }

    void clear() {
      setRight(0);
      setLeft(0);
    }

    void init() {
      this->clear();
    }

    void render(DriveAction* action) {
      if (action->active()) {
        switch (action->steeringDirection) {
          case Straight:
            this->clear();
          case Right:
            setLeft(0);
            setRight(this->ease(action->duration, action->elapsedTime()));
            break;
          case Left:
            setRight(0);
            setLeft(this->ease(action->duration, action->elapsedTime()));
            break;
        }
      } else {
        this->clear();
      }
    }
};
