#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include <stdbool.h>
#include <math.h>

#define TAILLE 9
#define CARRE 3 //srt(TAILLE)


structCase **create_grille(){
    structCase **tableau = NULL;
    tableau = (structCase **)malloc(TAILLE * sizeof(struct structCase *));

for (int i=0; i<TAILLE; i++){
    tableau[i] = (structCase*)malloc(TAILLE * sizeof(structCase));
}
return tableau;

}

structCase **add_case(structCase **grille, int val, int posX, int posY){
    structCase new_case = (structCase)malloc(sizeof(structCase));
    new_case->valeur = val;
    new_case->posX = posX;
    new_case->posY = posY;
    grille[posX][posY] = new_case;
    return grille;
}

structCase **rem_case(structCase **grille, int posX, int posY){
     grille[posX][posY]->valeur = NULL;
     return grille;

}

void afficheGrille (structCase **grille){
    printf(" \n GRILLE : ");
    for (int i=0; i<TAILLE; i++){
        printf("\n");
        if (i==CARRE){
            printf("\n");
        }
        if (i==CARRE*2){
            printf("\n");
        }
        for (int j=0; j<TAILLE; j++){
            if (j==CARRE){
            printf(" ");
            }
            if (j==CARRE*2){
            printf(" ");
            }
            printf("|%d| ", grille[j][i]->valeur);
            //printf("(%d, ", grille[i][j]->posX);
            //printf("%d) ", grille[i][j]->posY);

        }
    }
}

structCase **remplirGrille(structCase **grille){

    for (int i=0; i<TAILLE; i++){
        for (int j=0; j<TAILLE; j++){
            grille = add_case(grille, rand() %10, i, j);
        }
    }
    return grille;
}

int getValeur(structCase c){
    return c->valeur;
}

bool verifTab (structCase **grille,int xmin, int ymin, int xmax, int ymax){
    int height = ymax - ymin +1;
    int width = xmax - xmin + 1;
    int length = height*width;
    bool tab[length];
    for (int i=0; i<length ; i++){
        tab[i]=false;
    }
    for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){
                if (tab[getValeur(grille[x][y])]==false)
                    tab[getValeur(grille[x][y])]=true;
                else return false;
            }
    }
    return true;

}

bool verifLigne (structCase **grille, int ligne){
    return verifTab(grille, 0, ligne, TAILLE-1, ligne);

}

bool verifColonne (structCase **grille, int colonne){
    return verifTab(grille, colonne, 0, colonne, TAILLE-1);

}

bool verifCarre (structCase **grille, int x, int y){
    return verifTab(grille, x, y, x + CARRE-1, y + CARRE-1);

}

bool verifGrille(structCase **grille){
    for (int i=0; i<TAILLE; i++){
        if (verifLigne(grille, i)){
            printf("true %d", i);

        }
        else return true;
    }

    for (int j=0; j<TAILLE; j++){
        if (verifColonne(grille, j)){
            printf("true %d", j);
        }
        else return false;
    }


    for (int i=0; i <TAILLE; i=i+CARRE){
        for (int j=0; j <TAILLE; j=j+CARRE){
            if (verifCarre(grille, i, j)){
                printf("true %d %d", i, j);
        }
        else return false;

    }
    }
    return true;
}
