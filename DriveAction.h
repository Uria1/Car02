
class DriveAction : public Action {
  public:
    DrivingDirection drivingDirection;
    SteeringDirection steeringDirection;

    void goBackward(ms duration) {
      this->active = true;
      this->startTime = millis();
      this->drivingDirection = Backward;
      this->steeringDirection = Straight;
      this->duration = duration;
    }
};
