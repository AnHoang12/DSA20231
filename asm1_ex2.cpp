#include <iostream>
using namespace std;

#define MAX 100

struct Queue{
    int info[MAX];
    int front, rear;
};

void Initialize (Queue& Q){
    Q.front = 0;
    Q.rear = -1;
}

int IsEmpty(Queue Q){
    if(Q.front > Q.rear){
        return 1;
    }
    return 0;
}

int IsFull(Queue Q){
    if(Q.rear == -1){
        return 1;
    }
    return 0;
}

void enQueue(Queue &Q, int k){
    if(IsFull(Q)){
        cout << "\nQueue is Full";
    }
    else {
        Q.rear++;
        Q.info[Q.rear] = k;
        cout << "Inserted: " << k;
    }
}

int deQueue(Queue &Q){
    int k;
    if(IsEmpty(Q)){
        cout << "\nQueue is Empty";
        return -1;
    }
    else {
        k = Q.info[Q.front];
        Q.front++;
        cout << "\nDelete item: " << k;
        return k;
    }
}

void print(Queue Q){
    if(IsEmpty(Q)) cout << "\nQueue is empty";
    else {
        cout <<"\nQueue: ";
        for (int i = Q.front; i <= Q.rear; i++){
        cout  << Q.info[i];
        }
    }
}

int main(){
    Queue Q;
    Initialize(Q);
    enQueue(Q, 1);
    enQueue(Q, 2);
    print(Q);
}