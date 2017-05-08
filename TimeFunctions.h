class TimeFunctions {
  public:
    static int ease(int startValue, int endValue, ms totalDuration, ms elapsedTime, ms easeInDuration, ms easeOutDuration) {
      ms result;
      if (isEaseIn(elapsedTime, easeInDuration)) {
        float easeInPercentage = (float)elapsedTime / (float)easeInDuration;
        result = (endValue - startValue) * easeInPercentage + startValue;
      } else if (isEaseOut(elapsedTime, totalDuration, easeOutDuration)) {
        ms easeOutMS = elapsedTime - (totalDuration - easeOutDuration);
        float easeOutPercentage = (float)easeOutMS / (float)easeOutDuration;
        result = endValue - easeOutPercentage * (endValue - startValue)
      } else {
        result = endValue;
      }
      if (result < startValue) {
        result = startValue;
      }
      return result;
    }

    static boolean isEaseIn(ms elapsedTime, ms easeInDuration) {
      return elapsedTime < easeInDuration;
    }

    static boolean isEaseOut(ms elapsedTime, ms totalDuration, ms easeOutDuration) {
      return elapsedTime > totalDuration - easeOutDuration;
    }
}

