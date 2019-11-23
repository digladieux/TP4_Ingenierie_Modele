#ifndef _OBJETGRAPHIQUE_H
#define _OBJETGRAPHIQUE_H

#include "MetaObjetGraphique.h"

struct MetaObjectGraphique;
typedef enum OG { OG, CERCLE, RECTANGLE } OG_t ;

typedef struct ObjetGraphique
{
    struct MetaObjetGraphique* myClass ;
    int x ;
    int y ;
    OG_t type ;
} ObjetGraphique_;


#endif 