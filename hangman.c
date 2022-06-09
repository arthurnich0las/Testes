#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size);

int compare(char *letra, char pAdv[], char palavra[], int *contador, int contt, int i, int size)
{
    int x;
    for (int i = 0; i<size; i++)
    {
        char *aux = &pAdv[i];

        if(*aux == *letra)
        {
            system("clear");
            printf("Letra já inserida.\n");
            x = 0;
            break;
        }
        if(palavra[i] == *letra)
        {
            contt+=1;
            pAdv[i] = *letra;
            x = 1;
        }
    }

    //adicionar letra não encontrada;

    *contador = *contador+1;

    if(x == 1) 
    {
        system("clear");
        printf("A letra '%c' foi encontrada %d vezes.\n", *letra, contt);
    }
    
    return escanear(letra, pAdv, palavra, contador, 0, size);
}

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size)
{
    if(strcmp(pAdv, palavra) == 0){
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
    scanf(" %c", letra);

    compare(letra, pAdv, palavra, contador, 0, 0, size);
}

int main()
{

    system("clear");

    char palavra1[] = {"paralelepipedo"};
    char palavra2[] = {"funcional"};
    char palavra3[] = {"computador"};
    char palavra4[] = {"programa"};
    char palavra5[] = {"televisao"};
    char palavra6[] = {"havainas"};
    char palavra7[] = {"racionais"};
    char palavra8[] = {"universidade"};
    char palavra9[] = {"academia"};
    char palavra0[] = {"derrotado"};
    char pEscolhida[] = {""};

    int size = strlen(palavra8);

    char *pAdv = (char*) malloc(size*sizeof(char));

    int contador = 0, aux = 0;

    for(int i = 0; i<size; i++)
    {
        *(pAdv+i) = '_';
    }

    printf("Palavra escolhida!\n");

    char letra;

    escanear(&letra, pAdv, palavra8, &contador, 0, size);
}
