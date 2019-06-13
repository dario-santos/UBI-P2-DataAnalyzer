#include <stdio.h>
#include "ler.h"
#include "pesquisar.h"



int mostrarMenu(void);

int main(void)
{
    int introduzido = -1;
    int isLerMainExecuted = 0;


    do{
        introduzido = mostrarMenu();

        switch(introduzido)
        {
            case 1:
                isLerMainExecuted = 1;
                lerMain();
                break;
            case 2:
                if(!isLerMainExecuted)
                    printf("\n\nTem de ler o ficheiro primeiro!\n");
                else
                    pesquisarMain();
                break;
            case 0:
                freeMemoryLer(policeDataBase);
                break;
        }

    }while(introduzido != 0);


    return 0;
}

int mostrarMenu(void)
{
    int introduzido;

    printf("***************************************\n");
    printf("1: Leitura de ficheiro\n");
    printf("2: Pesquisa de conteudo\n\n");
    printf("0: Exit\n");
    printf("***************************************\n");
    printf("Inserido: ");
    scanf("%d", &introduzido);

    return introduzido;

}
