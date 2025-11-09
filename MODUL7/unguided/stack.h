#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    int info[20];  // tetap int, tapi bisa menampung char
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
void pushChar(Stack &S, char c);
int pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);

#endif
