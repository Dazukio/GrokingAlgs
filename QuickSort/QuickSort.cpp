#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int part(vector<int>& vec, int low, int high);
void quickSort(vector<int>& vec, int low, int high);
void displayVector(const vector<int>& vec);
int main()
{
    vector<int> myArr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(myArr, 0, myArr.size() - 1);
    displayVector(myArr);
    return 0;
}

int part(vector<int>& vec, int low, int high) {
    int randInxed = rand() % (high - low) + low;
    

    swap(vec[randInxed], vec[high]);
    int pv = vec[high];

    int swapMarker = low - 1;

    for (int i = low; i <= high; i++) {
        if (vec[i] <= pv) {
            swapMarker++;
            if (i > swapMarker) {
                swap(vec[i], vec[swapMarker]);
            }
        }
    }
    return swapMarker;
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int partition = part(vec, low, high);

        quickSort(vec, low, partition - 1);
        quickSort(vec, partition + 1, high);
        }
}

void displayVector(const vector<int>& vec) {
    for (int elem : vec) {
        cout << elem << ' ';
    }
    cout << '\n';
}