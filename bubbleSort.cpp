#ifndef BUBBLESORT_CPP
#define BUBBLESORT_CPP

#include <vector>

using namespace std;

void bubbleSort(vector<int> &T) {
  for (int i = T.size() - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (T[j] > T[j + 1]) {
        int aux = T[j];
        T[j] = T[j + 1];
        T[j + 1] = aux;
      }
    }
  }
}

#endif
