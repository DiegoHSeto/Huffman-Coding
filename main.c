#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"

int main()
{
    char test[] = "Hello World";

    printf("Caracteres compactados: \n\n");

    compact(test);
    return 0;
}
