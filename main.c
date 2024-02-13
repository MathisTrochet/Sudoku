#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include "ExempleModelesSudoku.h"
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main()
{

    srand( time( NULL ) );
/*
    structGrille grille0 = create_grille();
    grille0 = initGrille(grille0);

    structGrille grille1 = create_grille();
    grille1 = initGrille(grille1);



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
 

//GRILLE MOYENNE 

 
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


 

                                                                                           //GRILLE FACILE (grille1) - résoudre

    printf("GRILLE FACILE : \n\n AVANT :\n");

    afficheGrille(grille1);


    grille1 = implanterNote(grille1);


    printf("\n\n APRES :\n");

    afficheGrille(grille1);



    printf("\n\n[0][0] -> |"); // tableau de note pour la premiere case
    for(int i=0; i<TAILLE ; i++){
        

        printf("%d", getNote(grille1, 0, 0, i));
        

    }
    printf("|");

 



                                                                                         //GRILLE MOYENNE (grille2) - résoudre
    printf("\n\nGRILLE MOYENNE \n\nAVANT :\n");
    afficheGrille(grille2);

    grille2 = implanterNote(grille2);

    printf("\n\n APRES \n");

    afficheGrille(grille2);

    printf("\n\n[0][0] -> |");

    for(int i=0; i<TAILLE ; i++){
        
        printf("%d", getNote(grille2, 0, 0, i));
        
    }

    printf("|");


                                                                                         //GRILLE DIFFICILE (grille3) - résoudre 
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



structGrille grille4 = create_grille();  // GRILLE CAS N°2
grille4 = initGrille(grille4);

grille4 = add_case(grille4, 8, 2, 3);
grille4 = add_case(grille4, 8, 4, 6);
grille4 = add_case(grille4, 6, 1, 7);
grille4 = add_case(grille4, 1, 1, 8);
grille4 = add_case(grille4, 9, 0, 8);

printf("GRILLE 4");
calculerNotes(grille4);
grille4 = implanterNote(grille4);
afficheGrille(grille4);
printf("|");
for (int i=0; i<TAILLE; i++){
    printf("%d", getNote(grille4, 0, 7, i));
}
printf("|");
*/

//******************************************//
//******************************************//

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

printf("\n\n----Grille d'exemple paire cachee----\n");
afficheGrille(grille5);


//grille teste regle 6
structGrille grille6 = create_grille(); 
grille6 = initGrille(grille6);
printf("\n");
printf("\n");
printf("GRILLE 6 ");
printf("\n");

grille6 = add_case(grille6, 8, 0, 0);
grille6 = add_case(grille6, 4, 1, 0);
grille6 = add_case(grille6, 2, 3, 0);
grille6 = add_case(grille6, 9, 7, 0);
grille6 = add_case(grille6, 1, 8, 0);

grille6 = add_case(grille6, 1, 3, 1);
grille6 = add_case(grille6, 6, 4, 1);
grille6 = add_case(grille6, 9, 5, 1);
grille6 = add_case(grille6, 4, 6, 1);
grille6 = add_case(grille6, 8, 8, 1);

grille6 = add_case(grille6, 1, 0, 2);
grille6 = add_case(grille6, 9, 2, 2);
grille6 = add_case(grille6, 4, 3, 2);
grille6 = add_case(grille6, 5, 7, 2);
grille6 = add_case(grille6, 7, 8, 2);

grille6 = add_case(grille6, 7, 0, 3);
grille6 = add_case(grille6, 1, 1, 3);
grille6 = add_case(grille6, 8, 2, 3);
grille6 = add_case(grille6, 3, 3, 3);
grille6 = add_case(grille6, 2, 4, 3);
grille6 = add_case(grille6, 4, 5, 3);
grille6 = add_case(grille6, 6, 7, 3);

grille6 = add_case(grille6, 2, 2, 4);
grille6 = add_case(grille6, 6, 5, 4);

grille6 = add_case(grille6, 1, 2, 6);
grille6 = add_case(grille6, 6, 3, 6);
grille6 = add_case(grille6, 9, 4, 6);
grille6 = add_case(grille6, 8, 7, 6);

grille6 = add_case(grille6, 9, 1, 7);
grille6 = add_case(grille6, 8, 3, 7);
grille6 = add_case(grille6, 1, 6, 7);

grille6 = add_case(grille6, 5, 0, 8);
grille6 = add_case(grille6, 8, 1, 8);
grille6 = add_case(grille6, 7, 3, 8);
grille6 = add_case(grille6, 4, 4, 8);
grille6 = add_case(grille6, 1, 5, 8);

reglePairesNus(&grille6);
afficheGrille(grille6);

structCellule cellule0 = grille6.cellules[2][0];
structCellule cellule1 = grille6.cellules[2][1]; 
structCellule cellule2 = grille6.cellules[2][2]; 
structCellule cellule3 = grille6.cellules[2][3]; 
structCellule cellule4 = grille6.cellules[2][4];
structCellule cellule5 = grille6.cellules[2][5]; 
structCellule cellule6 = grille6.cellules[2][6];
structCellule cellule7 = grille6.cellules[2][7]; 
structCellule cellule8 = grille6.cellules[2][8];

printf("\n");
afficherNotesCellule(cellule0);
afficherNotesCellule(cellule1);
afficherNotesCellule(cellule2);
afficherNotesCellule(cellule3);
afficherNotesCellule(cellule4);
afficherNotesCellule(cellule5);
afficherNotesCellule(cellule6);
afficherNotesCellule(cellule7);
afficherNotesCellule(cellule8);
//afficherNotesCellule(cellule9);

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

printf("\n----grille teste regle 7 - Triplets Nus----\n"); 
structGrille grille7 = create_grille(); 
grille7 = initGrille(grille7);
printf("\n\n");
printf("GRILLE 7 ");
printf("\n");

grille7 = add_case(grille7, 6, 0, 0);
grille7 = add_case(grille7, 5, 8, 0);

grille7 = add_case(grille7, 1, 3, 1);
grille7 = add_case(grille7, 6, 5, 1);
grille7 = add_case(grille7, 2, 6, 1);

grille7 = add_case(grille7, 3, 4, 2);
grille7 = add_case(grille7, 6, 7, 2);

grille7 = add_case(grille7, 4, 1, 3);
grille7 = add_case(grille7, 6, 3, 3);
grille7 = add_case(grille7, 9, 6, 3);
grille7 = add_case(grille7, 5, 7, 3);
grille7 = add_case(grille7, 2, 8, 3);

grille7 = add_case(grille7, 6, 1, 4);
grille7 = add_case(grille7, 9, 3, 4);
grille7 = add_case(grille7, 2, 4, 4);
grille7 = add_case(grille7, 4, 7, 4);

grille7 = add_case(grille7, 2, 1, 5);
grille7 = add_case(grille7, 9, 2, 5);
grille7 = add_case(grille7, 4, 3, 5);
grille7 = add_case(grille7, 5, 4, 5);
grille7 = add_case(grille7, 8, 6, 5);
grille7 = add_case(grille7, 6, 8, 5);

grille7 = add_case(grille7, 2, 0, 6);
grille7 = add_case(grille7, 6, 2, 6);
grille7 = add_case(grille7, 4, 5, 6);
grille7 = add_case(grille7, 5, 6, 6);

grille7 = add_case(grille7, 4, 0, 7);
grille7 = add_case(grille7, 8, 2, 7);
grille7 = add_case(grille7, 9, 5, 7);
grille7 = add_case(grille7, 6, 6, 7);
grille7 = add_case(grille7, 2, 7, 7);

grille7 = add_case(grille7, 9, 0, 8);
grille7 = add_case(grille7, 1, 2, 8);
grille7 = add_case(grille7, 2, 3, 8);
grille7 = add_case(grille7, 6, 4, 8);
grille7 = add_case(grille7, 4, 6, 8);
grille7 = add_case(grille7, 3, 8, 8);

regleTripletsNus(&grille7);
afficheGrille(grille7);

structCellule cellule00 = grille7.cellules[1][0];
structCellule cellule01 = grille7.cellules[1][1]; 
structCellule cellule02 = grille7.cellules[1][2]; 
structCellule cellule03 = grille7.cellules[1][3]; 
structCellule cellule04 = grille7.cellules[1][4];
structCellule cellule05 = grille7.cellules[1][5]; 
structCellule cellule06 = grille7.cellules[1][6];
structCellule cellule07 = grille7.cellules[1][7]; 
structCellule cellule08 = grille7.cellules[1][8];
//structCellule cellule09 = grille7.cellules[2][9];
printf("\n");
afficherNotesCellule(cellule00);
afficherNotesCellule(cellule01);
afficherNotesCellule(cellule02);
afficherNotesCellule(cellule03);
afficherNotesCellule(cellule04);
afficherNotesCellule(cellule05);
afficherNotesCellule(cellule06);
afficherNotesCellule(cellule07);
afficherNotesCellule(cellule08);
//afficherNotesCellule(cellule09);

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//grille teste regle 11

printf("\n----grille teste regle 11 - paire pointante----\n"); 


structGrille grille11 = create_grille(); 
grille11 = initGrille(grille11);
printf("\n");
printf("\n");
printf("GRILLE 11 ");
printf("\n");

grille11 = add_case(grille11, 9, 2, 0);
grille11 = add_case(grille11, 7, 4, 0);
grille11 = add_case(grille11, 8, 1, 1);
grille11 = add_case(grille11, 4, 3, 1);
grille11 = add_case(grille11, 3, 2, 2);
grille11 = add_case(grille11, 2, 7, 2);
grille11 = add_case(grille11, 8, 8, 2);
grille11 = add_case(grille11, 1, 0, 3);
grille11 = add_case(grille11, 6, 6, 3);
grille11 = add_case(grille11, 7, 7, 3);
grille11 = add_case(grille11, 2, 1, 4);
grille11 = add_case(grille11, 1, 4, 4);
grille11 = add_case(grille11, 8, 5, 4);
grille11 = add_case(grille11, 4, 7, 4);
grille11 = add_case(grille11, 4, 1, 5);
grille11 = add_case(grille11, 7, 5, 5);
grille11 = add_case(grille11, 8, 6, 5);
grille11 = add_case(grille11, 6, 0, 6);
grille11 = add_case(grille11, 3, 4, 6);
grille11 = add_case(grille11, 1, 1, 7);
grille11 = add_case(grille11, 2, 6, 8);
grille11 = add_case(grille11, 8, 7, 8);
grille11 = add_case(grille11, 4, 8, 8);

afficheGrille(grille11);
reglePairesPointantes(&grille11);

structCellule cellule000 = grille11.cellules[0][0];
structCellule cellule001 = grille11.cellules[0][1]; 
structCellule cellule002 = grille11.cellules[0][2]; 
structCellule cellule003 = grille11.cellules[0][3]; 
structCellule cellule004 = grille11.cellules[0][4];
structCellule cellule005 = grille11.cellules[0][5]; 
structCellule cellule006 = grille11.cellules[0][6];
structCellule cellule007 = grille11.cellules[0][7]; 
structCellule cellule008 = grille11.cellules[0][8];
printf("\n");
afficherNotesCellule(cellule000);
afficherNotesCellule(cellule001);
afficherNotesCellule(cellule002);
afficherNotesCellule(cellule003);
afficherNotesCellule(cellule004);
afficherNotesCellule(cellule005);
afficherNotesCellule(cellule006);
afficherNotesCellule(cellule007);
afficherNotesCellule(cellule008);


// Test de paire et triplets cachés
printf("\n----grille teste regle 7 - Triplets Nus----\n"); 


afficherNotesCellule(grille5.cellules[0][4]);
printf(" - ");
afficherNotesCellule(grille5.cellules[0][5]);

pairesCachees(grille5);

afficherNotesCellule(grille5.cellules[0][4]);
printf(" - ");
afficherNotesCellule(grille5.cellules[0][5]);

afficherNotesCellule(grille5.cellules[4][4]);
printf(" - ");
afficherNotesCellule(grille5.cellules[5][4]);



structGrille grille8 = create_grille();
grille8 = initGrille(grille8);

add_case(grille8, 8, 2, 0);
add_case(grille8, 7, 5, 0);
add_case(grille8, 4, 1, 1);
add_case(grille8, 2, 2, 1);
add_case(grille8, 5, 5, 1);
add_case(grille8, 3, 2, 3);
add_case(grille8, 6, 5, 3);
add_case(grille8, 8, 6, 3);
add_case(grille8, 1, 8, 3);
add_case(grille8, 6, 8, 4);
add_case(grille8, 9, 0, 5);
add_case(grille8, 8, 1, 6);
add_case(grille8, 1, 3, 6);
add_case(grille8, 3, 4, 6);
add_case(grille8, 4, 6, 6);
add_case(grille8, 7, 7, 6);
add_case(grille8, 9, 4, 7);
add_case(grille8, 1, 1, 8);

printf("\nGrille d'exemple triplet cache\n");
afficheGrille(grille8);

//test triplet caché
printf("\n - ");
afficherNotesCellule(grille8.cellules[3][7]);
printf(" - ");
afficherNotesCellule(grille8.cellules[3][8]);
printf(" - ");
afficherNotesCellule(grille8.cellules[4][8]);

tripletsCaches(grille8);

printf("\n - ");
afficherNotesCellule(grille8.cellules[3][7]);
printf(" - ");
afficherNotesCellule(grille8.cellules[3][8]);
printf(" - ");
afficherNotesCellule(grille8.cellules[4][8]);

//******************************************//
//******************************************//

//free_grille(&grille0);
//free_grille(&grille1);
//free_grille(&grille2);
//free_grille(&grille3);
/*
free_grille(&grille6);
free_grille(&grille7);
*/
free_grille(&grille11);
free_grille(&grille6);
free_grille(&grille7);
free_grille(&grille8);



return EXIT_SUCCESS;

}
