#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdbool.h>

typedef struct {
    int valeur;
    int posX;
    int posY; /*
    int proba_1;
    int proba_2;
    int proba_3;
    int proba_4;
    int proba_5;
    int proba_6;
    int proba_7;
    int proba_8;
    int proba_9;
    */
} *structCase;

typedef struct{
    structCase cellule;
}grille;

//appel des fonctions utilis�es
    structCase **create_grille();
    structCase **add_case(structCase **grille, int val, int posX, int posY);
    structCase **rem_case(structCase **grille, int posX, int posY);
    void afficheGrille (structCase **grille);
    structCase **initGrille(structCase **grille);
    //void initGrille(structCase ***grille);
    structCase **remplirGrille(structCase **grille);
    bool verifTab (structCase **grille,int xmin, int ymin, int xmax, int ymax);
    bool verifLigne (structCase **grille, int ligne);
    bool verifColonne (structCase **grille, int colonne);
    bool verifCarre (structCase **grille, int x, int y);
    bool verifGrille(structCase **grille);
    structCase **regle1(structCase **grille, int xmin, int ymin, int xmax, int ymax);

    #endif // SUDOKU_H_INCLUDED
