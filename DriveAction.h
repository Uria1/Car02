
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
    void reverseLeft(ms duration) {
      this->start(Left, Backward, duration);
    }
    void advanceLeft(ms duration) {
      this->start(Left, Forward, duration);
    }
    void reverseRight(ms duration) {
      this->start(Right, Backward, duration);
    }
    void advanceRight(ms duration) {
      this->start(Right, Forward, duration);
    }
};
