#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> &T, int rojo, int cyan) {
  for (int i = 0; i < T.size(); i++) {
    if (T[i] == rojo) {
      cout << "\033[31m";
      cout << T[i];
      cout << "\033[0m";
    } else if (T[i] == cyan) {
      cout << "\033[36m";
      cout << T[i];
      cout << "\033[0m";
    } else {
      cout << T[i];
    }
  }
}

void bricksort(vector<int> &T) {
  int n = T.size();
  for (int i = n - 1; i > 0; i--) {
    cout << endl;
    cout << "  i=" << i << endl;
    for (int j = 0; j < i; j++) {
      mostrar(T, T[j], T[j - 1]);
      cout << " j=" << j + 1 << endl;
      if (T[j] < T[j - 1]) {
        int aux = T[j];
        T[j] = T[j - 1];
        T[j - 1] = aux;
      }
    }
    mostrar(T, 0, 0);
    cout << endl;
  }
}

int main() {
  vector<int> T = {5, 4, 3, 2, 1};
  bricksort(T);
}
