
class DriveAction : public Action {
  private:
    void start(SteeringDirection sd, DrivingDirection dd, ms duration, int speed) {
      this->startTime = millis();
      this->steeringDirection = sd;
      this->drivingDirection = dd;
      this->duration = duration;
      this->speed = speed;
    }

  public:
    DrivingDirection drivingDirection;
    SteeringDirection steeringDirection;
    int speed;

    void stop() {
      this->duration = 0;
    }
    void reverse(ms duration, int speed) {
      this->start(Straight, Backward, duration, speed);
    }
    void advance(ms duration, int speed) {
      this->start(Straight, Forward, duration, speed);
    }
    void reverseLeft(ms duration, int speed) {
      this->start(Left, Backward, duration, speed);
    }
    void advanceLeft(ms duration, int speed) {
      this->start(Left, Forward, duration, speed);
    }
    void reverseRight(ms duration, int speed) {
      this->start(Right, Backward, duration, speed);
    }
    void advanceRight(ms duration, int speed) {
      this->start(Right, Forward, duration, speed);
    }
};
