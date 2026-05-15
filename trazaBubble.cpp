#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> &T) {
  for (int i = 0; i < T.size(); i++) {
    cout << T[i];
  }
}

void bubbleSort(vector<int> &T) {
  for (int i = T.size() - 1; i > 0; i--) {
    cout << endl;
    cout << " i=" << i << endl;
    for (int j = 0; j < i; j++) {
      mostrar(T);
      cout << " j=" << j + 1 << endl;
      if (T[j] > T[j + 1]) {
        int aux = T[j];
        T[j] = T[j + 1];
        T[j + 1] = aux;
      }
    }
  }
  cout << endl;
  mostrar(T);
}

int main() {
  vector<int> T = {5, 4, 3, 2, 1};
  bubbleSort(T);
}
