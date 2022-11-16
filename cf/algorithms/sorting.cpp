#include <bits/stdc++.h>
using namespace std;

// TC: O(N**2)
void bubbleSort(vector<int> &arr) {
    // move the biggest element to the right
    int n = arr.size();
    for (int k = 0; k < n - 1; k++) {
        for (int i = 0; i < n - k - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

// TC: O(N**2)
void selectionSort(vector<int> &arr) {
    // choose the minimum and put it to left
    int min_idx = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        min_idx = i;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < arr[min_idx]) min_idx = k;
        }

        swap(arr[i], arr[min_idx]);
    }
}

void mergeArray(vector<int> &arr, int l, int m, int r) {
    int p1 = l, p2 = m + 1, p3 = 0;
    vector<int> aux(r - l + 1, -1);
    while (p1 <= m && p2 <= r) {
        if (arr[p1] < arr[p2]) {
            aux[p3++] = arr[p1++];
        } else if (arr[p1] >= arr[p2]) {
            aux[p3++] = arr[p2++];
        }
    }

    while (p1 <= m) aux[p3++] = arr[p1++];
    while (p2 <= r) aux[p3++] = arr[p2++];

    p3 = 0;
    while (p3 < r - l + 1) {
        arr[l + p3] = aux[p3];
        p3++;
    }
}

void mergeSortHelper(vector<int> &arr, int l, int r) {
    if (r - l + 1 > 1) {
        int m = (l + r) >> 1;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        mergeArray(arr, l, m, r);
    }
}

// MergeSort
// TC: O(NlogN)
void mergeSort(vector<int> &arr) {
    int n = arr.size();
    mergeSortHelper(arr, 0, n - 1);
}

int partition(vector<int> &A, int l, int r) {
    // choose a pivot element
    int p = rand() % (r - l + 1) + l;
    swap(A[p], A[l]);

    // A[l] is our pivot element
    int i = p;
    for (int j = l; j <= r; j++) {
        if (A[j] < A[l]) {
            swap(A[j], A[i]);
            i++;
        }
    }

    // move the pivot to its place
    swap(A[l], A[i - 1]);
    return i - 1;
}

void quickSortHelper(vector<int> &arr, int l, int r) {
    if (r - l > 0) {
        int p = partition(arr, l, r);
        quickSortHelper(arr, l, p - 1);
        quickSortHelper(arr, p + 1, r);
    }
}

// quickSort
// TC: (NlogN) -> Avg, (N**2) -> Worst Case
void quickSort(vector<int> &arr) {
    int n = arr.size();
    quickSortHelper(arr, 0, n - 1);
}

// heapsort
// TC: O(NlogN)
// SC: O(1)
void heapify(vector<int> &arr, int i, int n) {
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
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}

void heapSort(vector<int> &arr) {
    // heapify the array
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }

    // extract an element from the heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {6, 2, 5, 3, 9, 2};
    // bubbleSort(arr);
    // selectionSort(arr);
    // mergeSort(arr);
    // quickSort(arr);
    heapSort(arr);
    for (auto el : arr) cout << el << " ";

    cout << endl;
}