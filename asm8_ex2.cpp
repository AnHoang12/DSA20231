#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho danh sách liên kết
struct Node {
    int vertex;
    struct Node* next;
};

// Hàm tạo một Node mới
struct Node* taoNodeMoi(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cung từ đỉnh i đến đỉnh j
void themCung(struct Node** adjList, int i, int j) {
    // Thêm cung từ i đến j
    struct Node* newNode = taoNodeMoi(j);
    newNode->next = adjList[i];
    adjList[i] = newNode;

    // Nếu là đồ thị vô hướng, thêm cung từ j đến i
    // newNode = taoNodeMoi(i);
    // newNode->next = adjList[j];
    // adjList[j] = newNode;
}

// Hàm loại bỏ cung từ đỉnh i đến đỉnh j
void loaiBoCung(struct Node** adjList, int i, int j) {
    struct Node *prev, *temp;
    temp = adjList[i];

    if (temp != NULL && temp->vertex == j) {
        adjList[i] = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->vertex != j) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Hàm in danh sách kề
void inDanhSachKe(int n, struct Node** adjList) {
    printf("Danh sach ke:\n");
    for (int i = 0; i < n; i++) {
        struct Node* temp = adjList[i];
        printf("Dinh %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n; // Số đỉnh của đồ thị
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);

    struct Node** adjList = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL; // Khởi tạo danh sách kề cho mỗi đỉnh
    }

    // Thêm và loại bỏ cung từ đỉnh i đến đỉnh j
    themCung(adjList, 0, 1);
    loaiBoCung(adjList, 2, 3);

    // In danh sách kề
    inDanhSachKe(n, adjList);

    return 0;
}
