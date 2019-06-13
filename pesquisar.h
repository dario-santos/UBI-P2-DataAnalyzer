#ifndef _PESQUISAR_H_
#include "structs.h"


////////////////////////
//// Pesquisar /////////

void pesquisarMain(void);

void getInput(char* numProcurar, int* sizeNumProcurar, int* n);

int verifNumProcurar(char* numProcurar, int sizeNumProcurar);

int* getID(int* ID);

int calcularDif(char* inserido, char* linha, int inseridoTamanho, int tamanhoLinha, int* nOfZeros);

void dataOutput(int* n, DadosEncontrados* dados);

void freeMemoryPesquisar(char* numProcurar, DadosEncontrados* dados);


#endif // _PESQUISAR_H_
