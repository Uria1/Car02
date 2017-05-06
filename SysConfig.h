class SysConfig {

  public:
    PinConfig* pins;
    
    SysConfig(PinConfig* pins) {
      this->pins = pins;
    }

};
