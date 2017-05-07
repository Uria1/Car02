class PropultionController {
  private:
    SysConfig* config;
    ms easeIn = 3000;

    void setForward(int value) {
      analogWrite(config->pins->Forward, value);
    }
    void setBackward(int value) {
      analogWrite(config->pins->Backward, value);
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

    void go(DrivingDirection dd, ms elapsedTime) {
      switch (dd) {
        case Forward:
          setBackward(0);
          setForward(this->ease(elapsedTime, 255));
          break;
        case Backward:
          setForward(0);
          setBackward(this->ease(elapsedTime, 255));
      }
    }

    int ease(ms elapsedTime, int value) {
      if (elapsedTime < easeIn) {
        float f = (float)elapsedTime / (float)easeIn;
        return value * f;
      }
      return value;
    }


};

