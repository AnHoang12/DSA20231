#include <iostream>
using namespace std;

int Binary_search(int A[],int n,int X)
{
    int F=0, L = n-1;
    while (F<=L) {
        int m = (F+L)/2;
        if (X==A[m])
            return m;   
        else if (X< A[m])
            L = m-1;
        else 
            F = m+1;
    }
    return -1;
}

int Binary_search_DQ(int A[],int F, int L,int X)
{
    int LOC,m;
    if (L>=F){
        m = (F+L)/2;
        if (X== A[m])
            LOC=m;
        else if (A[m]>X)
            LOC = Binary_search_DQ(A, F, m-1, X);
        else 
            LOC = Binary_search_DQ(A, m+1, L, X);
        return LOC;
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5};
    cout<< Binary_search_DQ(arr, 0, 4, 3) << "\n";
}
