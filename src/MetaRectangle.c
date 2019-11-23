#include "../header/MetaRectangle.h"
#include "../header/Rectangle.h"
#include "../header/MetaObjetGraphique.h"
#include <stdlib.h>
#include <stdio.h>

extern MetaObjectGraphique_ leMetaOG;
extern MetaRectangle_ leMetaRectangle;
  void afficherRectangle(Rectangle_* this) ;

 void setLargeur(int l, Rectangle_* this) {
     this->largeur = l ;
 }
 void setHauteur(int h, Rectangle_* this) {
     this->hauteur = h ;
 }
 int getLargeur(Rectangle_* this) {
     return this->largeur ;
 }
 int getHauteur(Rectangle_* this) {
     return this->hauteur ;
 }

  void afficherRectangle(Rectangle_* this) {
     printf("Afficher - Rectangle : x = %d, y = %d, Largeur = %d, Hauteur = %d\n", this->superClasse.x, this->superClasse.y, this->largeur, this->hauteur) ;
 }

 void effacerRectangle(Rectangle_ * this) {
     this->myClass = NULL ;
      free(this) ;
}
void deplacerRectangle(Rectangle_ * this) {
    this->superClasse.myClass->setX( this->superClasse.myClass->getX((ObjetGraphique_*) this) + RECTANGLE, (ObjetGraphique_*) this);
    this->superClasse.myClass->setY( this->superClasse.myClass->getY((ObjetGraphique_*) this) + RECTANGLE, (ObjetGraphique_*) this);
}
int getCentreXRectangle(Rectangle_ * this) {
    return this->superClasse.myClass->getX((ObjetGraphique_*)this) + this->largeur/2 ;
}
int getCentreYRectangle(Rectangle_ * this) {
    return this->superClasse.myClass->getY((ObjetGraphique_*)this) + this->largeur/2 ;
}

 /* constructeur de la classe */
 Rectangle_* ConstructeurRectangle(){
     Rectangle_* this = malloc(sizeof(Rectangle_)) ;
     this->hauteur = 0 ;
     this->largeur = 0 ;
     this->myClass = &leMetaRectangle ;
     this->superClasse = *leMetaOG.ConstructeurObjetGraphique() ;
     this->superClasse.type = RECTANGLE;
     return this ;
 }

void ConstructeurMetaRectangle() {
    leMetaRectangle.getHauteur = getHauteur ;
    leMetaRectangle.getLargeur = getLargeur ;
    leMetaRectangle.setHauteur = setHauteur ;
    leMetaRectangle.setLargeur = setLargeur ;
    leMetaRectangle.ConstructeurRectangle = ConstructeurRectangle ;
    leMetaRectangle.superMetaClasse = &leMetaOG ;
    leMetaOG.TVMafficher[RECTANGLE] = afficherRectangle ;
    leMetaOG.TVMdeplacer[RECTANGLE] = deplacerRectangle ;
    leMetaOG.TVMeffacer[RECTANGLE] = effacerRectangle ;
    leMetaOG.TVMgetCentreX[RECTANGLE] = getCentreXRectangle ;
    leMetaOG.TVMgetCentreY[RECTANGLE] = getCentreYRectangle ;
}
