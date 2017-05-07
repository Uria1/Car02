class SteeringController {
  private:
    SysConfig* config;
    
    void setRight(int value) {
      analogWrite(config->pins->Right, value);
    }
    
    void setLeft(int value) {
      analogWrite(config->pins->Left, value);
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

    void steer(SteeringDirection sd) {
      switch (sd) {
        case Straight:
          this->clear();
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
};
