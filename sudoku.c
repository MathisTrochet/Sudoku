#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h" 
#include <stdbool.h>
#include <math.h>





structCase **create_grille(){
    structCase **grille = (structCase **)malloc(TAILLE * sizeof(structCase *));

for (int i=0; i<TAILLE; i++){
    grille[i] = (structCase*)malloc(TAILLE * sizeof(structCase));
    for (int j=0; j< TAILLE; j++){
        grille[i][j].valeur = 0;
        grille[i][j].posX = i;
        grille[i][j].posY = j;
    }
}
return grille;

}

structCase **add_case(structCase **grille, int val, int posX, int posY){
    grille[posX][posY].valeur = val;
    grille = zonesActuNotes(grille, posX, posY, val); // met toutes les lignes colonnes et carrés communs à "val", à jour 
    return grille;
}

structCase **rem_case(structCase **grille, int posX, int posY){
     grille[posX][posY].valeur = 0;
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
            printf("|%d| ", grille[j][i].valeur);
            //printf("(%d, ", grille[i][j]->posX);
            //printf("%d) ", grille[i][j]->posY);

        }
    }
}

structCase ** initGrille(structCase **grille){

    for (int i=0; i<TAILLE; i++){
        for (int j=0; j<TAILLE; j++){
            //grille[i][j].valeur = 0; (déjà fait dans la fonction create_grille)
            int *tab = (int*)malloc(TAILLE * sizeof(int));
            for (int k=0; k<TAILLE; k++){
                tab[k]=1;
                grille[i][j].note[k]= tab[k];
            }
        }
    }
    return grille;
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
    return c.valeur;
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
structCase **zonesActuNotes(structCase **grille, int posX, int posY, int val){
    //on actualise après un ajout de valeur les notes des lignes, colonnes et carré de la valeur en quesiton


    //ligne 
    grille = actuNotesZoneApresAjout(grille, 0, posY, TAILLE-1, posY, val);
    //printf("test");
    //colonne
    grille = actuNotesZoneApresAjout(grille, posX, 0, posX, TAILLE-1, val);
    //carre 
    grille = actuNotesZoneApresAjout(grille, posX - posX%CARRE, posY - posY%CARRE, (posX - posX%CARRE) + CARRE -1, (posY - posY%CARRE) + CARRE -1, val);

    return grille;
}

structCase **actuNotesZoneApresAjout(structCase **grille, int xmin, int ymin, int xmax, int ymax, int val){
    //printf("xmin : %d, ymin : %d, xmax : %d, ymax : %d, val : %d", xmin, ymin, xmax, ymax, val); a enlever (pour test)

     for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){
                if (grille[x][y].valeur == val){
                    for(int i=0; i<TAILLE; i++){
                        grille[x][y].note[i] = 0;
                    }
                    
                    grille[x][y].note[val-1] = 1;
                    
                   
                }
                
                else grille[x][y].note[val-1] = 0;

            if (x == 0 && y ==0 && grille[0][0].valeur==0){
                printf("test");
            }
                

            }
            
     }
     return grille;
     
}

structCase **implanterNote(structCase **grille){
    
    for (int i=0; i<TAILLE ; i++){
        for (int j=0; j<TAILLE ; j++){
            int compteur=0;
            int val;
            for(int k=0; k<TAILLE; k++){
                
                
                if (grille[i][j].note[k]==1){
                    compteur++;
                    val = k+1;
                }
            }
            if (compteur==1 && grille[i][j].valeur ==0){
                grille[i][j].valeur=val;
                grille = zonesActuNotes(grille,  i, j, val); // met toutes les lignes colonnes et carrés communs à la case "val", à jour 
                grille = implanterNote(grille); //
            }

            
        }
    }
    return grille;
}




structCase **regle1(structCase **grille, int xmin, int ymin, int xmax, int ymax){ // premiere version qui correspond a la prmiere regle du sudoku
    int height = ymax - ymin +1;
    int width = xmax - xmin + 1;
    int length = height*width ;
    bool tab[length]; // dans les cas testé length sera 9 
    for (int i = 0; i < length; i++) {
        tab[i] = false;
    }
    int resPosX, resPosY;
    
    for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){

                    if (getValeur(grille[x][y]) == 0){
                    resPosX = (grille[x][y]).posX;
                    resPosY = (grille[x][y]).posY; // on sauvegarde les positions de la valeur non définie
                }
                else // dans le tableau de booléean, on mets toutes les valeurs != de 0 a true
                { 
                    if (tab[getValeur(grille[x][y])-1]== false)
                    {
                        tab[getValeur(grille[x][y])-1]=true; 
                    }
                }
            }
    }

    for (int i=0; i<length; i++){
        if (tab[i] == false){
             printf("Nombre manquant : %d", i+1);
             grille[resPosX][resPosY].valeur = (i+1);
             
        }
    }
    
    return grille;
}