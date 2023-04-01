#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *v[5];
    for (int i = 0; i < 5; i++)
    {
        v[i] = malloc(sizeof(char)*15);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d:\n", i+1);
        scanf("%s",v[i]);
    }
    fflush(stdin);
    for (int i = 0; i < 5; i++)
    {
        printf("\nNombre %d: %s\n", i+1, v[i]);
    }
    
    for (int i = 0; i < 5; i++)
    {
        free(v[i]);
    }
    
    return 0;
}