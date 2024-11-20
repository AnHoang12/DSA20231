#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct LinkedList {
    struct Node* head;
};

void append(struct LinkedList* list, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void insert_at_position(struct LinkedList* list, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    struct Node* current = list->head;
    int i;
    for (i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void display(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList my_list;
    my_list.head = NULL;

    append(&my_list, 1);
    append(&my_list, 2);
    append(&my_list, 3);

    printf("Danh sách ban đầu:\n");
    display(&my_list);

    insert_at_position(&my_list, 4, 1);

    printf("Danh sách sau khi chèn:\n");
    display(&my_list);

    return 0;
}
