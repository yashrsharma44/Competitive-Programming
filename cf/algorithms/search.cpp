#include <bits/stdc++.h>
using namespace std;

// Simple linear search
// TC: O(N)
bool linearSearch(vector<int> arr, int val) {
    for (int el : arr) {
        if (val == el) return true;
    }
    return false;
}

// Should be sorted
// Binary Search
// TC: O(logN)
bool binarySearch(vector<int> arr, int val) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (arr[m] > val) {
            r = m - 1;
        } else if (arr[m] < val) {
            l = m + 1;
        } else {
            return true;
        }
    }

    return false;
}

// First True
bool getFirstTrue(vector<int> arr, int val) {
    int l = 0, r = arr.size();
    while (l < r) {
        int m = (l + r) >> 1;
        if (!(arr[m] >= val))
            l = m + 1;
        else
            r = m;
    }

    return l;
}

// Last True
bool getLastTrue(vector<int> arr, int val) {
    int l = -1, r = arr.size();
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (arr[m] >= val)
            l = m;
        else
            r = m;
    }

    return l;
}