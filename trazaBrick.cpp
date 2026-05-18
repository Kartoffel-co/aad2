#include <iostream>
#include <vector>

using namespace std;

void mostrar(vector<int> &T, int rojo, int cyan) {
  for (int i = 0; i < T.size(); i++) {
    if (i == rojo) {
      cout << "\033[31m";
      cout << T[i];
      cout << "\033[0m";
    } else if (i == cyan) {
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

  for (int i = 0; i < n - 1; i++) {
    cout << abs(i - 5) << endl;
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (T[j] < T[min]) {
        min = j;
      }
    }

    while (min > i) {
      mostrar(T, min, min - 1);
      cout << endl;

      swap(T[min], T[min - 1]);
      min--;
    }
    mostrar(T, -1, -1);
    cout << endl << endl;
  }
}

int main() {
  vector<int> T = {5, 4, 3, 2, 1};
  mostrar(T, -1, -1);
  cout << endl << endl;
  bricksort(T);
  mostrar(T, -1, -1);
}
