#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *LP, *RP;
};

typedef Node *PNode;
typedef Node *BinaryTree;
typedef Node *BSeachTree;

void Init(BinaryTree &Root){
    Root = NULL;
}
PNode SearchT(BSeachTree &Root, int x){
    if (Root == NULL) return NULL;
    if ( x == Root->key) return Root;
    else if(x < Root->key) return SearchT(Root->LP, x);
    else return SearchT(Root->RP, x);
}

PNode InsertTree(BSeachTree &Root, int x){
    PNode Q;
    if (Root == NULL){
        Q = new Node;
        Q->key = x;
        Q->LP = Q->RP = NULL;
        Root = Q;
    }
    else if(x < Root->key) return InsertTree(Root->LP, x);
    else return InsertTree(Root->RP, x);
}

void DeleteNode (PNode & P) { 
    PNode Q, R;
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
        P->key = Q->key;
        P->LP = Q->LP;
        } 
        else {
            do {//Dùng R để lưu parent của Q
            R = Q;
            Q = Q->RP;
            } while (Q->RP != NULL);
            P->key = Q->key; //Lấy giá trị ở Q đưa lên
            R->RP = Q->LP; //Chuyển con của Q lên vị trí Q
        }
        }
    delete Q;
}

void DeleteTree(BSeachTree &Root, int x){
    if(Root != NULL){
        if(x < Root->key) DeleteTree(Root->LP, x);
        else if(x > Root->key) DeleteTree(Root->RP, x);
        else DeleteNode(Root);
    }
}

void PreOrderTraversal (BinaryTree T) {
    if (T == NULL) return;
    cout << T->key << endl;
    PreOrderTraversal(T->LP);
    PreOrderTraversal(T->RP);
}

int countNode(BSeachTree T){
    if (T == NULL) return 0;
    else return (1 + countNode(T->LP) + countNode(T->RP));
}

int sumNode(BSeachTree T){
    if(T == NULL) return 0;
    else return(T->key + sumNode(T->LP) + sumNode(T->RP));
}

int main(){
    BSeachTree T;
    Init(T);
    InsertTree(T,3);
    InsertTree(T,1);
    InsertTree(T,2);
    InsertTree(T,4);
    DeleteTree(T,3);
    PreOrderTraversal(T);
    cout << "So node:" << countNode(T) << endl;
    cout << "Tong:"<< sumNode(T) << endl;
}