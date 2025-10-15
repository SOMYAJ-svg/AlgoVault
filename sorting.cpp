#include "sorting.h"
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
using ms = std::chrono::duration<double, std::milli>;

// Linear Search
int linearSearch(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Binary Search
int binarySearch(vector<int>& arr, int key) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}


svoid searchingMenu() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (true) {
        cout << "\n--- Searching Menu ---\n";
        cout << "1. Linear Search\n2. Binary Search\n3. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 3) break;

        // flush leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int key;
        cout << "Enter key to search: ";
        cin >> key;

        int idx = -1;
        if (choice == 1) {
            idx = linearSearch(arr, key);
        }
        else if (choice == 2) {
            // Binary search requires sorted array
            sort(arr.begin(), arr.end());
            idx = binarySearch(arr, key);
        }
        else {
            cout << "❌ Invalid choice! Try again.\n";
            continue;
        }

        if (idx != -1) cout << "✅ Element found at index " << idx << endl;
        else cout << "❌ Element not found." << endl;
    }
}