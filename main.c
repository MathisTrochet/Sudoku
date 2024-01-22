#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include "ExempleModelesSudoku.h"
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main()
{

    /*

    srand( time( NULL ) );

    structGrille grille0 = create_grille();
    grille0 = initGrille(grille0);


//GRILLE JUSTE

grille0 = add_case(grille0, 7, 0, 0);
grille0 = add_case(grille0, 9, 1, 0);
grille0 = add_case(grille0, 8, 2, 0);
grille0 = add_case(grille0, 1, 3, 0);
grille0 = add_case(grille0, 6, 4, 0);
grille0 = add_case(grille0, 2, 5, 0);
grille0 = add_case(grille0, 3, 6, 0);
grille0 = add_case(grille0, 5, 7, 0);
grille0 = add_case(grille0, 4, 8, 0);

grille0 = add_case(grille0, 6, 0, 1);
grille0 = add_case(grille0, 4, 1, 1);
grille0 = add_case(grille0, 5, 2, 1);
grille0 = add_case(grille0, 7, 3, 1);
grille0 = add_case(grille0, 8, 4, 1);
grille0 = add_case(grille0, 3, 5, 1);
grille0 = add_case(grille0, 2, 6, 1);
grille0 = add_case(grille0, 1, 7, 1);
grille0 = add_case(grille0, 9, 8, 1);

grille0 = add_case(grille0, 1, 0, 2);
grille0 = add_case(grille0, 3, 1, 2);
grille0 = add_case(grille0, 2, 2, 2);
grille0 = add_case(grille0, 4, 3, 2);
grille0 = add_case(grille0, 9, 4, 2);
grille0 = add_case(grille0, 5, 5, 2);
grille0 = add_case(grille0, 6, 6, 2);
grille0 = add_case(grille0, 8, 7, 2);
grille0 = add_case(grille0, 7, 8, 2);

grille0 = add_case(grille0, 5, 0, 3);
grille0 = add_case(grille0, 2, 1, 3);
grille0 = add_case(grille0, 4, 2, 3);
grille0 = add_case(grille0, 3, 3, 3);
grille0 = add_case(grille0, 1, 4, 3);
grille0 = add_case(grille0, 9, 5, 3);
grille0 = add_case(grille0, 7, 6, 3);
grille0 = add_case(grille0, 6, 7, 3);
grille0 = add_case(grille0, 8, 8, 3);

grille0 = add_case(grille0, 8, 0, 4);
grille0 = add_case(grille0, 7, 1, 4);
grille0 = add_case(grille0, 1, 2, 4);
grille0 = add_case(grille0, 2, 3, 4);
grille0 = add_case(grille0, 4, 4, 4);
grille0 = add_case(grille0, 6, 5, 4);
grille0 = add_case(grille0, 9, 6, 4);
grille0 = add_case(grille0, 3, 7, 4);
grille0 = add_case(grille0, 5, 8, 4);

grille0 = add_case(grille0, 3, 0, 5);
grille0 = add_case(grille0, 6, 1, 5);
grille0 = add_case(grille0, 9, 2, 5);
grille0 = add_case(grille0, 5, 3, 5);
grille0 = add_case(grille0, 7, 4, 5);
grille0 = add_case(grille0, 8, 5, 5);
grille0 = add_case(grille0, 4, 6, 5);
grille0 = add_case(grille0, 2, 7, 5);
grille0 = add_case(grille0, 1, 8, 5);

grille0 = add_case(grille0, 4, 0, 6);
grille0 = add_case(grille0, 8, 1, 6);
grille0 = add_case(grille0, 3, 2, 6);
grille0 = add_case(grille0, 9, 3, 6);
grille0 = add_case(grille0, 2, 4, 6);
grille0 = add_case(grille0, 1, 5, 6);
grille0 = add_case(grille0, 5, 6, 6);
grille0 = add_case(grille0, 7, 7, 6);
grille0 = add_case(grille0, 6, 8, 6);

grille0 = add_case(grille0, 9, 0, 7);
grille0 = add_case(grille0, 5, 1, 7);
grille0 = add_case(grille0, 6, 2, 7);
grille0 = add_case(grille0, 8, 3, 7);
grille0 = add_case(grille0, 3, 4, 7);
grille0 = add_case(grille0, 7, 5, 7);
grille0 = add_case(grille0, 1, 6, 7);
grille0 = add_case(grille0, 4, 7, 7);
grille0 = add_case(grille0, 2, 8, 7);

grille0 = add_case(grille0, 2, 0, 8);
grille0 = add_case(grille0, 1, 1, 8);
grille0 = add_case(grille0, 7, 2, 8);
grille0 = add_case(grille0, 6, 3, 8);
grille0 = add_case(grille0, 5, 4, 8);
grille0 = add_case(grille0, 4, 5, 8);
grille0 = add_case(grille0, 8, 6, 8);
grille0 = add_case(grille0, 9, 7, 8);
grille0 = add_case(grille0, 3, 8, 8);


//GRILLE FACILE  
*/

structGrille grille1 = create_grille();
grille1 = initGrille(grille1);
 
grille1 = add_case(grille1, 6, 1, 0);
grille1 = add_case(grille1, 8, 2, 0);
grille1 = add_case(grille1, 9, 3, 0);
grille1 = add_case(grille1, 1, 4, 0);
grille1 = add_case(grille1, 4, 6, 0);

grille1 = add_case(grille1, 3, 0, 1);
grille1 = add_case(grille1, 4, 1, 1);
grille1 = add_case(grille1, 2, 2, 1);
grille1 = add_case(grille1, 7, 5, 1);

grille1 = add_case(grille1, 7, 2, 2);
grille1 = add_case(grille1, 8, 7, 2);

grille1 = add_case(grille1, 4, 3, 3);
grille1 = add_case(grille1, 7, 4, 3);
grille1 = add_case(grille1, 9, 5, 3);
grille1 = add_case(grille1, 3, 7, 3);

grille1 = add_case(grille1, 4, 2, 4);
grille1 = add_case(grille1, 2, 5, 4);
grille1 = add_case(grille1, 9, 7, 4);

grille1 = add_case(grille1, 1, 1, 5);
grille1 = add_case(grille1, 7, 6, 5);
grille1 = add_case(grille1, 4, 8, 5);

grille1 = add_case(grille1, 2, 1, 6);
grille1 = add_case(grille1, 3, 3, 6);
grille1 = add_case(grille1, 4, 4, 6);
grille1 = add_case(grille1, 7, 7, 6);

grille1 = add_case(grille1, 4, 0, 7);
grille1 = add_case(grille1, 9, 4, 7);
grille1 = add_case(grille1, 1, 5, 7);
grille1 = add_case(grille1, 2, 6, 7);
grille1 = add_case(grille1, 6, 8, 7);

grille1 = add_case(grille1, 8, 0, 8);
grille1 = add_case(grille1, 1, 2, 8);
grille1 = add_case(grille1, 2, 4, 8);
grille1 = add_case(grille1, 6, 5, 8);
grille1 = add_case(grille1, 3, 6, 8);
grille1 = add_case(grille1, 4, 7, 8);
grille1 = add_case(grille1, 9, 8, 8);

int *tab;
tab = occurenceParIndice(grille1, 0, 0, 2, 2);

printf(" ||| ");
for(int i=0; i<TAILLE; i++){
    printf("%d", tab[i]);
}
printf(" ||| ");

int * tab2 = potentiel_k_uplet(tab, 2); // les dernier argument est 2 car on s'occupe ici de double (correspond à k)

for(int i=0; i<TAILLE; i++){
    printf("%d", tab2[i]);
}

int *coordonateTab = calculCoordonateTab(grille1, 0, 0, 2, 2, tab2);

printf(" || ");
for(int i=0; i<=( coordonateTab[0]*3 ); i++){
    printf("%d", coordonateTab[i]);
}
printf(" || ");

if (is_k_uplets_cachés(coordonateTab, 2)==true){
    printf("true");
}
else  printf("false");



//GRILLE MOYENNE 

 /*
structGrille grille2 = create_grille();

grille2 = initGrille(grille2);


grille2 = add_case(grille2, 9, 1, 0);

grille2 = add_case(grille2, 2, 0, 1);
grille2 = add_case(grille2, 1, 1, 1);
grille2 = add_case(grille2, 5, 7, 1);
grille2 = add_case(grille2, 7, 8, 1);

grille2 = add_case(grille2, 7, 0, 2);
grille2 = add_case(grille2, 5, 1, 2);
grille2 = add_case(grille2, 3, 2, 2);
grille2 = add_case(grille2, 2, 3, 2);
grille2 = add_case(grille2, 6, 7, 2);
grille2 = add_case(grille2, 1, 8, 2);

grille2 = add_case(grille2, 7, 2, 3);
grille2 = add_case(grille2, 9, 4, 3);
grille2 = add_case(grille2, 1, 6, 3);
grille2 = add_case(grille2, 3, 7, 3);
grille2 = add_case(grille2, 6, 8, 3);

grille2 = add_case(grille2, 8, 3, 4);
grille2 = add_case(grille2, 1, 4, 4);
grille2 = add_case(grille2, 7, 7, 4);

grille2 = add_case(grille2, 5, 0, 5);
grille2 = add_case(grille2, 2, 4, 5);
grille2 = add_case(grille2, 9, 8, 5);

grille2 = add_case(grille2, 4, 3, 6);
grille2 = add_case(grille2, 7, 6, 6);
grille2 = add_case(grille2, 3, 8, 6);

grille2 = add_case(grille2, 7, 3, 7);
grille2 = add_case(grille2, 6, 5, 7);

grille2 = add_case(grille2, 4, 2, 8);
grille2 = add_case(grille2, 8, 4, 8);
grille2 = add_case(grille2, 1, 7, 8);


int *tab;
tab = occurenceParIndice(grille2, 0, 6, 2, 8);
printf(" ||| ");
for(int i=0; i<TAILLE; i++){
    printf("%d", tab[i]);
}
printf(" ||| ");

int * tab2 = potentiel_k_uplet(grille2, 0, 6, 2, 8, tab, 2);
for(int i=0; i<TAILLE; i++){
    printf("%d", tab2[i]);
}
*/
 /*

// grille DIFFICILE 

structGrille grille3 = create_grille(); 
grille3 = initGrille(grille3);

grille3 = add_case(grille3, 7, 1, 0);
grille3 = add_case(grille3, 2, 5, 0);
grille3 = add_case(grille3, 5, 8, 0);
grille3 = add_case(grille3, 9, 0, 2);
grille3 = add_case(grille3, 4, 5, 2);
grille3 = add_case(grille3, 8, 7, 2);
grille3 = add_case(grille3, 3, 2, 3);
grille3 = add_case(grille3, 2, 3, 3);
grille3 = add_case(grille3, 5, 7, 3);
grille3 = add_case(grille3, 6, 3, 4);
grille3 = add_case(grille3, 3, 4, 4);
grille3 = add_case(grille3, 2, 0, 5);
grille3 = add_case(grille3, 9, 5, 5);
grille3 = add_case(grille3, 1, 7, 5);
grille3 = add_case(grille3, 9, 2, 6);
grille3 = add_case(grille3, 4, 4, 6);
grille3 = add_case(grille3, 6, 5, 6);
grille3 = add_case(grille3, 7, 8, 6);
grille3 = add_case(grille3, 3, 0, 7);
grille3 = add_case(grille3, 6, 8, 7);
grille3 = add_case(grille3, 8, 0, 8);
grille3 = add_case(grille3, 5, 5, 8);
grille3 = add_case(grille3, 4, 8, 8);


                                                                                        //GRILLE COMPLETE (grille0) - vérifier

    bool isValid = verifGrille(grille0); 
    if (isValid) {printf("Grille0 -> Valide");} else printf("Grille0 -> Non valide ");


 */

                                                                                           //GRILLE FACILE (grille1) - résoudre

    printf("GRILLE FACILE : \n\n AVANT :\n");

    afficheGrille(grille1);


    grille1 = implanterNote(grille1);


    printf("\n\n APRES :\n");

    afficheGrille(grille1);
/*


    printf("\n\n[0][0] -> |"); // tableau de note pour la premiere case
    for(int i=0; i<TAILLE ; i++){
        

        printf("%d", getNote(grille1, 0, 0, i));
        

    }
    printf("|");

 


*/
/*
                                                                                         //GRILLE MOYENNE (grille2) - résoudre
    printf("\n\nGRILLE MOYENNE \n\nAVANT :\n");
    afficheGrille(grille2);

    //grille2 = implanterNote(grille2);

    printf("\n\n APRES \n");

    afficheGrille(grille2);

    printf("\n\n[0][0] -> |");

    for(int i=0; i<TAILLE ; i++){
        
        printf("%d", getNote(grille2, 0, 0, i));
        
    }

    printf("|");


          /*                                                                               //GRILLE DIFFICILE (grille3) - résoudre 
    printf("\n\nGRILLE DIFFICILE \n\nAVANT :\n");
    afficheGrille(grille3);

    grille3 = implanterNote(grille3);

    printf("\n\n APRES \n");

    afficheGrille(grille3);

    printf("\n\n[0][0] -> |");

    for(int i=0; i<TAILLE ; i++){
        
        printf("%d", getNote(grille3, 0, 0, i));
        
    }

    printf("| \n");

*/
/*
structGrille grille4 = create_grille();  // GRILLE CAS N°2
grille4 = initGrille(grille4);

grille4 = add_case(grille4, 8, 2, 3);
grille4 = add_case(grille4, 8, 4, 6);
grille4 = add_case(grille4, 6, 1, 7);
grille4 = add_case(grille4, 1, 1, 8);
grille4 = add_case(grille4, 9, 0, 8);
grille4 = add_case(grille4, 7, 1, 0);
grille4 = add_case(grille4, 7, 2, 4);

//grille4 = regle2(grille4, 0, 6, 2, 8);

grille4 = calculerRegle2et8(grille4);
grille4 = calculerRegle2et8(grille4);


grille4 = implanterNote(grille4);

afficheGrille(grille4);
for(int i = 0; i<=2; i++){
    
    for (int j=6; j<=8; j++){
        printf("\n|");
        for(int k=0; k<9; k++){
            
            printf("%d", getNote(grille4, i, j, k));
        }
        printf("|");
    }
    
}
*/

structGrille grille5 = create_grille();
grille5 = initGrille(grille5);

grille5 = add_case(grille5, 9, 2, 0);
grille5 = add_case(grille5, 3, 4, 0);
grille5 = add_case(grille5, 2, 5, 0);
grille5 = add_case(grille5, 7, 3, 1);
grille5 = add_case(grille5, 1, 0, 2);
grille5 = add_case(grille5, 6, 1, 2);
grille5 = add_case(grille5, 2, 2, 2);
grille5 = add_case(grille5, 1, 1, 3);
grille5 = add_case(grille5, 2, 4, 3);
grille5 = add_case(grille5, 5, 6, 3);
grille5 = add_case(grille5, 6, 7, 3);
grille5 = add_case(grille5, 9, 3, 4);
grille5 = add_case(grille5, 5, 1, 5);

grille5 = add_case(grille5, 1, 6, 5);
grille5 = add_case(grille5, 7, 8, 5);
grille5 = add_case(grille5, 4, 6, 6);
grille5 = add_case(grille5, 3, 8, 6);
grille5 = add_case(grille5, 2, 1, 7);


grille5 = add_case(grille5, 6, 2, 7);
grille5 = add_case(grille5, 9, 5, 7);
grille5 = add_case(grille5, 5, 2, 8);
grille5 = add_case(grille5, 8, 3, 8);
grille5 = add_case(grille5, 7, 4, 8);




afficheGrille(grille5);

int *tab_2;
tab_2 = occurenceParIndice(grille5, 0, 3, 2, 5);

printf(" ||| ");
for(int i=0; i<TAILLE; i++){
    printf("%d", tab_2[i]);
}
printf(" ||| ");

int * tab2_2 = potentiel_k_uplet(tab_2, 2); // les dernier argument est 2 car on s'occupe ici de double (correspond à k)

for(int i=0; i<TAILLE; i++){
    printf("%d", tab2_2[i]);
}

int *coordonateTab_2 = calculCoordonateTab(grille5, 0, 0, 2, 2, tab2_2);

printf(" || ");
for(int i=0; i<=( coordonateTab_2[0]*3 ); i++){
    printf("%d", coordonateTab_2[i]);
}
printf(" || ");

if (is_k_uplets_cachés(coordonateTab_2, 2)==true){
    printf("true");
}

else  printf("false");




/*
free_grille(&grille0);
free_grille(&grille1);
free_grille(&grille2);
free_grille(&grille3);
*/
//free_grille(&grille4);





return EXIT_SUCCESS;

}
