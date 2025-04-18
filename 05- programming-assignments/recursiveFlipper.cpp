//
// Created by Austin Martin on 4/18/25.
//

#include <iostream>
#include <string>

using namespace std;

void flipper(int low, int high, int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int low = 0, high = 10;
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  flipper(low, high, arr, 10);

  cout << "Hello World!" << endl;

  return 0;
}