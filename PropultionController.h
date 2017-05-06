class PropultionController {
    SysConfig* config;
  public:
    PropultionController(SysConfig* config) {
      this->config = config;
    }
    void init() {
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

