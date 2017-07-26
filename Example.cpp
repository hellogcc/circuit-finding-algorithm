#include "CircuitFinder.h"

int main()
{
  int A[6][6] = {
    2, 5, 0, 0, 0, 0,
    3, 0, 0, 0, 0, 0,
    1, 2, 4, 6, 0, 0,
    5, 0, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 0,
    4, 0, 0, 0, 0, 0,
  };

  CircuitFinder<6> CF(A);
  CF.run();
  return 0;
}
