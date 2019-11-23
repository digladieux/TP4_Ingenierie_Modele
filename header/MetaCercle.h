#ifndef _METACERCLE_H
#define _METACERCLE_H

#include "MetaObjetGraphique.h"
#include "Cercle.h"

typedef struct Cercle Cercle_;

void ConstructeurMetaCercle() ;

typedef struct MetaCercle
{
 struct MetaObjetGraphique * superMetaClasse ;
 /* méthodes d’instances */
 void (*setRayon)( int, Cercle_*) ;
 int (*getRayon)(Cercle_*) ;
 /* constructeur de la classe */

 Cercle_* (*ConstructeurCercle)();
} MetaCercle_;


#endif