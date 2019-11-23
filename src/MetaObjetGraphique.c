#include "../header/MetaObjetGraphique.h"
#include "../header/ObjetGraphique.h"
#include <stdlib.h>
#include <stdio.h>
void afficherOG(ObjetGraphique_ * this) ;
extern MetaObjectGraphique_ leMetaOG;
int getX(ObjetGraphique_* this)
{
    return this->x;
}
void setX(int inX, ObjetGraphique_* this)
{
    this->x = inX;
}

int getY(ObjetGraphique_* this)
{
    return this->y;
}
void setY(int inY, ObjetGraphique_* this)
{
    this->y = inY;
}

int GetNbObjetGraphique() {
    MetaObjectGraphique_ m; 
    return m.NbObjetGraphique ;
}

void afficher(ObjetGraphique_ * this) {
    return leMetaOG.TVMafficher[this->type](this);
}
void effacer(ObjetGraphique_ * this) {
    return leMetaOG.TVMeffacer[this->type](this);
}
void deplacer(ObjetGraphique_ * this) {
    return leMetaOG.TVMdeplacer[this->type](this);
}
int getCentreX(ObjetGraphique_ * this) {
    return leMetaOG.TVMgetCentreX[this->type](this);
}
int getCentreY(ObjetGraphique_ * this) {
    return leMetaOG.TVMgetCentreY[this->type](this);
}
void afficherOG(ObjetGraphique_ * this) {
    printf("Afficher - Objet Graphique : x = %d, y = %d\n", this->x, this->y);
}
void effacerOG(ObjetGraphique_ * this) {
    this->myClass = NULL ;
    free(this) ;
}
void deplacerOG(ObjetGraphique_ * this) {
    this->myClass->setX(this->myClass->getX(this) + 10, this);
    this->myClass->setY(this->myClass->getY(this) + 10, this);
}
int getCentreXOG(ObjetGraphique_ * this) {
    return this->x ;
}
int getCentreYOG(ObjetGraphique_ * this) {
    return this->y ;
}

ObjetGraphique_* ConstructeurObjetGraphique() {

    ObjetGraphique_ * this = malloc(sizeof(ObjetGraphique_)) ;
    this->x = 0 ; 
    this->y = 0 ;
    this->myClass = &leMetaOG ;
    this->type = OG ;
    return this ;
}

void ConstructeurMetaObjetGraphique() {
    leMetaOG.getX = getX ;
    leMetaOG.getY = getY ;
    leMetaOG.setX = setX ;
    leMetaOG.setY = setY ;
    leMetaOG.afficher = afficher ;
    leMetaOG.effacer = effacer ;
    leMetaOG.deplacer = deplacer ;
    leMetaOG.getCentreX = getCentreX ;
    leMetaOG.getCentreY = getCentreY ;
    leMetaOG.TVMafficher[OG] = afficherOG ;
    leMetaOG.TVMdeplacer[OG] = deplacerOG ;
    leMetaOG.TVMeffacer[OG] = effacerOG ;
    leMetaOG.TVMgetCentreX[OG] = getCentreXOG ;
    leMetaOG.TVMgetCentreY[OG] = getCentreYOG ;
    leMetaOG.ConstructeurObjetGraphique = ConstructeurObjetGraphique ;
    leMetaOG.GetNbObjetGraphique = GetNbObjetGraphique ;
    leMetaOG.NbObjetGraphique = 0 ;
} 
