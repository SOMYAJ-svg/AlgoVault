#include "searching.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;
using ms = chrono::duration<double, milli>;

void searchingMenu() {
    int n;
    cout << "\n-- Searching Module --\n";
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (sorted for binary search recommended): ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "\nEnter value to search: ";
    int target; cin >> target;

    cout << "Choose:\n1. Linear Search\n2. Binary Search\nChoice: ";
    int choice; cin >> choice;

    auto start = chrono::high_resolution_clock::now();
    int idx = -1;

    if (choice == 1) idx = linearSearch(arr, target);
    else if (choice == 2) idx = binarySearch(arr, target);
    else {
        cout << "Invalid choice\n";
        return;
    }

    auto end = chrono::high_resolution_clock::now();
    ms duration = end - start;

    if (idx != -1) cout << "Found at index (0-based): " << idx << "\n";
    else cout << "Not found\n";

    cout << "Time taken: " << duration.count() << " ms\n";
}

int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i)
        if (arr[i] == target) return (int)i;
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int l = 0, r = (int)arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
