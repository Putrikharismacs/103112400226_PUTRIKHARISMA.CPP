#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5        // index 0–4 sesuai modul
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int head;
    int tail;
} Queue;

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
