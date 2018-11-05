#include "Factorial.h"
#include <cmath>

int factorial(int value) {
  if(std::abs(value) > 12) return 0;
  int result = 1;
  for(int i = 2; i <= std::abs(value); i++) result *= i;
  if(value < 0 && (value % 2)) result *= (-1);
  return result;
}
