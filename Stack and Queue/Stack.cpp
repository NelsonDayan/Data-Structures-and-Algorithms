#include <stdio.h>
using namespace std;

int top = 0,MAXSIZE=30, stack[30];

int push(int i) {
	if (top == MAXSIZE) {
		return 1;
	}
	stack[top] = i;
	top += 1;
}

int pop() {
	if (top == -1) {
		return 1;
	}
	stack[top] = NULL;
	top -= 1;
}

int peek() {
	return stack[top-1];
}

bool IsEmpty() {
	return top == 0;
}

bool IsFull() {
	return top == MAXSIZE;
}
int main() {
	push(1);
	push(2);
	push(3);
	printf("%d\n",peek());
	pop();
	pop();
	printf(IsEmpty() ? "true\n" : "false\n");
	printf(IsFull() ? "true\n" : "false\n");
}