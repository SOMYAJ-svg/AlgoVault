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


#include "sorting.h"
#include "searching.h"
#include "graph.h"
#include "compare.h"
#include "notes.h"
using namespace std;

void showMenu() {
    cout << "\n=============================\n";
    cout << "       🚀 AlgoVault 🚀       \n";
    cout << "=============================\n";
    cout << "1. Sorting Algorithms\n";
    cout << "2. Searching Algorithms\n";
    cout << "3. Graph Algorithms\n";
    cout << "4. Compare Algorithms (Benchmark)\n";
    cout << "5. Notes\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int choice;
    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            return 0;
        }

        switch (choice) {
            case 1: sortingMenu(); break;
            case 2: searchingMenu(); break;
            case 3: graphMenu(); break;
            case 4: compareMenu(); break;
            case 5: notesMenu(); break;
            case 6: cout << "Goodbye 👋\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
