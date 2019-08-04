#include "readf.h"

int readf_int(FILE* f)
{
    int aux;

    fscanf(f, "%d", &aux);
    
    return aux;
}

char readf_char(FILE* f)
{
    char aux;

    aux = fgetc(f);
    
    return aux;
}

char *readf_string(FILE *f, int length)
{
    char aux[length + 1]; 

    fgets(aux, length, f);

    return aux;
}

int main(void)
{
    FILE *f = fopen("teste.txt", "r");

    int x = readf_int(f);
    
    char c = readf_char(f);

    char aux[4] = readf_string(f, 3);

    printf("%d, %c, %s", x, c, aux);
    fclose(f);

    return 0;
}