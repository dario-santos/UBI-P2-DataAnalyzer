#include "pesquisar.h"
#include "ordenarAlg.h"

///////////////////////////////
/////PESQUISAR/////////////////

void pesquisarMain(void)
{
    DadosEncontrados* dados = NULL;
    char *numProcurar  = (char*) malloc(2049 * sizeof(char));
    int sizeNumProcurar;
    int n, i;
    int nOfZeros = 0;

    getInput(numProcurar, &sizeNumProcurar, &n);

    numProcurar  = (char*) realloc(numProcurar,(sizeNumProcurar + 1) * sizeof(char)); //Null Operator
    dados = (DadosEncontrados*) realloc(dados, MAX_SIZE * sizeof(DadosEncontrados));

    for(i = 0 ; i < MAX_SIZE ; i++)
    {
        dados[i].ID = getID(&policeDataBase[i].ID);
        dados[i].dif = calcularDif(numProcurar, policeDataBase[i].numero, sizeNumProcurar, (2049 - sizeNumProcurar), &nOfZeros);

        printf("\ni : %d", i);
        if(nOfZeros == n)
            break;

    }

    i = i == MAX_SIZE ? i - 1 : i;
    quickSort(dados,0, i);

    dataOutput(&n, dados);
    freeMemoryPesquisar(numProcurar, dados);

}

void getInput(char* numProcurar, int* sizeNumProcurar, int* n)
{
    int verifyBinaryInput;
    do{
        printf("\nInsira o numero que quer procurar: ");
        scanf("%s", numProcurar);

        *sizeNumProcurar = strlen(numProcurar);
        verifyBinaryInput = verifNumProcurar(numProcurar, *sizeNumProcurar);
        if(!verifyBinaryInput)
            printf("\nErro: Introduza um numero binario");
        if(*sizeNumProcurar <= 1 || *sizeNumProcurar >= 2048)
            printf("\nErro: Introduza um numero com mais do que um digito e menos do que 2048");


    }while((*sizeNumProcurar <= 1 || *sizeNumProcurar >= 2048) || !verifyBinaryInput);

    do{
        printf("Insira quantos ID quer receber: ");
        scanf("%d", n);

    }while(*n < 1 || *n > MAX_SIZE);

}

int verifNumProcurar(char* numProcurar, int sizeNumProcurar)
{
    int i;
    for(i = 0 ; i < sizeNumProcurar ; i++)
        if(numProcurar[i] != '0' && numProcurar[i] != '1' )
            return 0;

    return 1;

}

int* getID(int* ID)
{
    return ID;
}


int calcularDif(char* numProcurar, char* linha, int sizeNumProcurar, int tamanhoLinha, int* nOfZeros)
{

    int dif = sizeNumProcurar;
    int menorDif =  sizeNumProcurar;

    int i, j;
    for(i = 0; i < tamanhoLinha; i++)
    {

        if(i + sizeNumProcurar <= 4095)
            for(j = 0; j < sizeNumProcurar ; j++ )
                if(numProcurar[j] == linha[j+i])
                    --dif;

        menorDif = dif < menorDif ? dif : menorDif;
        dif = sizeNumProcurar;

        if(menorDif == 0)
        {
            (*nOfZeros)++;
            return 0;
        }
    }

    return menorDif;
}

void dataOutput(int* n, DadosEncontrados* dados)
{
    int i;
    printf("\n\nDados Obtidos:\n");
    for(i  = 0 ; i < *n ; i++)
    {
        printf("\nid: %08d. Dif: %d", *dados[i].ID, dados[i].dif);

        if( i % 20 == 0 && i >= 20)
        {
            printf("\nPrima uma tecla para obter os proximos 20 ID...");
            getchar();
        }
    }

    printf("\n");
    return;
}


void freeMemoryPesquisar(char* numProcurar, DadosEncontrados* dados)
{
    free(dados);
    free(numProcurar);
}
