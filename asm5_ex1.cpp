#include <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode *prev, *next;
};
typedef DNode *PDNode;

struct DList
{
    DNode *head;
    DNode *tail;
};


PDNode createNode(int k){
    PDNode Q = new DNode;
    Q->info = k;
    Q->prev = NULL;
    Q->next = NULL;
    return Q;
}

void createsList(DList &l){
	l.head = NULL;
	l.tail = NULL;
}

void insertBegin(DList &l, int k){
    PDNode Q = new DNode;
    Q = createNode(k);
    if(l.head==NULL){
		l.head = Q;
		l.tail = l.head;
	}
    else{
		Q->next = l.head;
		l.head->prev = Q;
		l.head = Q;
	}
}

void insertTail(DList &l, int k){
	PDNode Q = new DNode;
    Q = createNode(k);
	if (l.head==NULL){
		l.head = Q;
		l.tail = l.head;
	}
    else{
		Q->prev = l.tail;
		l.tail->next = Q;
		l.tail = Q;
	}
}

PDNode findNode(DList &l, int k) {
    while (l.head != NULL) {
        if (l.head->info == k) {
            return l.head; 
        }
        l.head = l.head->next;
    }   
    return NULL; 
}

void printList(DList &list) {
    PDNode Q = list.head;
    cout << "List: ";
    while (Q != NULL) {
        cout << Q->info << " ";
        Q = Q->next;
    }
    cout << endl;
} 

void insertAfter(PDNode P, int k){
    if (P == NULL) {
        cout << "the given previous node cannot be NULL";
        return;
    }
    PDNode Q = new DNode;
    Q = createNode(k);
    Q->next = P->next;
    P->next = Q;
    Q->prev = P;
    if (Q->next != NULL) 
        Q->next->prev = Q; 
}

void insertBefore(DList &l,PDNode P, int k){
    if (P == NULL) {
        cout << "the given next node cannot be NULL";
        return;
    }
    PDNode Q = new DNode;
    Q = createNode(k);
    Q->prev = P->prev;
    P->prev = Q;
    Q->next = P;
    if (Q->prev != NULL) Q->prev->next = Q;
    else
        l.head = Q;
}

void DeleteFirstNode(DList &l){
    if(l.head == NULL && l.tail == NULL) {
        cout << "Empty";
        return;
    }
    else{
        PDNode P = l.head;
        l.head = l.head->next;
        delete P;
    }
}

void deleteNode(DList &list, int k) {
    PDNode Q = list.head;
    while (Q != NULL && Q->info != k) {
        Q = Q->next;
    }

    if (Q == NULL) {
        cout << "Not found node = " << k  << endl;
        return;
    }

    if (Q == list.head) {
        list.head = Q->next;
        if (list.head != NULL) {
            list.head->prev = NULL;
        }
        if (Q == list.tail) {
            list.tail = NULL; 
        }
    } else if (Q == list.tail) {
        list.tail = Q->prev;
        if (list.tail != NULL) {
            list.tail->next = NULL;
        }
    } else {
        Q->prev->next = Q->next;
        Q->next->prev = Q->prev;
    }

    delete Q;
    cout << "Deleted node = " << k  << endl;
}

void DeleteEndNode(DList &list){
    if(list.head == NULL) {
        cout << "Empty." << endl;
        return;
    }

    PDNode Q = list.tail;

    if (Q == list.head) {
        delete Q;
        list.head = list.tail = NULL;
        cout << "Deleted end node." << endl;
        return;
    }

    list.tail = list.tail->prev;
    list.tail->next = NULL;
    delete Q;
    cout << "Deleted end node" << endl;
}


int main(){
    DList list;
    createsList(list);
    insertBegin(list,1);
    insertAfter(findNode(list,1),2);
    insertBefore(list,findNode(list,1),3);
    printList(list);
    //DeleteFirstNode(list);
    //deleteNode(list,1);
    DeleteEndNode(list); 
    printList(list);
}
