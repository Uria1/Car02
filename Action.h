class Action {
  public:
    boolean active = false;
    ms startTime;
    ms duration;

    ms getRemainingDuration() {
      ms r = duration - (millis() - startTime);
      if (r > 0) {
        return r;
      }
      return 0;
    }
};

