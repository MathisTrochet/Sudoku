#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdbool.h>

#define TAILLE 9
#define CARRE 3 //srt(TAILLE)

typedef struct {
    int valeur;
    int posX;
    int posY;
    int note[TAILLE];
} structCase;

typedef struct{
    structCase cellule;
}grille;

//appel des fonctions utilis�es
    structCase **create_grille();  
    structCase **initGrille(structCase **grille);
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
    structCase **zonesActuNotes(structCase **grille, int posX, int posY, int val);
    structCase **actuNotesZoneApresAjout(structCase **grille, int xmin, int ymin, int xmax, int ymax, int val);
    structCase **regle1(structCase **grille, int xmin, int ymin, int xmax, int ymax);

    structCase **implanterNote(structCase **grille);


    #endif // SUDOKU_H_INCLUDED
