#include <iostream>
#include "insertionUtil.h"

using namespace std;

int main() {
  srand(time(0));
  //---
  int n=10;
  int* v = new int[n];
  //----------------------------
  for (int i = 0; i < 10; ++i) {
    v[i]=(rand() % 100);
    cout << " " << v[i];
  }
  //---------------------------
  cout << endl;
  insertionSort(v,n);
  //v=insertionSort(v,n);
  print(v,n);
  return 0;
}