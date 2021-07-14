#include <stdio.h>
#include <cstdlib>
using namespace std;


struct node { 
    int data;
    int key;
    struct node* next;
    struct node* prev;
};

struct node* head=NULL;
struct node* tail=head;
struct node* current=NULL;

bool IsEmpty() {
    return head == NULL;
}
void print_front() {
    struct node* ptr = head;
    printf("\n[");
    while (ptr != NULL) {
        printf("(%d,%d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

void print_tail() {
    struct node* ptr = tail;
    printf("\n[");
    while (ptr != NULL) {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->prev;
    }
    printf("]\n");
}

void insert_head(int key, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->key = key;
    ptr->data = data;
    if (IsEmpty()) {
        tail = ptr;
    }
    else {
        head->prev = ptr;
    }
    ptr->next = head;
    head = ptr;
}

void insert_tail(int key, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->data = data;
    if (IsEmpty()) {
        tail = newnode;
    }
    else {
    tail->next = newnode;
    tail = newnode->next;
    }
    tail = newnode;
}
struct node* delete_head() {
    struct node* ptr = head;
    if (head->next == NULL) {
        tail = NULL;
    }
    else {
        head->next->prev = NULL;
    }
    head = head->next;
    return ptr;
}
struct node* delete_tail() {
    struct node* ptr = tail;
    if (head->next == NULL) {
        head = NULL;
    }
    else {
        tail->prev->next = NULL;
    }
    tail = tail->prev;
    return ptr;
}
struct node* delete_key(int key) {
    struct node* current = head;
    struct node* previous = NULL;
    if (head == NULL) {
        return NULL;
    }
    while (current->key != key) {
        if (current->next == NULL) {
            return NULL;
        }
        else {
            previous = current;
            current = current->next;
        }
    }
    if (current == head) {
        head = head->next;
    }
    else {
        current->prev->next = current->next;
    }
    if (current == tail) {
        tail = current->prev;
    }
    else {
        current->next->prev = current->prev;
    }
    return current;
}
bool insert_key(int key, int newKey, int data) {
    struct node* current = head;
    if (head == NULL) {
        return false;
    }
    while (current->key != key) {
        if (current->next == NULL) {
            return false;
        }
        else {
            current = current->next;
        }
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = newKey;
    newnode->data = data;

    if (current == tail) {
        newnode->next = NULL;
        tail = newnode;
    }
    else {
        newnode->next = current->next;
        current->next->prev = newnode;
    }
    newnode->prev = current;
    current->next = newnode;
    return true;
}
int main() {
    insert_head(1, 10);
    insert_head(2, 20);
    insert_head(3, 30);
    delete_head();
    print_front();
    delete_tail();
    print_front();
    insert_key(2, 7, 20);
    print_front();
    delete_key(7);
    print_front();
}