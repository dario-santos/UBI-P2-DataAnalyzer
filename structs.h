#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

struct DataBase{

    int ID;
    char* numero;

};

typedef struct DataBase DataBase;
DataBase policeDataBase[MAX_SIZE];




struct DadosEncontrados{

    int* ID;
    int dif;

};
typedef struct DadosEncontrados DadosEncontrados;

#endif // _STRUCTS_H_
