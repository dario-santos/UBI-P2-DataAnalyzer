#include "ordenarAlg.h"

void quickSort(DadosEncontrados dados[], int first, int last)
{
    int pivot, temp, i, j;
    int p_temp;

    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while(i < j)
        {
            while(dados[i].dif <= dados[pivot].dif && i < last)
                i++;

            while(dados[j].dif > dados[pivot].dif)
                j--;

            if(i < j)
                quickSortSwap(dados, i, j);

        } //while
        quickSortSwap(dados, pivot, j);

        quickSort(dados, first , j - 1);
        quickSort(dados, j + 1 , last);

    }
}
void quickSortSwap(DadosEncontrados* dados, int i, int j)
{
    int difTemp, idTemp;

    difTemp = dados[i].dif;
    idTemp = dados[i].ID;


    dados[i].dif = dados[j].dif;
    dados[i].ID = dados[j].ID;


    dados[j].dif = difTemp;
    dados[j].ID = idTemp;

}
