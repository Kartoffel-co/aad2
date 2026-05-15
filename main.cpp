#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

#include "brickSort.cpp"
#include "bubbleSort.cpp"

using namespace std;
using namespace chrono;

// Función para generar un vector de n elementos aleatorios sin números
// repetidos
vector<int> generarVectorAleatorio(int n, mt19937 &gen) {
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    vec[i] = i + 1; // Llena el vector con números del 1 al n
  }
  shuffle(vec.begin(), vec.end(), gen);
  // Mezcla los números aleatoriamente usando el algoritmo de
  // Fisher-Yates
  return vec;
}

int main() {
  ofstream archivo("resultados.csv");
  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo." << endl;
    return 1;
  }

  random_device rd;  // inicializa la semilla
  mt19937 gen(rd()); // generador de números aleatorio basado en el algoritmo
                     // Mersenne Twister 19937 con la semilla rd()

  archivo << "Tamano del Vector ; Tiempo Bubble (us) ; Tiempo Brick ; n^2"
          << endl;

  for (int n = 100; n <= 10000; n += 100) {
    std::vector<int> vectorAleatorio = generarVectorAleatorio(n, gen);

    auto inicioBubble = high_resolution_clock::now();
    bubbleSort(vectorAleatorio);
    auto finBubble = high_resolution_clock::now();

    auto inicioBrick = high_resolution_clock::now();
    bricksort(vectorAleatorio);
    auto finBrick = high_resolution_clock::now();

    double tiempoBubble =
        duration<double, micro>(finBubble - inicioBubble).count();

    double tiempoBrick =
        duration<double, micro>(finBrick - inicioBrick).count();

    int exp = n * n;

    archivo << n << ";" << tiempoBubble << ";" << tiempoBrick << ";" << exp
            << endl;

    cout << n << " ; " << tiempoBubble << ";" << tiempoBrick << ";" << exp
         << endl;
  }
  archivo.close();
}
