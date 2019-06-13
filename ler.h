#ifndef _LER_H_
#include "structs.h"

void lerMain(void);

void copiarFicheiro(DataBase policeDataBase[], FILE* ficheiro);

int copiarID(FILE* ficheiro);

void copiarNumero(DataBase policeDataBase[],int i ,FILE* ficheiro);


//Libertar Memória
void freeMemoryLer(DataBase policeDataBase[]);


#endif // _LER_H_

