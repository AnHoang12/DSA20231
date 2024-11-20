#include <iostream>
#include <string>
using namespace std;

struct Employee{
    int id;
    string name;
    double salary;
};

struct Node
{
    Employee data;
    Node* LP;
    Node* RP;
};

typedef Node* BSearchTree;

void Initilize(BSearchTree &root){
    root = NULL;
}

Node* makeTreeNode(int mscn, string tenCN,double luong){
    Node* temp = new Node;
    temp->data.id = mscn;
    temp->data.name = tenCN;
    temp->data.salary = luong;
}

void InsertTree(BSearchTree &root, Employee e){
    Node* temp;
    if (root == NULL){
        temp = makeTreeNode(e.id, e.name, e.salary);
        root = temp;
    }
    else if(e.id < root->data.id) return InsertTree(root->LP, e);
    else return InsertTree(root->RP, e);
}

Node* SearchNode(BSearchTree &root, int id){
    Employee e;
    e.id = id;
    if (root == NULL) {
        return NULL;
    }
    if ( e.id == root->data.id) return root;
    else if(e.id < root->data.id) return SearchNode(root->LP, id);
    else return SearchNode(root->RP, id);
}

void DeleteNode (Node* & P) { 
    Node* Q, *R;
    if (P->LP == NULL) { 
    Q = P;
    P = P->RP;
    } 
    else if (P->RP == NULL){
        Q = P;
        P = P->LP;
    }
    else{
        Q = P->LP;
    if (Q->RP == NULL) {
        P->data.id = Q->data.id;
        P->LP = Q->LP;
        } 
        else {
            do {//Dùng R để lưu parent của Q
            R = Q;
            Q = Q->RP;
            } while (Q->RP != NULL);
            P->data.id = Q->data.id; //Lấy giá trị ở Q đưa lên
            R->RP = Q->LP; //Chuyển con của Q lên vị trí Q
        }
        }
    delete Q;
}

void DeleteEmployee(BSearchTree &root, int id){
    Employee e;
    e.id = id;
    if(root!=NULL){
        if(e.id < root->data.id) return DeleteEmployee(root->LP, id);
        else if (e.id > root->data.id) return DeleteEmployee(root->RP, id);
        else return DeleteNode(root);
    }
}

int main(){
    
}