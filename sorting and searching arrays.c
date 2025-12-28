#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void swapVal(int *num1, int *num2);
void generateArray(int arr[], int arraySize, int range);
void printArray(int arr[], int arraySize);
int getInput(int range);
void sequentialSearch(int arr[], int arraySize, int key);
void bubbleSort(int arr[], int arraySize);
int binarySearch(int arr[], int min, int max, int key);
void selectionSort(int arr[], int arraySize);
void quickSort(int arr[], int min,  int max);
int partition(int arr[], int i, int k);


int main(void) {

  // Create array Conditions.

  srand((int)time(NULL));
  int arraySize = 10;
  int exArray[arraySize];
  int searchKey;
  int range = 10;


  //                Generate and print unsorted array.


  generateArray(exArray, arraySize, range);
  printArray(exArray, arraySize);
  printf("\n\n");


  //                Sorting Functions


  //bubbleSort(exArray, arraySize);

  //selectionSort(exArray, arraySize);

  quickSort(exArray, 0, arraySize - 1);


  //                Print sorted array.


  printArray(exArray, arraySize);


  //                Get search key and input to searching algorithm of choice.


  searchKey = getInput(range);

  //searchKey = sequentialSearch(exArray, arraySize, searchKey);

  searchKey = binarySearch(exArray, 0, arraySize - 1, searchKey);

  printf("Item is at index: %d.\n", searchKey + 1);


  return 0;
}

void swapVal(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
  return;
}


void generateArray(int arr[], int arraySize, int range) {
  for (int i = 0 ; i < arraySize ; i++) {
    arr[i] = (rand() % range) + 1;
  }
  return;
}

void printArray(int arr[], int arraySize) {
  for (int i = 0 ; i < arraySize ; i++) {
    printf("%5d", arr[i]);
    if ((i+1) % 20 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  return;
}

int getInput(int range) {
  int input;
  printf("Enter search term between 1 and %d.\n", range);
  scanf("%d", &input);
  printf("\n");
  return input;
}

void sequentialSearch(int arr[], int arraySize, int key) {
  for (int i = 0 ; i < arraySize ; i++) {
    if (arr[i] == key) {
      printf("Key is at index: %d\n", i);
    }
  }
  return;
}

void bubbleSort(int arr[], int arraySize) {
  bool swap;
  do {
    swap = false;
    for (int i = 1 ; i < arraySize ; i++) {
      if (arr[i-1] > arr[i]) {
        swapVal(&arr[i-1], &arr[i]);
        swap = true;
      } 
    }
  } while(swap);
  return;
}

int binarySearch(int arr[], int min, int max, int key) {
  //returns key index.

  int mid;

  while (max >= min) {
    mid = (max + min) / 2;

    if (arr[mid] < key) {
      min = mid + 1;
    }
    else if (arr[mid] > key) {
      max = mid - 1;
    }
    else {
      return mid;
    }
  }
  return -1; //Not found
}

void selectionSort(int arr[], int arraySize) {

  int indexSmallest;

  for (int i = 0 ; i < arraySize ; i++) {
    indexSmallest = i;
    for (int j = i + 1 ; j < arraySize ; j++) {
      if (arr[j] < arr[indexSmallest]) {
        indexSmallest = j;
      }
    }
    swapVal(&arr[i], &arr[indexSmallest]);
  }

  return;
}

void quickSort(int arr[], int min,  int max) {

  int j;
   
  /* Base case: If there are 1 or zero elements to sort,
  partition is already sorted */
  if (min >= max) {
    return;
  }
   
  /* Partition the data within the array. Value j returned
  from partitioning is location of last element in low partition. */
  j = partition(arr, min, max);
   
  /* Recursively sort low partition (i to j) and
  high partition (j + 1 to k) */
  quickSort(arr, min, j);
  quickSort(arr, j + 1, max);

}

int partition(int arr[], int min, int max) {
  int l;
  int h;
  int midpoint;
  int pivot;
  bool done;
   
  /* Pick middle element as pivot */
  midpoint = (max + min) / 2;
  pivot = arr[midpoint];
   
  done = false;
  l = min;
  h = max;
   
  while (!done) {
      
    /* Increment l while numbers[l] < pivot */
    while (arr[l] < pivot) {
      ++l;
    }
      
    /* Decrement h while pivot < numbers[h] */
    while (pivot < arr[h]) {
      --h;
    }
      
    /* If there are zero or one elements remaining,
    all numbers are partitioned. Return h */
    if (l >= h) {
      done = true;
    }
    else {
      //Swap numbers[l] and numbers[h], update l and h

      swapVal(&arr[l], &arr[h]);
         
      ++l;
      --h;
      }
   }
   return h;
}
