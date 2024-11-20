#include <iostream>
using namespace std;

struct student{
    int id;
    char name[50];
    char class_id[10];
    float gpa;
};

struct Node{
    student info;
    Node* next;
};

void InitList(Node* &H){
    H = NULL;
}

bool IsEmpty(Node* H){
    return(H==NULL);
}

void InsertBegin(Node* &H, student s){
    Node* Q = new Node;
    Q->info = s;
    Q->next = NULL;
    if (IsEmpty){
        H = Q;
    }
    else {
        Q->next = H;
        H = Q;
    }
}

void InsertAfter(Node* &H, Node* P, student s){
    Node* Q = new Node;
    Q->info = s;
    Q->next = NULL;
    if(IsEmpty(H)){
        H = Q;
    }
    else {
        if(P == NULL) return;
        else{
        Q->next = P->next;
        P->next = Q;
        }
    }
}

Node* InsertBefore(Node* &H, Node* P, student s){
    Node* Q = new Node;
    Q->info = s;
    Q->next = NULL;
    if(IsEmpty(H)){
        H = Q;
        return Q;
    }
    else{
        if(P == NULL) return NULL;
        Q->info = P->info;
        P->info = s;
        Q->next = P->next;
        P->next = Q;
    }
    return P;
}

Node* SearchNode(Node* &H, student s){
    Node* P = H;
    while(P != NULL){
        if(P->info.id == s.id) return P;
        else P = P->next;
    }
    return 0;
}

void DeleteFirstNode(Node* &H){
    if(IsEmpty(H)) cout << "Empty";
    else{
        Node* P = H;
        H = H->next;
        delete P;
    }
}

void DeleteNode(Node* &H, Node* P){
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
            Node* Q = H;
            while( Q->next != P) Q = Q->next;
            Q->next = P->next;
            delete P;
        }
    }
}

float GPA(Node* H){
    Node* P;
    P = H;
    int count = 0;
    int gpa = 0;
    while (P != NULL)
    {
        gpa += H->info.gpa;
        count ++;
        P = P->next;
    }
    float GPA = gpa/count;
    return GPA;
}

void print(Node* H){
    Node* P;
    P = H;
    cout << "\nDanh sach: ";
    while (P != NULL)
    {
        cout << "\nID:" << H->info.id << " Name:"<< H->info.name << " Class:"<< H->info.class_id << " GPA:" << H->info.gpa;
        P = P->next;
    }
}

struct HashTable {
    int size;
    Node** table;
};

int hashFunction(int id){
    return id%1000;
}

void InitTable(HashTable& hashTable, int tableSize) {
    hashTable.size = tableSize;
    hashTable.table = new Node*[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        hashTable.table[i] = nullptr;
    }
}

void InsertIntoHashTable(HashTable& hashTable, student s) {
    int hashIndex = hashFunction(s.id);
    InsertBegin(hashTable.table[hashIndex], s);
}

Node* searchByID(Node* hashTable[], int id) {
    int hashIndex = hashFunction(id);

    Node* current = hashTable[hashIndex];
    while (current != nullptr) {
        if (current->info.id == id) {
            return current; // Found the student
        }   
        current = current->next;
    }

    return nullptr; // Student with specified ID not found
}

int main(){
    HashTable hashTable;
    InitTable(hashTable, 100);

    Node*H;
    InitList(H);
    student s1 = {20210001,"Nguyen Van A","DT1",3.0};
    student s2 = {20210002,"Nguyen Van B","DT1",3.5};
    student s3 = {20210003,"Nguyen Van C","DT1",4.0};
    InsertBegin(H,s1);
    InsertBegin(H,s2);
    InsertBegin(H,s3);
    print(H);

    InsertIntoHashTable(hashTable, s1);
    InsertIntoHashTable(hashTable, s2);
    InsertIntoHashTable(hashTable, s3);
    Node* foundStudent = searchByID(hashTable.table, 20210001);
    if (foundStudent != nullptr) {
        cout << "Student found! ID: " << foundStudent->info.id << ", Name: " << foundStudent->info.name << endl;
    } else {
        cout << "Student not found!" << endl;
    }

    return 0;

}