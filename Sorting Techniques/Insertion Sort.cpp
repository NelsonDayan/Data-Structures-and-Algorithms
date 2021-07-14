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

void insertionSort() {

    int valueToInsert;
    int holePosition;
    int i;
    for (i = 1; i < MAX; i++) {
        valueToInsert = intArray[i];
        holePosition = i;
        while (holePosition > 0 && intArray[holePosition - 1] > valueToInsert) {
            intArray[holePosition] = intArray[holePosition - 1];
            holePosition--;
        }
        if (holePosition != i) {
            intArray[holePosition] = valueToInsert;
        }
    }
}

void main() {
    insertionSort();
    display();
}