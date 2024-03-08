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
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  std::ofstream file;
  file.open("HeapSort.txt");
  int count = 0;

  for (int size = 50000; size <= 1000000; size += 50000) {
    double answer = 0;
    for (int i = 0; i < 30; i++) {

      int *arr = new int[size];
      int count = 1;
      for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
      }

      double start = wtime();
      heapSort(arr, size);
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
