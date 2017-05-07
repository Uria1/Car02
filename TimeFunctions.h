class TimeFunctions {
  public:
    static int ease(int startValue, int endValue, ms totalDuration, ms elapsedTime, ms easeInDuration, ms easeOutDuration) {
     if (elapsedTime < easeInDuration) {
        //ease in
        float f = (float)elapsedTime / (float)easeInDuration;
        return value * f;
      } else if (elapsedTime > totalDuration - easeOutDuration) {
        //ease out
        //float f = (float)
      }
      return value;
    }
}

