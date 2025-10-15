#include "compare.h"
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
#include <random>
#include <chrono>
using namespace std;
using ms = chrono::duration<double, milli>;

// Helper to copy a vector and time a function that modifies it
template<typename Func>
double timeFunction(vector<int> arr, Func f) {
    auto start = chrono::high_resolution_clock::now();
    f(arr);
    auto end = chrono::high_resolution_clock::now();
    ms duration = end - start;
    return duration.count();
}

// wrappers to adapt our sorting functions which take vector<int>&
static void bubbleWrap(vector<int>& a) { bubbleSort(a); }
static void selectionWrap(vector<int>& a) { selectionSort(a); }
static void insertionWrap(vector<int>& a) { insertionSort(a); }
static void mergeWrap(vector<int>& a) { if(!a.empty()) mergeSort(a, 0, (int)a.size()-1); }
static void quickWrap(vector<int>& a) { if(!a.empty()) quickSort(a, 0, (int)a.size()-1); }

void compareMenu() {
    cout << "\n-- Compare / Benchmark Module --\n";
    int n;
    cout << "Enter size of random array to generate (e.g., 1000): ";
    cin >> n;
    vector<int> base(n);
    mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; ++i) base[i] = rng() % 100000;

    cout << "Running benchmarks... (this may take a moment)\n";

    // we measure by copying the base array each time and running
    vector<pair<string,double>> results;
    {
        auto arr = base;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(arr);
        auto end = chrono::high_resolution_clock::now();
        ms duration = end - start;
        results.push_back({"Bubble Sort", duration.count()});
    }
    {
        auto arr = base;
        auto start = chrono::high_resolution_clock::now();
        selectionSort(arr);
        auto end = chrono::high_resolution_clock::now();
        ms duration = end - start;
        results.push_back({"Selection Sort", duration.count()});
    }
    {
        auto arr = base;
        auto start = chrono::high_resolution_clock::now();
        insertionSort(arr);
        auto end = chrono::high_resolution_clock::now();
        ms duration = end - start;
        results.push_back({"Insertion Sort", duration.count()});
    }
    {
        auto arr = base;
        auto start = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, (int)arr.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        ms duration = end - start;
        results.push_back({"Merge Sort", duration.count()});
    }
    {
        auto arr = base;
        auto start = chrono::high_resolution_clock::now();
        quickSort(arr, 0, (int)arr.size() - 1);
        auto end = chrono::high_resolution_clock::now();
        ms duration = end - start;
        results.push_back({"Quick Sort", duration.count()});
    }

    cout << "\nBenchmark results (milliseconds):\n";
    for (auto &p : results) {
        cout << p.first << ": " << p.second << " ms\n";
    }
}
