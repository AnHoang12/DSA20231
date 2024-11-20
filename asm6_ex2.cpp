#include <iostream>
using namespace std;

struct student
{
    int ID;
    char name[50];
    char classname[50];
    float gpa;
};

struct Node
{
    student key;
    Node *LP, *RP;
};

typedef Node *PNode;
typedef Node *BinaryTree;
typedef Node *BSeachTree;

//Khoi tao list
void Init(BinaryTree &Root){
    Root = NULL;
}

//Tim node SV voi mssv 
PNode SearchT(BSeachTree &Root, int id){
    student x;
    x.ID = id;
    if (Root == NULL) {
        return NULL;
    }
    if ( x.ID == Root->key.ID) return Root;
    else if(x.ID < Root->key.ID) return SearchT(Root->LP, id);
    else return SearchT(Root->RP, id);
}

//Them sinh vien
PNode InsertTree(BSeachTree &Root, student x){
    PNode Q;
    if (Root == NULL){
        Q = new Node;
        Q->key =  x;
        Q->LP = Q->RP = NULL;
        Root = Q;
    }
    else if(x.ID < Root->key.ID) return InsertTree(Root->LP, x);
    else return InsertTree(Root->RP, x);
}

//Xoa 1 node
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
        P->key.ID = Q->key.ID;
        P->LP = Q->LP;
        } 
        else {
            do {//Dùng R để lưu parent của Q
            R = Q;
            Q = Q->RP;
            } while (Q->RP != NULL);
            P->key.ID = Q->key.ID; //Lấy giá trị ở Q đưa lên
            R->RP = Q->LP; //Chuyển con của Q lên vị trí Q
        }
        }
    delete Q;
}

//xoa 1 sinh vien 
void DeleteTree(BSeachTree &Root, int id){
    student x;
    x.ID = id;
    if(Root != NULL){
        if(x.ID < Root->key.ID) DeleteTree(Root->LP, id);
        else if(x.ID > Root->key.ID) DeleteTree(Root->RP, id);
        else DeleteNode(Root);
    }
}

//Duyet cay theo thu tu truoc
void PreOrderTraversal (BinaryTree T) {
    if (T == NULL) return;
    cout <<"ID: "<< T->key.ID <<" Name: "<< T->key.name <<" Class: "<< T->key.classname <<" GPA: "<< T->key.gpa << endl;
    PreOrderTraversal(T->LP);
    PreOrderTraversal(T->RP);
}

//In ra sinh vien
void findbyID(PNode T){
    if (T==NULL) cout << "Student not found" << endl;
    else{
        cout << "Student found by ID=" << T->key.ID << endl;
        cout <<"ID: "<< T->key.ID <<" Name: "<< T->key.name <<" Class: "<< T->key.classname <<" GPA: "<< T->key.gpa << endl;
    }
}

void printS(PNode T){
    cout <<"ID: "<< T->key.ID <<" Name: "<< T->key.name <<" Class: "<< T->key.classname <<" GPA: "<< T->key.gpa << endl;
}

//tim sv co gpa cao nhat
PNode highestGPA(BSeachTree &Root, student x){
    if (Root == NULL) {
        return NULL;
    }
    if (x.gpa < Root->key.gpa) return Root;
    else if(x.gpa > Root->key.gpa || x.gpa == Root->key.gpa) return highestGPA(Root->LP, x);
    else return highestGPA(Root->RP, x);
}

//tinh tong gpa 
int sumGPA(BSeachTree T){
    if(T == NULL) return 0;
    else return(T->key.gpa + sumGPA(T->LP) + sumGPA(T->RP));
}

int main(){
    BSeachTree T;
    Init(T);
    student s1 = {1,"Nguyen Van A","DT3",3.0};
    student s2 = {2,"Nguyen Van B","DT3",3.5};
    student s3 = {3,"Nguyen Van C","DT3",2.5};
    student s4 = {4,"Nguyen Van D","DT3",3.0};

    InsertTree(T,s3);
    InsertTree(T,s2);
    InsertTree(T,s1);
    InsertTree(T,s4);
    PreOrderTraversal(T);
    DeleteTree(T,1);
    PreOrderTraversal(T);
    //findbyID(SearchT(T,0));
   // printS(highestGPA(T,s1));
    //cout << "Sum of GPA: " << sumGPA(T);
}