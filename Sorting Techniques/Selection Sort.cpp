#include <iostream>
#define MAX 7

int intArray[MAX] = { 4,6,3,2,1,9,7 };

void display() {
    int i;
    printf("[");
    for (i = 0;i < MAX;i++) {
        printf("%d ", intArray[i]);
    }
    printf("]\n");
}

void selectionSort() {
    int indexMin, i, j;
    for (i = 0; i < MAX - 1; i++) {
        indexMin = i;
        for (j = i + 1;j < MAX;j++) {
            if (intArray[j] < intArray[indexMin]) {
                indexMin = j;
            }
        }

        if (indexMin != i) {
            int temp = intArray[indexMin];
            intArray[indexMin] = intArray[i];
            intArray[i] = temp;
        }
    }
}

void main() {
    selectionSort();
    display();
}