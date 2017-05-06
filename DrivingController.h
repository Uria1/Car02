class DrivingController {
    PropultionController* propultionController = new PropultionController();
    SteeringController* steeringController = new SteeringController();

  public:
    void render(DriveAction* action) {
      ms rd = action->getRemainingDuration();
      if (rd > 0) {
        this->go(Backward, Straight, 50, 500);
      } else {
      }

    }

    void go(DrivingDirection dd, SteeringDirection sd, speed speed, ms duration) {
      
    }
};

