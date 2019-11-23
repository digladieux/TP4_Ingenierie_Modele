#ifndef _CERCLE_H
#define _CERCLE_H

#include "ObjetGraphique.h"
#include "MetaCercle.h"
struct MetaCercle ;

typedef struct Cercle
{
 struct ObjetGraphique superClasse ;
 struct MetaCercle * myClass ;
 int rayon ;
} Cercle_; 

#endif