#include <iostream>
#include <string>
using namespace std;

// CSC249
// M3T1
// Joshua Eckman
// 2/14/23

void SelectionSort (int* numbers, int numbersSize) {
  for (int i = 0; i < numbersSize - 1; i++) {
    int indexSmallest = i;
    for (int j = i + 1; j < numbersSize; j++) {
       if (numbers[j] < numbers[indexSmallest]) {
          indexSmallest = j;
       }
    }
    int temp = numbers[i];
    numbers[i] = numbers[indexSmallest];
    numbers[indexSmallest] = temp;
  }
}

string ArrayToString(int* array, int arraySize) {
   if (0 == arraySize) {
      return string("[]");
   }

   string result = "[" + to_string(array[0]);

   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   result += "]";
   return result;
}

int main() {
  cout << "Enter eight numbers:" << endl;
  int numbers[8];
  for (int i = 0; i < 8; i++) {
    cout << "Element " << i + 1 << ": ";
    cin >> numbers[i];
  }
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

  cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

  SelectionSort(numbers, numbersSize);

  cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}