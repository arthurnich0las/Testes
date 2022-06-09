#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size);

int compare(char *letra, char pAdv[], char palavra[], int *contador, int contt, int i, int size)
{
    for (int i = 0; i<size; i++)
    {
        char *aux = &pAdv[i];

        if(*aux == *letra)
        {
            printf("Letra já inserida.\n");
            break;
        }
        if(palavra[i] == *letra)
        {
            contt+=1;
            pAdv[i] = *letra;
        }
    }

    *contador = *contador+1;

    printf("A letra %c foi encontrada %d vezes.\n", *letra, contt);
    return escanear(letra, pAdv, palavra, contador, 0, size);
}

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size)
{

    if(*contador == size+1){
        printf("\nParabéns! Você descobriu a palavra.\nPalavra encontrada: ");
        for(int i = 0; i<size; i++)
        {
            printf("%c", pAdv[i]);
        }
        printf("\n");
        return 0;
    }

    printf("\nPalavra: ");
        for(int i = 0; i<size; i++)
        {
            printf("%c", pAdv[i]);
        }

    printf("\n\nDigite uma letra: ");
    scanf("%c", letra);

    compare(letra, pAdv, palavra, contador, 0, 0, size);
}

int main()
{
    system("clear");

    char palavra[] = "paralelepipedo";
    int size = strlen(palavra);

    char *pAdv = (char*) malloc(size*sizeof(char));

    int contador = 0, aux = 0;

    for(int i = 0; i<size; i++)
    {
        *(pAdv+i) = '_';
    }

    printf("Palavra escolhida!\n");

    char letra;

    escanear(&letra, pAdv, palavra, &contador, 0, size);
}
