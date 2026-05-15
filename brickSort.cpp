#ifndef BRICKSORT_CPP
#define BRICKSORT_CPP

#include <vector>

using namespace std;

void bricksort(vector<int> &T) {
  int n = T.size();
  for (int i = 0; i < n - 1; i++) {

    for (int j = n - 1; j > i; j--) {

      if (T[j] < T[j - 1]) {
        int aux = T[j];
        T[j] = T[j - 1];
        T[j - 1] = aux;
      }
    }
  }
}

#endif
