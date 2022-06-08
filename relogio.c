#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    system("clear");

    printf("Defina a hora: ");
    scanf("%d", &horas);
    printf("\nDefina os minutos: ");
    scanf("%d", &minutos);
    printf("\nDefina os segundos: ");
    scanf("%d", &segundos);

    if(horas>24 || minutos>60 || segundos>60){
        printf("Error\n");
        exit(0);
    }

    system("clear");
    while(1){
        segundos++;
        if (segundos>59){
            minutos++;
            segundos = 0;
        }
        else if(minutos>59){
            horas++;
            minutos = 0;
        }
        else if(horas>24){
            horas = 0;
            minutos = 0;
            segundos = 0;
        }
        printf("Horas: ");
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
        sleep(1);
        system("clear");
    }

    return 0;
}