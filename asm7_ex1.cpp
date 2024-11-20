#include <iostream>
using namespace std;

// Selection sort
void SelectionSort(int arr[], int n) {
    int i, j, min_index;
    for (i = 0; i < n - 1; ++i) {
        min_index = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[min_index]);
    }
}

// Insertion sort
void InsertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void BubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                swap(arr[i], arr[i+1]);
            }
        }
    }
}

// Quick sort
int Partition(int A[], int first, int last){
    if (first>=last) return 0;
    int c=A[first];
    int i=first+1,j=last;
    while (i<=j){
        while (A[i]<=c && i<=j) i++;
        while (A[j]>c && i<=j) j--;
        if (i<j) swap(A[i], A[j]);
    }
    swap(A[first], A[j]);
    return j;
}

void QuickSort(int A[], int first, int last){
    int j;
    if( first < last ) 
    {
        j = Partition( A, first, last);
        QuickSort(A, first, j-1);
        QuickSort(A, j+1, last);
    }
}

// Merge sort 
void MergeArrays(int A[],int first, int mid, int last) 
{
    int i= first,j= mid +1;
    while (i<j && j<=last){
        if (A[i]<=A[j]) i++;
        else {//chen Aj vao vi tri i
            int x=A[j];
            for (int k=j-1;k>=i;k--) 
                A[k+1]=A[k];
            A[i]=x;
            i++; j++;
        }
    }
}

void Merge(int A[], int first, int last){
    if (first>=last) return;
    int mid=(first+last)/2;
    Merge(A,first,mid);
    Merge(A,mid+1,last);
    MergeArrays(A,first,mid,last);
}

void MergeSort(int A[], int N){
    if (N<2) return;
    Merge(A,0,N-1);
}


// Heap sort 
void adjust(int A[], int i, int N)
{
    int max = i; // khoi tao max nhu la root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // Neu nut con trai lon hon so voi root
    if (l < N && A[l] > A[max])
        max = l;
    // Neu nut con phai lon hon so voi root
    if (r < N && A[r] > A[max])
        max = r;
    // Neu root khong phai la lon nhat
    if (max != i)
    {
        swap(A[i], A[max]);
        // De quy lai ham adjust
        adjust(A, max, N);
 }
}

void heap_sort(int A[], int N) {
 // Tao dong ban dau
for (int i = N / 2 - 1; i >= 0; i--)
    adjust(A, i, N);
 // Trích xuất từng phần tử một từ heap
for (int i = N - 1; i >= 0; i--)
{
 // Di chuyen root ve cuoi cung
    swap(A[0], A[i]);
 // vun lại đống cho cây con gồm i phần tử
    adjust(A, 0, i);
}
}


int main(){
    int array[] = {1,4,3,5,2};
    QuickSort(array,0 ,4);
    for(int i =0; i<5; i++) cout << array[i] << "\n";
}