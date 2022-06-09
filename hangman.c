#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int compare(char *letra, char pAdv[], char palavra[], int *contador, int contt, int i, int size)
{
    for (int i = 0; i<size; i++)
    {
        char *aux = &pAdv[i];

        if(*aux == *letra)
        {
            system("clear");
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
    return escanear(&letra, pAdv, palavra, &contador, 0, size);
}

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size)
{

    if(*contador == size){
        //if(aux==size){
        //int x = 0;
        //printf("Palavra encontrada: ");
        //while(pAdv[x] != '\0')
        //{
        //    printf("%c", pAdv[x]);
        //    x+=1;
        //}
        //printf("\n");

        printf("Palavra encontrada: ");
        for(int i = 0; i<size; i++)
        {
            printf("%c", pAdv[i]);
        }
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
    char palavra[] = "paralelepipedo";
    int size = strlen(palavra);

    char pAdv[size];

    static int contador = 0;
    int aux = 0;
    int i = 0;

    for(int i = 0; i<size; i++)
    {
        pAdv[i] = '_';
    }

    system("clear");

    printf("Palavra escolhida!\n");

    char letra;

    escanear(&letra, pAdv, palavra, &contador, 0, size);

   
}
