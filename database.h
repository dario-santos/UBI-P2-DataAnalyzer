#ifndef _DATABASE_H_
#define _DATABASE_H_

#define MAX_SIZE 100000

typedef struct DATABASE
{
    int id;
    char* number;
    struct DATABASE *p_next;
    struct DATABASE *p_prev; 
} Database;

Database policeDatabase[MAX_SIZE];

/*
 * Function: database_free
 * -----------------------
 *   Frees the allocated memory
 * 
 *   L: The list to free
 *
 *   returns: NULL
 */
Database *database_free(DataBase *L);

#endif //_DATABASE_H_