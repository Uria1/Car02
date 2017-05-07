
class DriveAction : public Action {
  private:
    void start(SteeringDirection sd, DrivingDirection dd, ms duration) {
      this->startTime = millis();
      this->steeringDirection = sd;
      this->drivingDirection = dd;
      this->duration = duration;
    }

  public:
    DrivingDirection drivingDirection;
    SteeringDirection steeringDirection;

    void reverse(ms duration) {
      this->start(Straight, Backward, duration);
    }
    void advance(ms duration) {
      this->start(Straight, Forward, duration);
    }
};
