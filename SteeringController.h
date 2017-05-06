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

  private:
    void setRight(int value) {
      analogWrite(config->pins->Right, value);
    }
    void setLeft(int value) {
      analogWrite(config->pins->Left, value);
    }
};
