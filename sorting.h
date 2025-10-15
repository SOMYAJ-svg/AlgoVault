#ifndef SORTING_H
#define SORTING_H

#include <vector>

void sortingMenu();
void bubbleSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr, int l, int r);
void quickSort(std::vector<int>& arr, int l, int r);

#endif // SORTING_H
