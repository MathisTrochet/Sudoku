#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h" 
#include <stdbool.h>
#include <math.h>


// getteurs et setteurs pour recuperer et placer des valeurs dans la grille

int getValeur(structGrille grille, int x, int y){
    return grille.cellules[x][y].valeur;
}
int getPosX(structGrille grille, int x, int y){
    return grille.cellules[x][y].posX;
}
int getPosY(structGrille grille, int x, int y){
    return grille.cellules[x][y].posY;
}
int getNote(structGrille grille, int x, int y, int ind){
    return grille.cellules[x][y].note[ind];
}

void setValeur(structGrille *grille, int x, int y, int val){
    (*grille).cellules[x][y].valeur = val;
}
void setPosX(structGrille *grille, int x, int y, int posX){
    (*grille).cellules[x][y].posX = posX;
}
void setPosY(structGrille *grille, int x, int y, int posY){
    (*grille).cellules[x][y].posY = posY;
}
void setNote(structGrille *grille, int x, int y, int ind, int note){
    (*grille).cellules[x][y].note[ind] = note;
}



structGrille create_grille(){
    structGrille grille;
    grille.cellules = (structCellule **)malloc(TAILLE * sizeof(structCellule *)); // alloue l'espace nécessaire pour chaque colonne

for (int x=0; x<TAILLE; x++){
    grille.cellules[x] = (structCellule*)malloc(TAILLE * sizeof(structCellule));  // alloue l'espace nécessaire pour chaque cellule de chaque colonne 
    for (int y=0; y< TAILLE; y++){
        setValeur(&grille, x, y, 0); //initialise valeurs à 0
        setPosX(&grille, x, y, x); // initialise posX à i
        setPosX(&grille, x, y, y); // initialise posY à j
    }
}
return grille;

}

structGrille add_case(structGrille grille, int val, int posX, int posY){
    setValeur(&grille, posX, posY, val);
    grille = actualiseNotes(grille, posX, posY, val); // met toutes les lignes colonnes et carrés communs à "val", à jour 
    return grille;
}

structGrille rem_case(structGrille grille, int posX, int posY){
     setValeur(&grille, posX, posY, 0);
     return grille;
}

void free_grille(structGrille *grille) {
    for (int x = 0; x < TAILLE; x++) {
        free(grille->cellules[x]);  // Libérer chaque ligne
    }
    free(grille->cellules);  // Libérer le tableau de pointeurs
}


void afficheGrille (structGrille grille){
    printf(" \n GRILLE : ");
    for (int x=0; x<TAILLE; x++){
        printf("\n");
        if (x==CARRE){
            printf("\n");
        }
        if (x==CARRE*2){
            printf("\n");
        }
        for (int y=0; y<TAILLE; y++){
            if (y==CARRE){
            printf(" ");
            }
            if (y==CARRE*2){
            printf(" ");
            }
            printf("|%d| ", getValeur(grille, y, x));
            //printf("(%d, ", grille[i][j]->posX);
            //printf("%d) ", grille[i][j]->posY);

        }
    }
}

structGrille initGrille(structGrille grille){ //initialise le tableau de notes

    for (int x=0; x<TAILLE; x++){
        for (int y=0; y<TAILLE; y++){
            //grille.cellules[x][y].valeur = 0; //(déjà fait dans la fonction create_grille)
            int *tab = (int*)malloc(TAILLE * sizeof(int));
            for (int k=0; k<TAILLE; k++){
                setNote(&grille, x, y, k, 1);
            }
        }
    }
    return grille;
}


structGrille remplirGrille(structGrille grille){

    for (int x=0; x<TAILLE; x++){
        for (int y=0; y<TAILLE; y++){
            grille = add_case(grille, rand() %10, x, y);
        }
    }
    return grille;
}




bool verifTab (structGrille grille,int xmin, int ymin, int xmax, int ymax){
    int height = ymax - ymin +1;
    int width = xmax - xmin + 1;
    int length = height*width;
    bool tab[length];
    int i;
    for (i=0; i<length ; i++){
        tab[i]=false;
    }
    for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){
                if (tab[getValeur(grille, x, y)-1]==false) {tab[getValeur(grille, x, y)-1]=true;}
            }
    }
    for (i=0; i<length; i++){
        if (tab[i]==false){
            return false;
        }
    }
    return true;

}

bool verifLigne (structGrille grille, int ligne){
    return verifTab(grille, 0, ligne, TAILLE-1, ligne);

}

bool verifColonne (structGrille grille, int colonne){
    return verifTab(grille, colonne, 0, colonne, TAILLE-1);

}

bool verifCarre (structGrille grille, int x, int y){
    return verifTab(grille, x, y, x + CARRE-1, y + CARRE-1);

}

bool verifGrille(structGrille grille){
    for (int x=0; x<TAILLE; x++){   // si une ligne n'est pas complete alors veriGrille -> false
        if (!verifLigne(grille, x)){
            return false;
        }
        
    }

    for (int y=0; y<TAILLE; y++){  // si une colonne n'est pas complete alors veriGrille -> false
        if (!verifColonne(grille, y)){
            return false;
        }
        
    }


    for (int x=0; x<TAILLE; x=x+CARRE){  // si un carré n'est pas complet alors veriGrille -> false
        for (int y=0; y<TAILLE; y=y+CARRE){
            if (!verifCarre(grille, x, y)){
                return false;
            }
        }
    }

    return true; // si tout est complet alors grille complete donc true
}



structGrille actualiseNotes(structGrille grille, int posX, int posY, int val){
    //on actualise après un ajout de valeur les notes des lignes, colonnes et carré de la valeur en question

    //printf("|val = %d, x = %d, y = %d |", val, posX, posY); // bonne coordonnées

    //ligne 
    grille = actualiseNotesZone(grille, 0, posY, TAILLE-1, posY, val);

    //colonne
    grille = actualiseNotesZone(grille, posX, 0, posX, TAILLE-1, val);

    //carre 
    grille = actualiseNotesZone(grille, posX - posX%CARRE, posY - posY%CARRE, (posX - posX%CARRE) + CARRE -1, (posY - posY%CARRE) + CARRE -1, val);

    return grille;
}



structGrille actualiseNotesZone(structGrille grille, int xmin, int ymin, int xmax, int ymax, int val){
    structGrille nouvelleGrille = grille;
    //printf("|val = %d, xmin = %d,  ymin = %d, xmax = %d,  ymax = %d |", val, xmin, ymin, xmax, ymax); // bonne coordonnées

    //printf("|%d, %d|",xmax-xmin+1, ymax-ymin+1);
    int compteur=0;
    int compteur2=0;
    int posX=0;
    int posY=0;
    int nbcarreX;
    int nbcarreY;
     for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){

                
                
                if (getValeur(nouvelleGrille, x, y) == val){ //si val est 5, la condition change le tableau de note comme cela : [000010000]
                    for(int z=0; z<TAILLE; z++){
                        setNote(&nouvelleGrille, x, y, z, 0); // met tous les entiers du tableau "note" à 0     ex : [000000000] 
                    }
                    setNote(&nouvelleGrille, x, y, val-1, 1); // dans ce tableau de note, seul l'indice correspondant à la valeur traité sera mis à 1  ex: de [000000000] à [000010000]
                    
                }
                
                else setNote(&nouvelleGrille, x, y, val-1, 0); // l'indice du tableau de note correspondant à la valeur traité sera mis à 0 dans tous les tableaux de note pour | la ligne, la colonne et le carré | associé a la valeur traitée
                                                        // ex : tjrs pour val = 5, les autres tableaux de xMin à xMax auront : [111101111]
            }
            
     }

     
     
     
     return nouvelleGrille;
     
}

structGrille implanterNote(structGrille grille){
    
    for (int x=0; x<TAILLE ; x++){
        for (int y=0; y<TAILLE ; y++){
            int compteur=0;
            int val;
            for(int k=0; k<TAILLE; k++){
                
                
                if (getNote(grille, x, y, k)==1){
                    compteur++;
                    val = k+1;
                }
            }
            if (compteur==1 && getValeur(grille, x, y) ==0){ 
                setValeur(&grille, x, y, val);
                grille = actualiseNotes(grille,  x, y, val); // met toutes les lignes colonnes et carrés communs à la case "val", à jour 
                grille = implanterNote(grille); // rappelle la fonction pour recommencer autant de fois qu'on aura des valeurs prete à etre implanter 
                                                // (si tableau seulement de 0 avec un seul 1 alors, il est pret a etre implanté) ex: [000010000]
            }   
            

            
        }
    }
    return grille;
}




structGrille regle1(structGrille grille, int xmin, int ymin, int xmax, int ymax){ // premiere version qui correspond a la premiere regle du sudoku
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

                if (getValeur(grille, x, y) == 0){
                    resPosX = getPosX(grille, x, y);
                    resPosY = getPosY(grille, x, y); // on sauvegarde les positions de la valeur non définie
                    //printf("posY : %d", resPosX);
                }

                else // dans le tableau de booléean, on mets toutes les valeurs != de 0 a true
                { 
                    if (tab[ getValeur(grille, x, y) - 1 ]== false)
                    {
                        tab[ getValeur(grille, x, y) - 1 ]=true; 
                    }
                }
            }
    }

    for (int x=0; x<length; x++){
        if (tab[x] == false){
             printf("Nombre manquant : %d", x+1);
             setValeur(&grille, resPosX, resPosY, x+1);
        }
    }
    
    
    return grille;
}

structGrille regle2et8(structGrille grille, int xmin, int ymin, int xmax, int ymax){
    int compteur=0;
    int posX=xmax; // si 8 n'a pas été trouvé dans les 8 autres cases, alors il est forcement dans la derniere. Donc on l'initialise ici.
    int posY=ymax;
    int val;

    for (int i=1; i<=TAILLE ; i++){
        val = i;
        compteur=0; // on reset 
        for (int x = xmin ; x<=xmax ; x++){
                for (int y=ymin ; y<=ymax ; y++){

                        if (getNote(grille, x, y, val-1)==0){
                            compteur++;
                        }
                        else{   //getNote(grille, x, y, val-1)==1
                            posX = x; //getPosX(grille, x, y);
                            posY = y; // getPosY(grille, x, y);
                        }
                        
                    if (compteur == 8 && getValeur(grille, posX, posY)==0){
                        printf("B");
                        
                        printf("|%d, %d, %d|", val, posX, posY);

                        for (int i=0; i<TAILLE; i++){
                            
                            setNote(&grille, posX, posY, i, 0);
                        }
                        setNote(&grille, posX, posY, val-1, 1);            
                    }

                }
                
        }
    }
    return grille;

}

structGrille calculerRegle2et8(structGrille grille){ //question : dans l'exemple que j'ai fait 
    int posX=0;
    int posY=0;
    for (int i=posX; i<TAILLE; i=i+CARRE){
        for (int j=posY; j<TAILLE ; j=j+CARRE){
            regle2et8(grille, i - i%CARRE, j - j%CARRE, (i - i%CARRE) + CARRE -1, (j - j%CARRE) + CARRE -1);
        }
        
    }
    //grille = regle2(grille, 0, 6, 2, 8);
    return grille;
}

//parcours du carré + 2 notes(grille): (note1 x note2)
structGrille FindTWo(structGrille grille){
    
}

//compare les 2 notes de 2 cellules
structGrille CompareTwo(int *x, int *y){

}

//supprime les 2 notes dans le carré
structGrille Supr(structGrille grille){

}

structGrille regle6(structGrille grille){
}
