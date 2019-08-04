#include <stdlib.h>
#include "database.h"


Database *database_free(Database *L)
{
    Database *current = L;

    while (current != NULL)
    {
        Database *next = current->p_next;

        free(current);
        current = next;
    }

    return NULL;
}
