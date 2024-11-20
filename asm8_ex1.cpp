#include <stdio.h>

#define MAX_SIZE 100 // Định nghĩa kích thước tối đa cho ma trận kề

// Hàm thêm cung từ đỉnh i đến đỉnh j
void themCung(int n, int graph[][MAX_SIZE], int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        graph[i][j] = 1; // Thêm cung từ i đến j
        // Nếu là đồ thị vô hướng thì cần thêm cung từ j đến i
        // graph[j][i] = 1; // Bỏ comment nếu là đồ thị vô hướng
    } else {
        printf("Không hợp lệ!\n");
    }
}

// Hàm loại bỏ cung từ đỉnh i đến đỉnh j
void loaiBoCung(int n, int graph[][MAX_SIZE], int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n) {
        graph[i][j] = 0; // Loại bỏ cung từ i đến j
        // Nếu là đồ thị vô hướng thì cần loại bỏ cung từ j đến i
        // graph[j][i] = 0; // Bỏ comment nếu là đồ thị vô hướng
    } else {
        printf("Không hợp lệ!\n");
    }
}

// Hàm in ma trận kề
void inMaTran(int n, int graph[][MAX_SIZE]) {
    printf("Ma trận kề:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n; // Số đỉnh của đồ thị
    printf("Nhập số đỉnh của đồ thị: ");
    scanf("%d", &n);

    int graph[MAX_SIZE][MAX_SIZE] = {0}; // Khởi tạo ma trận kề ban đầu

    // Thêm và loại bỏ cung từ đỉnh i đến đỉnh j
    themCung(n, graph, 0, 1);
    loaiBoCung(n, graph, 2, 3);

    // In ma trận kề
    inMaTran(n, graph);

    return 0;
}