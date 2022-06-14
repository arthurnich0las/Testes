#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size, int *vidas, int *chances);

int compare(char *letra, char pAdv[], char palavra[], int *contador, int contt, int i, int size, int *vidas, int *chances)
{
    int x = 0;
    for (int i = 0; i<size; i++)
    {
        char *aux = &pAdv[i];

        if(*aux == *letra) //comparando a letra do índice atual para ver se já havia sido inserida
        {
            system("clear");
            printf("Letra já inserida.\n");
            x = 0;
            break; //caso seja inserida, há o 'break' do laço de repetição
        }
        if(palavra[i] == *letra)  //comparando a letra com o indice da palavra
        {
            contt+=1;           //caso seja encontrada, adiciona um contador as vezes que foi encontrada
            pAdv[i] = *letra;   //substituimos na 'palavra adivinhada'
            x = 1;              //aux para ajudar a printar no final da função
        }
    }

    if (contt == 0){            //condição para quando não encontrar nenhuma letra
        system("clear");
        *vidas = *vidas - 1;
        printf("A letra '%c' não foi encontrada\n", *letra);
    }

    *contador = *contador+1; 

    if(x == 1) 
    {
        system("clear");
        printf("A letra '%c' foi encontrada %d vezes.\n", *letra, contt);
    }
    
    return escanear(letra, pAdv, palavra, contador, 0, size, vidas, chances);
}

int escanear(char *letra, char pAdv[], char palavra[], int *contador, int i, int size, int *vidas, int *chances)
{
    if(*vidas == 0){
        int opc;
        system("clear");
        printf("Acabaram suas vidas :(\n\n");
        printf("Gostaria de tentar novamente?\n");
        printf("\n0 - Encerrar programa\n1 - Tentar novamente\n");
        scanf("%d", opc);
        if(opc == 0) { exit(0);}
        else if (opc==1) { main();} 
    }

    if(strcmp(pAdv, palavra) == 0){
        printf("\nParabéns! Você descobriu a palavra em %d chances.\n\nPalavra encontrada: '", *chances);
        for(int i = 0; i<size; i++)
        {
            printf("%c", pAdv[i]);
        }
        printf("'");
        printf("\n\n");
        return 0;
    }

    printf("\nVidas: %d", *vidas);
    printf("\nPalavra: ");
    
        for(int i = 0; i<size; i++)
        {
            printf("%c", pAdv[i]);
        }

    printf("\n\nDigite uma letra: ");
    scanf(" %c", letra);
      //perder vida quando acerta nao da
    *chances = *chances +1;

    compare(letra, pAdv, palavra, contador, 0, 0, size, vidas, chances);
}

int main()
{
    int vidas = 10;
    int chances = 0;
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

    int size = strlen(palavra7);

    char *pAdv = (char*) malloc(size*sizeof(char));

    int contador = 0, aux = 0;

    for(int i = 0; i<size; i++)
    {
        *(pAdv+i) = '_';
    }

    printf("Palavra escolhida!\n");

    char letra;

    escanear(&letra, pAdv, palavra7, &contador, 0, size, &vidas, &chances);
}
