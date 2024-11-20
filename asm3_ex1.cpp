//Nguyen Hoang An 20210011

#include <iostream>
using namespace std;

struct Node{
    int info;
    Node* next;
};
typedef Node* PNode;
typedef Node* LinkedList;

void InitList(LinkedList &H){
    H = NULL;
}

bool IsEmpty(LinkedList H){
    return(H==NULL);
}

PNode createNode(int k){
    PNode Q = new Node;
    Q->info = k;
    Q->next = NULL;
    return Q;
}

void InsertBegin(LinkedList &H, int k){
    PNode Q = new Node;
    Q->info = k;
    if(IsEmpty(H)){
        Q->next = NULL;
        H = Q;
    }

    else{
        Q->next = H;
        H = Q;
    }
}

PNode InsertAfter(LinkedList &H, PNode P, int k){
    PNode Q = new Node;
    Q->info = k;
    if(IsEmpty(H)){
        Q->next = NULL;
        H = Q;
    }
    else {
        if(P == NULL) return NULL;
        Q->next = P->next;
        P->next = Q;
    }
}

PNode InsertBefore(LinkedList &H, PNode P, int k){
    PNode Q = new Node;
    Q->info = k;
    if(IsEmpty(H)){
        H = Q;
        Q->next = NULL;
        return Q;
    }
    else{
        if(P == NULL) return NULL;
        Q->info = P->info;
        P->info = k;
        Q->next = P->next;
        P->next = Q;
    }
    return P;
}

PNode SearchNode(LinkedList &H, int k){
    PNode P = H;
    while(P != NULL){
        if(P->info == k) return P;
        else P = P->next;
    }
    return 0;
}

void DeleteFirstNode(LinkedList &H){
    if(IsEmpty(H)) cout << "Empty";
    else{
        PNode P = H;
        H = H->next;
        delete P;
    }
}

void DeleteNode(LinkedList &H, PNode P){
    if(IsEmpty(H)) cout << "Empty";
    if(H == P && P->next == NULL){
        H = NULL;
        delete P;
    }
    else {
        if(H == P){
            H = P->next;
            delete P;
        }
        else {
            PNode Q = H;
            while( Q->next != P) Q = Q->next;
            Q->next = P->next;
            delete P;
        }
    }
}

int CountK(LinkedList &H, int k){
    PNode P = H;
    int count = 0;
    while ((P!=NULL))
    {
        if(P->info == k){
            count++;
        }
        P = P->next;
    }
    return count;
}

void Delete_allK(LinkedList &H, int k){
    PNode current = H;
    PNode prev = NULL;
    while (current != NULL)
    {
        if (current->info == k){
            if(prev == NULL){
                H = current->next;
            }
            else {
                prev->next = current->next;
            }
            PNode P = current; 
            current = (prev == NULL)? H : prev->next;
            delete P;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
}

void print(LinkedList H){
    PNode P; 
    P = H;
    cout << "Danh sach: ";
    while (P!=NULL){
        cout << P->info << " ";
        P = P->next;
    }
}


int main(){
    LinkedList H;
    InitList(H);
    InsertBegin(H,1);
    InsertBegin(H,2);
    InsertAfter(H, SearchNode(H,2),3);
    InsertBegin(H,1);
    print(H);
    Delete_allK(H,1);
    print(H);
    return 0;
}