#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void compare(char letra[], char pAdv[], char palavra[], int contador, int i)
{
    if(letra[0] == pAdv[i])
    {
        printf("Letra já inserida.\n");
        return;
    }

    if(palavra[i] == '\0')
    {
        printf("A letra %c foi encontrada %d vezes.\n", letra[0], contador);
        return;
    }

    if(letra[0] == palavra[i])
    {
        pAdv[i] = letra[0];
        contador+=1;
        i+=1;

        compare(letra, pAdv, palavra, contador, i);
    }
    
    
}

int main()
{
    char palavra[] = "paralelepipedo";
    int size = sizeof(palavra)/sizeof(palavra[0]);
    char pAdv[size];
    int contador = 0;
    int aux = 0;
    int i = 0;
    for(int i = 0; i<size; i++)
    {
        pAdv[i] = '_';
    }

    system("clear");

    printf("Palavra escolhida...\n");
    sleep(1);

    char letra[1];
    while(1)
    {
        printf("Palavra: ");
        int x = 0;
        while(pAdv[x] != '\0')
        {
            printf("%c", pAdv[x]);
            x++;
        }
        printf("\n\n");

        printf("Digite uma letra: ");
        scanf(" %c", &letra[0]);
        
        compare(letra, pAdv, palavra, 0, 0);

        printf("A letra %c foi encontrada %d vezes\n\n", letra[0], contador);
        contador=0;
        if(aux==size){
            int x = 0;
            printf("Palavra encontrada: ");
            while(pAdv[x] != '\0')
            {
                printf("%c", pAdv[x]);
                x+=1;
            }
            printf("\n");
            return 0;
        }
    }

}
