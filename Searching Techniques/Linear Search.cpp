#include <iostream>
#define MAX 20
using namespace std;

int intArray[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};

void printline(int count) {
   int i;
	
   for(i = 0;i <count-1;i++) {
      printf("=");
   }
	
   printf("=\n");
}

int find(int data) {

   int comparisons = 0;
   int index = -1;
   int i;
   for(i = 0;i<MAX;i++) {
      comparisons++;
      if(data == intArray[i]) {
         index = i;
         break;
      }
   }   
	
   printf("Total comparisons made: %d", comparisons);
   return index;
}

void display() {
   int i;
   printf("[");
   for(i = 0;i<MAX;i++) {
      printf("%d ",intArray[i]);
   }
   printf("]\n");
}

void main() {
   int location = find(55);
}