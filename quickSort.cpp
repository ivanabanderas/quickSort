#include <iostream>
#include <vector>

using namespace std;

void mySwap(int& a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

int pivote(vector<int>& array, int left, int right) {
    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (array[j] <= pivot) {
            i++;
            mySwap(array[i], array[j]);
        }
    }

    mySwap(array[i + 1], array[right]);
    return i + 1;
}


void quickSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int pivotIndex = pivote(array, left, right);
        quickSort(array, left, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, right);
    }
}

int main() {
    vector<int> array = {2, 18, 33, 3, 10};

    quickSort(array, 0, array.size() - 1);

    for (int num:array){
        cout << num << ",";
    }

    return 0;
}
