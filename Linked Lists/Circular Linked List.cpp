#include <stdio.h>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    int key;

    struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

bool isEmpty() {
    return head == NULL;
}

void insert(int key, int data) {
    struct node* link = (struct node*)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty()) {
        head = link;
        head->next = head;
    }
    else {
        link->next = head;
        head = link;
    }
}

struct node* delete_() {
    struct node* ptr = head;
    if (head->next == head) {
        head = NULL;
        return ptr;
    }
    head = head->next;
    return ptr;
}

void print() {
    struct node* ptr = head;
    printf("\n[");
    if (head != NULL) {
        while (ptr->next != ptr) {
            printf("(%d,%d) ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }

    printf("]");
}

void main() {
    insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    print();
    delete_();
    print();
}