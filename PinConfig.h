class PinConfig {
  public:
    PinConfig(DrivingPins* drivingPins) {
      this->drivingPins = drivingPins;
    }
    DrivingPins* drivingPins;
};
