#include "HuffmanTree.h"
#include "PriorityQueue.h"
#include <string.h>

struct huffmanNode
{
    char data;
    int frequency;
    struct huffmanNode *left;
    struct huffmanNode *right;
};

void printEncodedCharacters(huffmanNode *ht, int *code, int t)
{

    if(ht->left)
    {
        code[t] = 0;
        printEncodedCharacters(ht->left, code, t+1);
    }

    if(ht->right)
    {
        code[t] = 1;
        printEncodedCharacters(ht->right, code, t+1);
    }

    if(!(ht->left) && !(ht->right))
    {
        printf("%c: ", ht->data);

        for(int i = 0; i < t; i++)
        {
            printf("%d", code[i]);
        }

        printf("\n");
    }


}

void compact(char *string)
{
    huffmanNode *ht = createHuffmanTree(string);

    int arr[100];

    int top = 0;


    printEncodedCharacters(ht, arr, top);


}


huffmanNode *createHuffmanTree(char *string)
{
    /*Criação da fila de prioridades contendo os caracteres
    ordenados por ordem de frequência*/

    PriorityQueue *pq = createPriorityQueue();

    huffmanNode *huffmanTree;

    int *frequency = (int *)calloc(256, sizeof(int));

    for(int i = 0 ; i < strlen(string); i++)
    {
        for(int j = 0; j < 256; j++)
        {
            if(string[i] == j)
            {
                frequency[j]++;
            }
        }
    }

    for(int i = 0; i < 256;i++)
    {
        if(frequency[i]>0)
        {
            huffmanNode *leaf = (huffmanNode*)malloc(sizeof(huffmanNode));

            leaf->data = (char)i;
            leaf->frequency = frequency[i];
            leaf->left = NULL;
            leaf->right = NULL;

            enqueue(pq, leaf);
        }
    }

    //Criação da árvore de Huffman

    while(getSize(pq)>1)
    {
        huffmanNode *parent = (huffmanNode *)malloc(sizeof(huffmanNode));

        parent->data = '?';
        parent->right = getFirstNode(pq);
        dequeue(pq);
        parent->left = getFirstNode(pq);
        dequeue(pq);
        parent->frequency = (parent->right->frequency + parent->left->frequency);
        enqueue(pq, parent);

        huffmanTree = parent;

    }


    return huffmanTree;

}

int getHuffmanNodeFrequency(huffmanNode *hn)
{
    return hn->frequency;
}

char getHuffmanNodeCharacter(huffmanNode *hn)
{
    return hn->data;
}
