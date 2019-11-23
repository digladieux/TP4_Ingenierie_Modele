#include "../header/MetaObjetGraphique.h"
#include "../header/MetaCercle.h"
#include "../header/MetaRectangle.h"
#include "../header/ObjetGraphique.h"
#include "../header/Cercle.h"
#include "../header/Rectangle.h"
#include <stdio.h>
#include <stdlib.h>

MetaObjectGraphique_ leMetaOG;
MetaCercle_ leMetaCercle;
MetaRectangle_ leMetaRectangle;

void initMeta() ;
void initOG() ;
void initCercle() ;
void initRectangle() ;

int main(void) {
    
    initMeta() ;
    initOG() ;
    printf("\n");
    initCercle() ;
    printf("\n");
    initRectangle() ;
}

void initOG() {
    ObjetGraphique_ * og ;
    og = leMetaOG.ConstructeurObjetGraphique() ;

    og->myClass->afficher(og) ;
    og->myClass ->setX(2, og) ;
    og->myClass ->setY(3, og) ;
    og->myClass->afficher(og) ;

    og->myClass->deplacer(og) ;
    og->myClass->afficher(og) ;
    
    og->myClass->effacer(og) ;

}

void initCercle() {
    Cercle_ * cercle ;
    cercle = leMetaCercle.ConstructeurCercle() ;
    
    cercle->superClasse.myClass->afficher((ObjetGraphique_*)cercle) ;
    cercle->myClass->superMetaClasse->setX(2, (ObjetGraphique_*)cercle) ;
    cercle->myClass->superMetaClasse->setY(3, (ObjetGraphique_*)cercle) ;
    cercle->myClass->setRayon(5,cercle) ;
    cercle->superClasse.myClass->afficher((ObjetGraphique_*)cercle) ;

    cercle->superClasse.myClass->deplacer((ObjetGraphique_*)cercle) ;
    cercle->superClasse.myClass->afficher((ObjetGraphique_*)cercle) ;

    cercle->myClass->superMetaClasse->effacer((ObjetGraphique_ *)cercle) ;
}

void initRectangle() {
    Rectangle_ * rectangle ;
    rectangle = leMetaRectangle.ConstructeurRectangle() ;
   
    rectangle->superClasse.myClass->afficher((ObjetGraphique_*)rectangle) ;
    rectangle->myClass->superMetaClasse->setX(2, (ObjetGraphique_*)rectangle) ;
    rectangle->myClass->superMetaClasse->setY(3, (ObjetGraphique_*)rectangle) ;
    rectangle->myClass->setHauteur(6,rectangle) ;
    rectangle->myClass->setLargeur(7,rectangle) ;
    rectangle->superClasse.myClass->afficher((ObjetGraphique_*)rectangle) ;

    rectangle->superClasse.myClass->deplacer((ObjetGraphique_*)rectangle) ;
    rectangle->superClasse.myClass->afficher((ObjetGraphique_*)rectangle) ;

    rectangle->myClass->superMetaClasse->effacer((ObjetGraphique_ *)rectangle) ;
}

void initMeta() {
    ConstructeurMetaObjetGraphique() ;
    ConstructeurMetaCercle() ;
    ConstructeurMetaRectangle() ;
}