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
    bool is_hiden;
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
    structGrille regle2et8(structGrille grille, int xmin, int ymin, int xmax, int ymax);
    structGrille calculerRegle2et8(structGrille grille);
    int *occurrenceParIndice(structGrille grille, int xmin, int ymin, int xmax, int ymax);
    int * potentiel_k_uplet(int *tab, int k);
    int *calculCoordonateTab(structGrille grille, int xmin, int ymin, int xmax, int ymax, int *returnTab);
    structCellule *tabPotentiellesBonneValeurs(structGrille grille, int xmin, int ymin, int xmax, int ymax, int *returnTab);

    bool is_k_uplets_caches(structGrille grille, structCellule *cellTab, int k);
    structGrille supprK(structGrille grille, structCellule *list, int xmin, int ymin, int xmax, int ymax, int k);
    void afficherNotesCellule(structCellule cellule);
    structGrille k_uplet_cache(structGrille grille, int k);

    int *testPaireCachee(structGrille grille, int xmin, int ymin, int xmax, int ymax, int a, int b);
    structGrille supprAutresQuePaires(structGrille grille, int x, int y, int a, int b);
    structGrille pairesCachees(structGrille grille);

    int *testTripleeCachee(structGrille grille, int xmin, int ymin, int xmax, int ymax, int a, int b, int c);
    bool is_a_k_uplet_cache(int *testTab, int k);
    structGrille tripletsCaches(structGrille grille);

    int *coordPotentielsPointants(structGrille grille, int xmin, int ymin, int xmax, int ymax, int note, int k);
    bool verifLignePointants(int *tabVal, int k);
    bool verifColonnePointants(int *tabVal, int k);
    structGrille supprAutresInstancesPointants(structGrille grille, int *tabVal, int k);
    structGrille pairesEtTripletsPointants(structGrille grille);

    #endif // SUDOKU_H_INCLUDED
