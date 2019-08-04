#include "ler.h"

void lerMain(void)
{
    FILE* ficheiro = NULL;

    ficheiro = fopen("DANGER_DB_LARGE.txt", "r");

    if(ficheiro == NULL){
        printf("\nError file don't exist\n");
        exit(EXIT_FAILURE);
    }

    copiarFicheiro(policeDataBase, ficheiro);

    fclose(ficheiro);
}

void copiarFicheiro(DataBase policeDataBase[], FILE* ficheiro)
{
    int i;
    for(i = 0; i < MAX_SIZE; i++)
        {
            policeDataBase[i].numero = (char*) malloc(2049 * sizeof(char)); //Null operator

            policeDataBase[i].ID = copiarID(ficheiro);

            copiarNumero(policeDataBase, i, ficheiro);

            if(i == 25000)
                printf("\nCopiando... 25%% ");
            if(i == 50000)
                printf("\nCopiando... 50%% ");
            if(i == 75000)
                printf("\nCopiando... 75%% ");
            if(i == 99999)
                printf("\nDone.\n");
        }
}

int copiarID(FILE* ficheiro)
{
    int id;
    fscanf(ficheiro,"%d", &id);

    return id;
}

void copiarNumero(DataBase policeDataBase[], int i, FILE* ficheiro)
{
    fgetc(ficheiro); //TAB
    fgets(policeDataBase[i].numero, 2049, ficheiro);
    policeDataBase[i].numero[2049] = '\0';

}

// copiado
void freeMemoryLer(DataBase policeDataBase[])
{
    int i;
    for(i = 0 ; i < MAX_SIZE ; i++ )
        free(policeDataBase[i].numero);

}

