#include <iostream>
using namespace std;
const int MAX = 10000;
typedef struct {
    int info[MAX];
    unsigned int n; 
} Stack;

void Initialize (Stack& S){
    S.n=0;
}
bool IsEmpty (Stack S){
    return (S.n==0);
}
bool IsFull (Stack S){
    return (S.n==MAX);
}
void Push (int K, Stack &S){

    if(IsFull(S)){
        return;
    }
    S.info[S.n] = K;
    S.n++;
}
int Pop(Stack &S){
    if(IsEmpty(S)){
        return -1;
    }
    S.n--;
    return S.info[S.n];
}
int Top(Stack S){
    if(IsEmpty(S)) {
        return -1;
    }
    return S.info[S.n-1];
}

void print(Stack S){
    int i = 0;
    while (i < S.n)
        cout << S.info[i++] << " ";
    cout << endl;
}
void Change(int N, Stack& S){
    int m=N;
    int R,X;
    do{
        R = m % 2;
        Push(R, S);
        m = m/2;
    }
    while(m != 0);
    while(!IsEmpty(S)){
        X = Pop(S);
        cout << X;
    }
    cout << endl;
}
int main (){

    
    Stack S;
    Initialize(S);
   
    Change (125, S);
    
    return 0;
}