#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdbool.h>

typedef struct {
    int valeur;
    int posX;
    int posY;
} *structCase;

typedef struct{
    structCase cellule;
}grille;

//appel des fonctions utilisées
    structCase **create_grille();
    structCase **add_case(structCase **grille, int val, int posX, int posY);
    structCase **rem_case(structCase **grille, int posX, int posY);
    void afficheGrille (structCase **grille);
    structCase **remplirGrille(structCase **grille);
    bool verifTab (structCase **grille,int xmin, int ymin, int xmax, int ymax);
    bool verifLigne (structCase **grille, int ligne);
    bool verifColonne (structCase **grille, int colonne);
    bool verifCarre (structCase **grille, int x, int y);
    bool verifGrille(structCase **grille);
#endif // SUDOKU_H_INCLUDED
