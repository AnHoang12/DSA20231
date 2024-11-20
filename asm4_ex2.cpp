#include <iostream>
using namespace std;

int findMin1(int arr[], int size) {
    if (size == 1) {
        return arr[0];      
    }
    int min = findMin1(arr + 1, size - 1);
    return (arr[0] < min) ? arr[0] : min;
}

int findMin2(int arr[], int size){
    int min = arr[0];
    for (int i = 0; i < size; i++){
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 7, 10, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int minVal = findMin1(arr, size);
    cout << "Giá trị nhỏ nhất trong mảng là: " << minVal << endl;

    return 0;
}
