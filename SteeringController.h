class SteeringController {
    SysConfig* config;
  public:
    SteeringController(SysConfig* config) {
      this->config = config;
    }
    void init() {
      setRight(0);
      setLeft(0);
    }
    void steer(SteeringDirection sd) {
      switch (sd) {
        case Right:
          setLeft(0);
          setRight(255);
          break;
        case Left:
          setRight(0);
          setLeft(255);
          break;
      }
    }
  private:
    void setRight(int value) {
      analogWrite(config->pins->Right, value);
    }
    void setLeft(int value) {
      analogWrite(config->pins->Left, value);
    }
};
