#include "PriorityQueue.h"

struct node
{
    struct huffmanNode *hnode;
    struct node *next;
};

typedef struct node Node;

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));

    if(pq==NULL)
    {
        printf("Falha na alocacao da fila de prioridades");
        exit(0);
    }

    *pq = NULL;

    return pq;
}

void enqueue(PriorityQueue *pq, huffmanNode *hn)
{
    if(pq==NULL)
    {
        printf("Lista invalida!");
        exit(0);
    }

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->hnode = hn;
    newNode->next = NULL;

    if((*pq)==NULL)
    {
        (*pq) = newNode;
    }
    else
    {
        Node *aux = (*pq);
        Node *prev;

        while(aux!= NULL && getHuffmanNodeFrequency(aux->hnode) < getHuffmanNodeFrequency(hn))
        {
            prev = aux;
            aux = aux->next;
        }

        if(aux==(*pq))
        {
            newNode->next = (*pq);
            (*pq) = newNode;
        }
        else
        {
             newNode->next = prev->next;
             prev->next = newNode;
        }

    }
}

void dequeue(PriorityQueue *pq)
{
    if(pq==NULL)
    {
        printf("Lista invalida!");
        exit(0);
    }

    if((*pq)==NULL)
    {
        printf("Impossivel remover de uma fila vazia!");
    }

    Node *aux = (*pq);

    (*pq) = aux->next;
    free(aux);
}

huffmanNode* getFirstNode(PriorityQueue *pq)
{
    return (*pq)->hnode;
}

int getSize(PriorityQueue *pq)
{
    Node *aux = (*pq);
    int count = 0;

    while(aux!=NULL)
    {
        aux = aux->next;
        count++;
    }

    return count;

}

