#include <stdio.h>
#include <cstdlib>
using namespace std;

//node structure 
struct node { 
    int data;
    int key;
    struct node* next;
};

//defined head and current
struct node* head = NULL;
struct node* current = head;

//print list
void print_list() {
    struct node* ptr = head;
    printf("\n[");
    while (ptr != NULL) {
        printf("(%d,%d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

//insert in front of the list
void insert_front(int key,int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->key = key;
    ptr->data = data;
    ptr->next=head;
    head=ptr;
}

//delete in front of the list
struct node* delete_front() {
    struct node* ptr = head;
    head = head->next;
    return ptr;
}

//check if list is empty
bool IsEmpty() {
    return head == NULL;
}
int Search(int key) {
    struct node* ptr = head;
    while (ptr!=NULL){
        if (key == ptr->key) {
            return ptr->data;
        }
    }
    printf("Key not found!");
}

//Delete node with given key
struct node* delete_key(int key) {
    struct node* pre = NULL;
    struct node* cur = head;
    if (head == NULL) {
        return NULL;
    }
    while (cur->key != key) {
        if (cur->next==NULL) {
            return NULL;
        }
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    if (cur == head) {
        head = head->next;
    }
    else {
        pre->next = cur->next;
    }
    return cur;
}

//Test the above functions
int main() {
    insert_front(1, 10);
    insert_front(2, 20);
    insert_front(3, 30);
    print_list();
    printf(IsEmpty() ? "true" : "false");
    delete_front();
    delete_front();
    delete_key(1);
    print_list();
    printf(IsEmpty() ? "true" : "false");
}