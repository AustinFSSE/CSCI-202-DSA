//
// Created by Austin Martin on 4/18/25.
//

#include <iostream>
#include <string>


using namespace std;

void flipper(int low, int high, int *arr, int size) {
  low = arr[low];
  high = arr[high];
  int distance = (high - low ) / 2;
  for (int i = low - 1; i < distance; i++) {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = arr[low];
  }
}
void displayArray(int *arr) {
  for (int i = 0; i < arr.size; i++) {
    cout << arr[i] << endl;
  }
}

int main() {
  int low = 3, high = 7;
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  displayArray(arr);
  flipper(low, high, arr, 10);
  displayArray(arr);


  cout << "Hello World!" << endl;

  return 0;
}