//
// Created by Austin Martin on 4/18/25.
//

#include <iostream>
#include <string>


using namespace std;

int main() {
  int low = 3, high = 7;
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  low = arr[low];
  high = arr[high];
  int distance = (high - low ) / 2;
  for (int i = low - 1; i < distance; i++) {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = arr[low];
  }
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}