
class StateMonitor {
  public:
    int frontProx;

    void read(unsigned long millis) {
      //read sensors, etc.

      unsigned long l = millis / 5000;
      if (l % 2 == 0) {
        frontProx = 40;
      } else {
        frontProx = 200;
      }
    }
};

