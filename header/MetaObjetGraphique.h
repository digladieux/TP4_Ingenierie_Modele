#ifndef _METAOBJETGRAPHIQUE_H
#define _METAOBJETGRAPHIQUE_H
#define NBCLASSES 3

#include "ObjetGraphique.h"

typedef struct ObjetGraphique ObjetGraphique_;

void ConstructeurMetaObjetGraphique() ;

typedef struct MetaObjetGraphique {

/* TVMs */
void (*TVMafficher[NBCLASSES])(ObjetGraphique_ *);
void (*TVMeffacer[NBCLASSES])(ObjetGraphique_ *);
void (*TVMdeplacer[NBCLASSES])(ObjetGraphique_ *);
int (*TVMgetCentreX[NBCLASSES])(ObjetGraphique_ *);
int (*TVMgetCentreY[NBCLASSES])(ObjetGraphique_ *);
/* pointeurs pour appeler les méthodes */
void (*afficher)(ObjetGraphique_ *);
void (*effacer)(ObjetGraphique_ *);
void (*deplacer)(ObjetGraphique_ *);
int (*getCentreX)(ObjetGraphique_ *);
int (*getCentreY)(ObjetGraphique_ *);


/* méthodes d’instances */
 void (*setX)(int, ObjetGraphique_*) ;
 void (*setY)(int, ObjetGraphique_*) ;
 int (*getX)(ObjetGraphique_*) ;
 int (*getY)(ObjetGraphique_*) ;
 /* attributs de classe */
 int NbObjetGraphique ;
 /* méthodes de classe */
 int (*GetNbObjetGraphique)(void);
 /* constructeur de la classe */
 ObjetGraphique_* (*ConstructeurObjetGraphique)();

} MetaObjectGraphique_ ;


#endif 