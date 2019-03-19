#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void quicksort(int arr [], int lefft, int right);
int partition(int arr [], int left, int right);
void swap(int arr [], int i, int j);

void quicksort(int arr [], int left, int right) {
    int index = partition(arr, left, right);
    if (left < index - 1 ) {
        quicksort(arr, left, index - 1 );
    }
    if (index < right) {
        quicksort(arr, index, right);
    }
}

int partition(int arr [], int left, int right) {
    // find the pivot; 
    int mid = (left + right) / 2;
    int pivot = arr[mid];
    while (left <= right) {
        // Find the element on the left that should be on the right
        while(arr[left] < pivot)  {
            left++;
        }
        //Find the element on the right that should be on the left;
        while(arr[right] > pivot) {
            right--;
        } 

        // swap the value
        if (left <= right) {
            swap(arr, left, right);
            right--;
            left++;  
        }
    }
    return left;
}

void swap(int arr [], int i, int j) {
    if (i != j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void pprint(int arr[] , int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " | ";
    }
    cout << endl;
}

void testQuickSort() {
    const int n = 10 ;
    int arr1 [n] = {9,8,7,6,5,4,3,2,1,0 };
    int arr2 [n] = {1,0,7,6,5,5,5,9,1,0 };
    int arr3[5] = {4,4,4,4,4};
    quicksort(arr1, 0, n-1);
    pprint(arr1, n);

    quicksort(arr3, 0, 4);
    pprint(arr3, 5);

    quicksort(arr2, 0, n-1);
    pprint(arr2, n);

}

int main() {
  testQuickSort();
}
