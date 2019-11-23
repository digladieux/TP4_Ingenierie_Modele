#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "ObjetGraphique.h"
#include "MetaRectangle.h"

struct MetaRectangle ;

typedef struct Rectangle
{
 struct ObjetGraphique superClasse ;
 struct MetaRectangle * myClass ;
 int largeur ;
 int hauteur ;
} Rectangle_ ;
#endif