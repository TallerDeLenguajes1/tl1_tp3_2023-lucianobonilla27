#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar(int *mt){
    for (int i = 0; i < 5*12; i++)
    {
        *(mt+i) =  rand() % 50000 + 10000;
        
    }
    
}

int main()
{
  
    int mt[5][12],max=0,anioM,mesM,min=50000,aniom,mesm;
    float prom=0;
    inicializar(mt);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%d  ",mt[i][j]);
        }
        printf("\n");
    }
     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            prom = mt[i][j]+prom;
        }
        prom = prom/12;
        printf("promedio anio %d = %.2f\n",2024 + i,prom);
        prom=0;
    }
     for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (mt[i][j] < min)
            {
                min = mt[i][j];
                aniom = 2023 + i;
                mesm = j+1;
            }
            if (mt[i][j] > max)
            {
                max = mt[i][j];
                anioM = 2023 + i;
                mesM = j+1;
            }
            
            
        }
        
    }
    printf("el valor maximo fue %d obtenido el %d/%d\n",max,mesM,anioM);
    printf("el valor minimo fue %d obtenido el %d/%d\n",min,mesm,aniom);


    
    return 0;
}

/*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.
*/