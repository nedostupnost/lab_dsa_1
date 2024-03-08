#include <cstdint>
#include <fstream>
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

void countingSort(uint32_t arr[], int n) {
  uint32_t max = arr[0];

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  uint32_t *count = new uint32_t[max + 1]();

  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }

  uint32_t index = 0;
  for (int i = 0; i <= max; i++) {
    while (count[i] > 0) {
      arr[index++] = i;
      count[i]--;
    }
  }

  delete[] count;
}

int main() {
  std::ofstream file;
  file.open("CountingSort.txt");

  int count = 0;

  for (int size = 50000; size <= 1000000; size += 50000) {
    double answer = 0;
    for (int i = 0; i < 30; i++) {

      uint32_t *arr = new uint32_t[size];

      for (int i = 0; i < size; i++) {
        arr[i] = getrand(0, 100000);
      }

      double start = wtime();
      countingSort(arr, size);
      double end = wtime();

      answer += end - start;

      delete[] arr;
    }
    count++;
    file << count << ". Размер массива: " << size
         << "\nВремя выполения: " << (answer / 30) << " c\n\n"
         << std::endl;
  }

  return 0;
}