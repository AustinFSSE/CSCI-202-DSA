//
// Created by Austin Martin on 4/18/25.
//

#include <iostream>
#include <string>


using namespace std;

int main() {
  int low = 3, high = 7;
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int start = low - 1;
  int end = high - 1;

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
  cout << endl;

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}