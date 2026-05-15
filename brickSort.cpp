#ifndef BRICKSORT_CPP
#define BRICKSORT_CPP

#include <vector>

using namespace std;

void bricksort(vector<int> &T) {
  int n = T.size();
  for (int i = n - 1; i > 0; i--) {

    for (int j = 0; j < i; j++) {

      if (T[j] < T[j - 1]) {
        int aux = T[j];
        T[j] = T[j - 1];
        T[j - 1] = aux;
      }
    }
  }
}

#endif
