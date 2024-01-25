#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

#include <stdbool.h>

#define TAILLE 9
#define CARRE (int) sqrt(TAILLE)


typedef struct {
    int valeur;
    int posX;
    int posY;
    int note[TAILLE];
} structCellule;

typedef struct{
    structCellule **cellules;
} structGrille;

//appel des fonctions utilis�es
    int getValeur(structGrille grille, int x, int y);
    int getPosX(structGrille grille, int x, int y);
    int getPosY(structGrille grille, int x, int y);
    int getNote(structGrille grille, int x, int y, int ind);
    void setValeur(structGrille *grille, int x, int y, int val);
    void setPosX(structGrille *grille, int x, int y, int posX);
    void setPosY(structGrille *grille, int x, int y, int posY);
    void setNote(structGrille *grille, int x, int y, int ind, int note);

    structGrille create_grille();  
    structGrille initGrille(structGrille grille);
    structGrille add_case(structGrille grille, int val, int posX, int posY);
    structGrille rem_case(structGrille grille, int posX, int posY);
    void free_grille(structGrille *grille);
    void afficheGrille (structGrille grille);
    structGrille remplirGrille(structGrille grille);
    bool verifTab (structGrille grille,int xmin, int ymin, int xmax, int ymax);
    bool verifLigne (structGrille grille, int ligne);
    bool verifColonne (structGrille grille, int colonne);
    bool verifCarre (structGrille grille, int x, int y);
    bool verifGrille(structGrille grille);
    structGrille actualiseNotes(structGrille grille, int posX, int posY, int val);
    structGrille actualiseNotesZone(structGrille grille, int xmin, int ymin, int xmax, int ymax, int val);
    structGrille implanterNote(structGrille grille);
    structGrille regle1(structGrille grille, int xmin, int ymin, int xmax, int ymax);
    structGrille regle2(structGrille grille, int xmin, int ymin, int xmax, int ymax);
    structGrille calculerNotes(structGrille grille);

    bool sontDeuxPaires(structCellule cell1, structCellule cell2);
    void eliminerCandidats(structGrille* grille);
    void updateGrid(structGrille *grille);
    structGrille regle6(structGrille *grille);
    void afficherNotesCellule(structCellule cellule);

    void eliminerKupletsNus(structGrille *grille);
    bool sontDoubletsNus(structCellule cell1, structCellule cell2);
    structGrille regle9(structGrille *grille);
    bool trouveDoubletNu(structGrille *grille, int blockRow, int blockCol, int *row1, int *col1, int *row2, int *col2);


    #endif // SUDOKU_H_INCLUDED
