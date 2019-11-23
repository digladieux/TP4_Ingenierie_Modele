#ifndef _METARECTANGLE_H
#define _METARECTANGLE_H

typedef struct Rectangle Rectangle_;

void ConstructeurMetaRectangle() ;

typedef struct MetaRectangle
{
 struct MetaObjetGraphique * superMetaClasse ;
 /* méthodes d’instances */
 void (*setLargeur)(int, Rectangle_*) ;
 void (*setHauteur)(int, Rectangle_*) ;
 int (*getLargeur)(Rectangle_*) ;
 int (*getHauteur)(Rectangle_*) ;
 /* constructeur de la classe */
 Rectangle_* (*ConstructeurRectangle)();
} MetaRectangle_;

#endif