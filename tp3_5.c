#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char **v;
    int tama;
    printf("ingrese la cantidad de nombres: \n");
    scanf("%d",&tama);
    v = malloc(tama * sizeof(char));

    for (int i = 0; i < tama; i++)
    {
        v[i] = malloc(sizeof(char) * 20);
    }
    
     for (int i = 0; i < tama; i++)
    {
        printf("ingrese el nombre %d: \n",i+1);
        scanf("%s",v[i]);
    }
    
    for (int i = 0; i < tama; i++)
    {
        printf("nombre %d: \n",i+1);
        printf("%s\n",v[i]);
    }





      for (int i = 0; i < tama; i++)
    {
        free(v[i]);
    }
    free(v);
    
    return 0;
}