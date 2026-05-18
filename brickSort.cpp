#ifndef BRICKSORT_CPP
#define BRICKSORT_CPP

#include <vector>

using namespace std;

void bricksort(vector<int> &T) {

  int n = T.size();

  for (int i = 0; i < n - 1; i++) {

    int min = i;

    for (int j = i + 1; j < n; j++) {

      if (T[j] < T[min]) {
        min = j;
      }
    }

    while (min > i) {

      swap(T[min], T[min - 1]);
      min--;
    }
  }
}

#endif
