#include "typedefs.h"

class Action {
  public:
    ms startTime;
    ms duration;

    boolean active() {
      return elapsedTime() <= duration;
    }
    
    ms elapsedTime() {
      return millis() - startTime;
    }

    ms remainingDuration() {
      ms r = duration - (millis() - startTime);
      if (r > 0) {
        return r;
      }
      return 0;
    }
};

