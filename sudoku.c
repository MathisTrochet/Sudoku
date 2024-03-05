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

structGrille cachee(structGrille grille, int xmin, int ymin, int xmax, int ymax){
    int compteur=0;
    int posX=xmax; // si 8 n'a pas été trouvé dans les 8 autres cases, alors il est forcement dans la derniere. Donc on l'initialise ici.
    int posY=ymax;
    int val;
    int tab[TAILLE];

    for (int x = xmin ; x<=xmax ; x++){
            for (int y=ymin ; y<=ymax ; y++){
                for (int z=0; z<TAILLE; z++){
                    if (getNote(grille, x, y, val-1)==1){
                        tab[z]++; //on augmente d'un
                    }
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
   return grille;
}

//parcours du carré + 2 notes(grille): (note1 x note2)
int *occurrenceParIndice(structGrille grille, int xmin, int ymin, int xmax, int ymax){

    int *tab = (int*)malloc(TAILLE * sizeof(int));
    for(int i=0; i<TAILLE; i++){
        tab[i]=0;
    }

    for (int x = xmin ; x<=xmax ; x++){
        for (int y=ymin ; y<=ymax ; y++){
            for (int z=0; z<TAILLE; z++){
                if (getNote(grille, x, y, z)==1){
                    tab[z]++; //on augmente d'un pour calculer l'occurrence de l'indice z
                }
            }
    
        }
    }
    
    return tab;
    
}

int * potentiel_k_uplet(int *tab, int k){ //si tab[0] != k on arrete tout c'est pas la peine 
    int *returnTab = (int*)malloc(TAILLE * sizeof(int));
    int ind=1;
    for(int i=0; i<TAILLE; i++){
        if (tab[i] == k){
            returnTab[ind] = i+1; // stock le potentiel element de la paire
            ind++;
            returnTab[0] = ind-1; // on place en premier le nombre de valeurs trouvés
        }
    }
    
    return returnTab; // retourne toutes les éléments faisant parti du k-uplets
}

void afficherNotesCellule(structCellule cellule) {
    printf("Notes de la cellule :\n");
    for (int i = 0; i < TAILLE; i++) {
        if (cellule.note[i]) {
            printf("%d ", i + 1); // Afficher la possibilité (ajouter 1 car les indices commencent à 0)
        }
    }
    printf("\n");
}

/*****************************************************************************************************************/
//PAIRES ET TRIPLETS CACHEES

// teste si une paire est présente ou non dans les cases d'une zone

// renvoie un tableau avec un booleen : 0 si (a,b) n'est pas dans la case et 1 si (a,b) est dans la case
//et les coordonnées des cases
int *testPaireCachee(structGrille grille, int xmin, int ymin, int xmax, int ymax, int a, int b){
    int *testTab = (int*)malloc((TAILLE*3) * sizeof(int));
    for(int i = 0; i < TAILLE*3; i++){
        testTab[i] = 0;
    }
    int index = 0;

    for(int x = xmin; x <= xmax; x++){
        for(int y = ymin; y <= ymax; y++){
            if((getNote(grille, x, y, a-1) == 1) && (getNote(grille, x, y, b-1) == 1)){    
                testTab[index] = 1;     //le booleen
            }
            testTab[index+1] = x;       //première coordonnée de la case
            testTab[index+2] = y;       //deuxième coordonnée de la case
            index = index + 3;
        }
    }
    return testTab;
}

// vérifie à partir du tableau de test si un k_uplet est un k_uplet caché
bool is_a_k_uplet_cache(int *testTab, int k){
    int count = 0;
    int index = 0;

    for(int i = 0; i < TAILLE; i++){
        if(testTab[index] == 1){
            count++;
        }
        index = index + 3;
    }

    if(count == k){
        return true;
    }
    else{
        return false;
    }
}

//supprime dans une case toutes les notes qui ne correspondent pas à la paire
structGrille supprAutresQuePaires(structGrille grille, int x, int y, int a, int b){
    for(int i = 0; i < TAILLE; i++){
        if((i == a-1) || (i == b-1)){
            setNote(&grille, x, y, i, 1);
        }
        else{
            setNote(&grille, x, y, i, 0);
        }
    }
    return grille;
}

//fonction principale de la règle paires cachées
structGrille pairesCachees(structGrille grille){
    for(int x = 0; x <= (TAILLE - CARRE); x=x+CARRE){
        for(int y = 0; y <= (TAILLE - CARRE); y=y+CARRE){
            
            int *occ = occurrenceParIndice(grille, x, y, (x + CARRE -1), (y + CARRE-1)); //on récupère l'occurrence par indice des notes d'une zone

            for(int i = 1; i < TAILLE; i++){    
                if(occ[i-1] == 2){              //pour une première valeur on vérifie que son occurrence est égale à deux

                    for(int j = i+1; j <= TAILLE; j++){
                        if(occ[j-1] == 2){      //pour une seconde valeur on vérifie que son occurrence est aussi égale à deux
                    
                            int *testPaires = testPaireCachee(grille, x, y, (x + CARRE -1), (y + CARRE-1), i, j); //tableau de test pour savoir
                                                                                                                  //si le couple appartient ou non à des cases
                            bool verif = is_a_k_uplet_cache(testPaires, 2);    //on vérifie si le couple forme une paire cachée                                   

                            if(verif){
                                for(int k = 0; k < TAILLE*3; k=k+3){
                                    if(testPaires[k] == 1){
                                        supprAutresQuePaires(grille, testPaires[k+1], testPaires[k+2], i, j); //on supprime les autres notes de la case
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return grille;
}


// teste si un triplet est présent ou non dans les cases d'une zone

// renvoie un tableau avec un booleen : 0 si (a,b,c) n'est pas dans la case et 1 si (a,b,c) est dans la case
//et les coordonnées des cases
int *testTripleeCachee(structGrille grille, int xmin, int ymin, int xmax, int ymax, int a, int b, int c){
    int *testTab = (int*)malloc((TAILLE*3) * sizeof(int));
    for(int i = 0; i < TAILLE*3; i++){
        testTab[i] = 0;
    }
    int index = 0;

    for(int x = xmin; x <= xmax; x++){
        for(int y = ymin; y <= ymax; y++){

            //condition qui couvre le cas ou les 3 valeurs sont toutes présentes dans 3 cases de la zone
            if((getNote(grille, x, y, a-1) == 1) && (getNote(grille, x, y, b-1) == 1) && (getNote(grille, x, y, c-1) == 1)){   
                testTab[index] = 1;     //le booleen
            }
            //condition qui couvre le cas ou les 3 valeurs sont présentes 2 à deux dans 3 cases de la zone
            else if(((getNote(grille, x, y, a-1) == 1) && (getNote(grille, x, y, b-1) == 1))
                || ((getNote(grille, x, y, a-1) == 1) && (getNote(grille, x, y, c-1) == 1)) 
                || ((getNote(grille, x, y, b-1) == 1) && (getNote(grille, x, y, c-1) == 1))){
                testTab[index] = 1;     //le booleen
            }
            testTab[index+1] = x;       //première coordonnée de la case
            testTab[index+2] = y;       //deuxième coordonnée de la case
            index = index + 3;
        }
    }
    return testTab;
}

//supprime dans une case toutes les notes qui ne correspondent pas au triplet
structGrille supprAutresQueTriplets(structGrille grille, int x, int y, int a, int b, int c){
    for(int i = 0; i < TAILLE; i++){
        if((i == a-1) || (i == b-1) || (i == c-1)){
            setNote(&grille, x, y, i, 1);
        }
        else{
            setNote(&grille, x, y, i, 0);
        }
    }
    return grille;
}

//fonction principale de la règle paires cachées
//elle effectue quasiment le même traitement que la fonction paires cachées, à la différence que l'on a 3 valeurs
structGrille tripletsCaches(structGrille grille){
    for(int x = 0; x <= (TAILLE - CARRE); x=x+CARRE){
        for(int y = 0; y <= (TAILLE - CARRE); y=y+CARRE){
            
            int *occ = occurrenceParIndice(grille, x, y, (x + CARRE -1), (y + CARRE-1));

            for(int i = 1; i < TAILLE-1; i++){
                if((occ[i-1] == 2) || (occ[i-1] == 3)){ //on test l'occurrence de la première valeur qui doit apparaître une ou deux fois

                    for(int j = i+1; j < TAILLE; j++){
                        if(occ[j-1] == occ[i-1]){       //la deuxième valeur doit apparaître le même nombre de fois que la première

                            for(int k = j+1; k <= TAILLE; k++){
                                if(occ[k-1] == occ[i-1]){   //la troisième valeur doit apparaître le même nombre de fois que les deux autres

                                    //le reste du traitement est le même que pour les paires cachées
                                    int *testTriplet = testTripleeCachee(grille, x, y, (x + CARRE -1), (y + CARRE-1), i, j, k);
                                    bool verif = is_a_k_uplet_cache(testTriplet, 3);

                                    if(verif){
                                        for(int ind = 0; ind < TAILLE*3; ind=ind+3){
                                            if(testTriplet[ind] == 1){
                                                supprAutresQueTriplets(grille, testTriplet[ind+1], testTriplet[ind+2], i, j, k);
                                            }
                                        }
                                    }

                                }
                            }
                    
                        }
                    }
                }
            }
        }
    }
    return grille;
}

/**************************************************************************************************************/

//PAIRES ET TRIPLETS POINTANTS

//Fonction qui renvoie un tableau avec les coordonnées des cases dans lesquels on retrouve les potentiels pointants
int *coordPotentielsPointants(structGrille grille, int xmin, int ymin, int xmax, int ymax, int note, int k){
    int taille = 1 + k*2;

    int *potentielsPointants = (int*)malloc(taille * sizeof(int));
    potentielsPointants[0] = note;
    for(int i = 1; i < taille; i++){
        potentielsPointants[i] = 0;
    }

    int ind = 1;
    for(int x = xmin; x <= xmax; x++){
        for(int y = ymin; y <= ymax; y++){
            if(getNote(grille, x, y, note-1) == 1){
                potentielsPointants[ind] = x;
                potentielsPointants[ind + 1] = y;
                ind = ind + 2;
            }
        }
    }
    
    return potentielsPointants;
}

//Fonction qui vérifie si les instances de la valeur pouvant formées un k-uplet pointant sont sur la même ligne
//Tableau tabVal : - première case : la valeur
//                 - les autres cases : les coordonnées des cellules dans lesquelles on retrouve la note

bool verifLignePointants(int *tabVal, int k){
    int taille = 1 + k*2;
   
    bool areOnOneRow = false;

    for(int i = 2; i < taille-2; i=i+2){
        if(tabVal[i] == tabVal[i+2]){
            areOnOneRow = true;
        }
        else{
            areOnOneRow = false;
        }
    }

    return areOnOneRow;
}

//Fonction qui vérifie si les instances de la valeur pouvant formées un k-uplet pointant sont sur la même colonne
//Tableau tabVal : - première case : la valeur
//                 - les autres cases : les coordonnées des cellules dans lesquelles on retrouve la note
bool verifColonnePointants(int *tabVal, int k){
    int taille = 1 + k*2;

    bool areOnOneColumn = false;

    for(int i = 1; i < taille-3; i=i+2){
        if(tabVal[i] == tabVal[i+2]){
            areOnOneColumn = true;
        }
        else{
            areOnOneColumn = false;
        }
    }

    return areOnOneColumn;
}

//
structGrille supprAutresInstancesPointants(structGrille grille, int *tabVal, int k){
    int taille = 1 + k*2;
    int val = tabVal[0];

    if(verifLignePointants(tabVal, k)){
        int y = tabVal[2];                   //si les pointants sont sur la même ligne, ils ont le même y
        for(int x = 0; x < TAILLE; x++){
            bool setLigne = true;
            for(int i = 1; i < taille; i=i+2){
                if(x == tabVal[i]){
                    setLigne = false;
                }
            }
            if(setLigne){
                setNote(&grille, x, y, val-1, 0);
            }
        }

    }
    else{
        int x = tabVal[1];                  //si les pointants sont sur la même colonne, ils ont le même x
        for(int y = 0; y < TAILLE; y++){
            bool setColonne = true;
            for(int i = 2; i < taille; i=i+2){
                if(y == tabVal[i]){
                    setColonne = false;
                }
            }
            if(setColonne){
                setNote(&grille, x, y, val-1, 0);
            }
        }
    }
    return grille;
}

structGrille pairesEtTripletsPointants(structGrille grille){
    for(int x = 0; x <= (TAILLE - CARRE); x=x+CARRE){
        for(int y = 0; y <= (TAILLE - CARRE); y=y+CARRE){
            
            int *occ = occurrenceParIndice(grille, x, y, (x + CARRE -1), (y + CARRE-1));

            for(int i = 0; i < TAILLE; i++){
                for(int k = 2; k <= 3; k++){
                    if(occ[i] == k){
                        int *coord = coordPotentielsPointants(grille, x, y, (x + CARRE -1), (y + CARRE-1), i+1, k);
                        if(verifLignePointants(coord, k) || verifColonnePointants(coord, k)){
                            grille = supprAutresInstancesPointants(grille, coord, k);
                        }
                    }
                }
            }

        }
    }
    return grille;
}