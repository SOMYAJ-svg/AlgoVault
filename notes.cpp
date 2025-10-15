#include "notes.h"
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

const string NOTES_FILE = "data/notes.txt";

void appendNote(const string &note) {
    ofstream fout(NOTES_FILE, ios::app);
    if (!fout) {
        cout << "Error: Unable to open notes file for writing\n";
        return;
    }
    // Add timestamp
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    fout << std::ctime(&now) << note << "\n----\n";
    fout.close();
    cout << "Note saved.\n";
}

void viewNotes() {
    ifstream fin(NOTES_FILE);
    if (!fin) {
        cout << "No notes yet. Add one!\n";
        return;
    }
    cout << "\n-- Your Notes --\n";
    string line;
    while (getline(fin, line)) {
        cout << line << "\n";
    }
    fin.close();
}

void notesMenu() {
    cout << "\n-- Notes Module --\n";
    cout << "1. Add note\n2. View notes\nChoice: ";
    int choice; cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (choice == 1) {
        cout << "Enter note (single line). Press enter to save:\n";
        string note;
        getline(cin, note);
        appendNote(note);
    } else if (choice == 2) {
        viewNotes();
    } else {
        cout << "Invalid choice\n";
    }
}
