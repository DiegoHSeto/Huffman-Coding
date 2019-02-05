#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"

typedef struct node *PriorityQueue;

PriorityQueue *createPriorityQueue();
void enqueue(PriorityQueue *pq, huffmanNode *hn);
void dequeue(PriorityQueue *pq);
huffmanNode* getFirstNode(PriorityQueue *pq);
int getSize(PriorityQueue *pq);

