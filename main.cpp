#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

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

  archivo << "Tamano del Vector ; Tiempo (us)" << endl;

  for (int n = 100; n <= 10000; n += 100) {
    std::vector<int> vectorAleatorio = generarVectorAleatorio(n, gen);

    auto inicio = high_resolution_clock::now();
    bubbleSort(vectorAleatorio);
    auto fin = high_resolution_clock::now();

    double tiempo = duration<double, micro>(fin - inicio).count();
    archivo << n << ";" << tiempo << endl;
    cout << n << " ; " << tiempo << endl;
  }
  archivo.close();
}
