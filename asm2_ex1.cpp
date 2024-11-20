#include <iostream>
using namespace std;
#define SIZE 5

struct CircularQueue
{
    int front, rear;
    int arr[SIZE];
};

void Initialize(CircularQueue &Q){
    Q.front = Q.rear = -1;
}

int isFull(CircularQueue Q) {
  if ((Q.front == Q.rear + 1) || (Q.front == 0 && Q.rear == SIZE - 1)) return 1;
  return 0;
}

int isEmpty(CircularQueue Q) {
  if (Q.front == -1) return 1;
  return 0;
}

void enQueue(CircularQueue &Q, int element) {
  if (isFull(Q))
    cout <<"\n Queue is full";
  else {
    if (Q.front == -1) Q.front = 0;
    Q.rear = (Q.rear + 1) % SIZE;
    Q.arr[Q.rear] = element;
    cout << "\n Inserted-> " << element;
  }
} 

int deQueue(CircularQueue &Q) {
  int element;
  if (isEmpty(Q)) {
   cout << "\n Queue is empty";
    return (-1);
  } else {
    element = Q.arr[Q.front];
    if (Q.front == Q.rear) {
      Q.front = -1;
      Q.rear = -1;
    } 
    else {
      Q.front = (Q.front + 1) % SIZE;
    }
    cout << "\n Deleted element: " << element;
    return (element);
  }
}
void display(CircularQueue &Q) {
  int i;
  if (isEmpty(Q))
    cout << "\nEmpty Queue\n";
  else {
    cout <<"\n Front: " << Q.front;
    cout <<"\n Queue: ";
    for (i = Q.front; i != Q.rear; i = (i + 1) % SIZE) {
      cout << Q.arr[i];
    }
    cout << Q.arr[i];
    cout <<"\n Rear: " << Q.rear;
  }
}
int main(){
  CircularQueue Q;
  Initialize(Q);
  enQueue(Q,1);
  enQueue(Q,2);
  enQueue(Q,3);
  enQueue(Q,4);
  enQueue(Q,5);
  display(Q);
  deQueue(Q);
  display(Q);
  return 0;
}
