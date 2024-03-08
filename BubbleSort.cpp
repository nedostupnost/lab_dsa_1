#include <cstdlib>
#include <iostream>
#include <sys/time.h>

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void bubbleSort(uint32_t arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  const int size = 1000000;
  uint32_t *arr = new uint32_t[size];

  for (int i = 0; i < size; i++) {
    arr[i] = getrand(0, 100000);
  }
  double start_time = wtime();
  bubbleSort(arr, size);
  double end_time = wtime();

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  delete[] arr;

  std::cout << "\n\n" << end_time - start_time << " с\n\n" << std::endl;

  return 0;
}