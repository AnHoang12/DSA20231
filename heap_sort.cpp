#include <iostream>
using namespace std;
void adjust(int A[], int i, int N){
    int max = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<N && A[l]>A[max]){
        max = l;
    }
    if (r<N && A[r]>A[max]){
        max = r;
    }
    if(max != i){
        swap(A[i], A[max]);
        adjust(A, max, N);
    }
}

void heap_sort(int A[], int N){
    for (int i = N/2-1;i>=0;i--)
        adjust(A, i, N);
    for (int i = N - 1; i>= 0; i --){
        swap(A[0], A[i]);
        adjust(A, 0, i);
    }
}
int main(){
    int A[] = {5,3,4,2,1};
    heap_sort(A,5);
    for (int i =0;i<5; i++) cout<< A[i];
}