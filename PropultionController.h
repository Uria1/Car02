class PropultionController {
    SysConfig* config;
  public:
    PropultionController(SysConfig* config) {
      this->config = config;
    }
    void init() {
      stop();
    }
    void go(DrivingDirection dd) {
      switch (dd) {
        case Forward:
          setBackward(0);
          setForward(200);
          break;
        case Backward:
          setForward(0);
          setBackward(200);
      }
    }
    void stop() {
      setForward(0);
      setBackward(0);
    }
  private:
    void setForward(int value) {
      analogWrite(config->pins->Forward, value);
    }
    void setBackward(int value) {
      analogWrite(config->pins->Backward, value);
    }
};

