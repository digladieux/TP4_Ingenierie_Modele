#include "../header/MetaCercle.h"
#include "../header/MetaObjetGraphique.h"
#include <stdlib.h>
#include <stdio.h>

extern MetaCercle_ leMetaCercle;
extern MetaObjectGraphique_ leMetaOG;
 void afficherCercle(Cercle_* this) ;
 void setRayon( int r, Cercle_* this) {
     this->rayon = r ;
 }
 int getRayon(Cercle_* this) {
     return this->rayon ;
 }

 void afficherCercle(Cercle_* this) {
     printf("Afficher - Cercle : x = %d, y = %d, Rayon = %d\n", this->superClasse.x, this->superClasse.y, this->rayon) ;
 }


  void effacerCercle(Cercle_ * this) {
      this->myClass = NULL ;
      free(this) ;
}
void deplacerCercle(Cercle_ * this) {
    this->superClasse.myClass->setX(this->superClasse.myClass->getX((ObjetGraphique_*) this) + CERCLE, (ObjetGraphique_*) this);
    this->superClasse.myClass->setY(this->superClasse.myClass->getY((ObjetGraphique_*) this) + CERCLE, (ObjetGraphique_*) this);
}
int getCentreXCercle(Cercle_ * this) {
    return this->myClass->superMetaClasse->getX((ObjetGraphique_ *)this) ;
}
int getCentreYCercle(Cercle_ * this) {
    return this->myClass->superMetaClasse->getY((ObjetGraphique_ *)this) ;

}
 /* constructeur de la classe */
 Cercle_* ConstructeurCercle(){
    Cercle_* this = malloc(sizeof(Cercle_)) ;
    this->rayon = 0 ;
    this->myClass = &leMetaCercle ;
    this->superClasse = *leMetaOG.ConstructeurObjetGraphique() ;
    this->superClasse.type = CERCLE;

    return this ;
 }

void ConstructeurMetaCercle() {
    leMetaCercle.ConstructeurCercle = ConstructeurCercle ;
    leMetaCercle.getRayon = getRayon ;
    leMetaCercle.setRayon = setRayon ;
    leMetaCercle.superMetaClasse = &leMetaOG ;
    leMetaOG.TVMafficher[CERCLE] = afficherCercle ;
    leMetaOG.TVMdeplacer[CERCLE] = deplacerCercle ;
    leMetaOG.TVMeffacer[CERCLE] = effacerCercle ;
    leMetaOG.TVMgetCentreX[CERCLE] = getCentreXCercle ;
    leMetaOG.TVMgetCentreY[CERCLE] = getCentreYCercle ;
}