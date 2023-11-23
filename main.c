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

    structGrille grille0 = create_grille();
    grille0 = initGrille(grille0);

    structGrille grille1 = create_grille();
    grille1 = initGrille(grille1);
    

    //remplirGrille(grille1);
    //afficheGrille(grille1);



//GRILLE FACILE BASE 

//grille0 = add_case(grille0, 0, 0, 0);
grille0 = add_case(grille0, 6, 1, 0);
grille0 = add_case(grille0, 8, 2, 0);
grille0 = add_case(grille0, 9, 3, 0);
grille0 = add_case(grille0, 1, 4, 0);
//grille0 = add_case(grille0, 0, 5, 0);
grille0 = add_case(grille0, 4, 6, 0);
//grille0 = add_case(grille0, 0, 7, 0);
//grille0 = add_case(grille0, 0, 8, 0);

grille0 = add_case(grille0, 3, 0, 1);
grille0 = add_case(grille0, 4, 1, 1);
grille0 = add_case(grille0, 2, 2, 1);
//grille0 = add_case(grille0, 0, 3, 1);
//grille0 = add_case(grille0, 0, 4, 1);
grille0 = add_case(grille0, 7, 5, 1);
//grille0 = add_case(grille0, 0, 6, 1);
//grille0 = add_case(grille0, 0, 7, 1);
//grille0 = add_case(grille0, 0, 8, 1);

//grille0 = add_case(grille0, 0, 0, 2);
//grille0 = add_case(grille0, 0, 1, 2);
grille0 = add_case(grille0, 7, 2, 2);
//grille0 = add_case(grille0, 0, 3, 2);
//grille0 = add_case(grille0, 0, 4, 2);
//grille0 = add_case(grille0, 0, 5, 2);
//grille0 = add_case(grille0, 0, 6, 2);
grille0 = add_case(grille0, 8, 7, 2);
//grille0 = add_case(grille0, 0, 8, 2);

//grille0 = add_case(grille0, 0, 0, 3);
//grille0 = add_case(grille0, 0, 1, 3);
//grille0 = add_case(grille0, 0, 2, 3);
grille0 = add_case(grille0, 4, 3, 3);
grille0 = add_case(grille0, 7, 4, 3);
grille0 = add_case(grille0, 9, 5, 3);
//grille0 = add_case(grille0, 0, 6, 3);
grille0 = add_case(grille0, 3, 7, 3);
//grille0 = add_case(grille0, 0, 8, 3);

//grille0 = add_case(grille0, 0, 0, 4);
//grille0 = add_case(grille0, 0, 1, 4);
grille0 = add_case(grille0, 4, 2, 4);
//grille0 = add_case(grille0, 0, 3, 4);
//grille0 = add_case(grille0, 0, 4, 4);
grille0 = add_case(grille0, 2, 5, 4);
//grille0 = add_case(grille0, 0, 6, 4);
grille0 = add_case(grille0, 9, 7, 4);
//grille0 = add_case(grille0, 0, 8, 4);

//grille0 = add_case(grille0, 0, 0, 5);
grille0 = add_case(grille0, 1, 1, 5);
//grille0 = add_case(grille0, 0, 2, 5);
//grille0 = add_case(grille0, 0, 3, 5);
//grille0 = add_case(grille0, 0, 4, 5);
//grille0 = add_case(grille0, 0, 5, 5);
grille0 = add_case(grille0, 7, 6, 5);
//grille0 = add_case(grille0, 0, 7, 5);
grille0 = add_case(grille0, 4, 8, 5);

//grille0 = add_case(grille0, 0, 0, 6);
grille0 = add_case(grille0, 2, 1, 6);
//grille0 = add_case(grille0, 0, 2, 6);
grille0 = add_case(grille0, 3, 3, 6);
grille0 = add_case(grille0, 4, 4, 6);
//grille0 = add_case(grille0, 0, 5, 6);
//grille0 = add_case(grille0, 0, 6, 6);
grille0 = add_case(grille0, 7, 7, 6);
//grille0 = add_case(grille0, 0, 8, 6);

grille0 = add_case(grille0, 4, 0, 7);
//grille0 = add_case(grille0, 0, 1, 7);
//grille0 = add_case(grille0, 0, 2, 7);
//grille0 = add_case(grille0, 0, 3, 7);
grille0 = add_case(grille0, 9, 4, 7);
grille0 = add_case(grille0, 1, 5, 7);
grille0 = add_case(grille0, 2, 6, 7);
//grille0 = add_case(grille0, 0, 7, 7);
grille0 = add_case(grille0, 6, 8, 7);

grille0 = add_case(grille0, 8, 0, 8);
//grille0 = add_case(grille0, 0, 1, 8);
grille0 = add_case(grille0, 1, 2, 8);
//grille0 = add_case(grille0, 0, 3, 8);
grille0 = add_case(grille0, 2, 4, 8);
grille0 = add_case(grille0, 6, 5, 8);
grille0 = add_case(grille0, 3, 6, 8);
grille0 = add_case(grille0, 4, 7, 8);
grille0 = add_case(grille0, 9, 8, 8);

//GRILLE JUSTE



//grille1 = add_case(grille1, 7, 0, 0);
//grille1 = add_case(grille1, 9, 1, 0);
//grille1 = add_case(grille1, 8, 2, 0);
//grille1 = add_case(grille1, 1, 3, 0);
//grille1 = add_case(grille1, 6, 4, 0);
//grille1 = add_case(grille1, 2, 5, 0);
//grille1 = add_case(grille1, 3, 6, 0);
//grille1 = add_case(grille1, 5, 7, 0);
//grille1 = add_case(grille1, 4, 8, 0);

//grille1 = add_case(grille1, 6, 0, 1);
//grille1 = add_case(grille1, 4, 1, 1);
//grille1 = add_case(grille1, 5, 2, 1);
grille1 = add_case(grille1, 7, 3, 1);
grille1 = add_case(grille1, 8, 4, 1);
grille1 = add_case(grille1, 3, 5, 1);
grille1 = add_case(grille1, 2, 6, 1);
grille1 = add_case(grille1, 1, 7, 1);
grille1 = add_case(grille1, 9, 8, 1);

grille1 = add_case(grille1, 1, 0, 2);
grille1 = add_case(grille1, 3, 1, 2);
grille1 = add_case(grille1, 2, 2, 2);
grille1 = add_case(grille1, 4, 3, 2);
grille1 = add_case(grille1, 9, 4, 2);
grille1 = add_case(grille1, 5, 5, 2);
grille1 = add_case(grille1, 6, 6, 2);
grille1 = add_case(grille1, 8, 7, 2);
grille1 = add_case(grille1, 7, 8, 2);

grille1 = add_case(grille1, 5, 0, 3);
grille1 = add_case(grille1, 2, 1, 3);
grille1 = add_case(grille1, 4, 2, 3);
grille1 = add_case(grille1, 3, 3, 3);
grille1 = add_case(grille1, 1, 4, 3);
grille1 = add_case(grille1, 9, 5, 3);
grille1 = add_case(grille1, 7, 6, 3);
grille1 = add_case(grille1, 6, 7, 3);
grille1 = add_case(grille1, 8, 8, 3);

grille1 = add_case(grille1, 8, 0, 4);
grille1 = add_case(grille1, 7, 1, 4);
grille1 = add_case(grille1, 1, 2, 4);
grille1 = add_case(grille1, 2, 3, 4);
grille1 = add_case(grille1, 4, 4, 4);
grille1 = add_case(grille1, 6, 5, 4);
grille1 = add_case(grille1, 9, 6, 4);
grille1 = add_case(grille1, 3, 7, 4);
grille1 = add_case(grille1, 5, 8, 4);

grille1 = add_case(grille1, 3, 0, 5);
grille1 = add_case(grille1, 6, 1, 5);
grille1 = add_case(grille1, 9, 2, 5);
grille1 = add_case(grille1, 5, 3, 5);
grille1 = add_case(grille1, 7, 4, 5);
grille1 = add_case(grille1, 8, 5, 5);
grille1 = add_case(grille1, 4, 6, 5);
grille1 = add_case(grille1, 2, 7, 5);
grille1 = add_case(grille1, 1, 8, 5);

grille1 = add_case(grille1, 4, 0, 6);
grille1 = add_case(grille1, 8, 1, 6);
grille1 = add_case(grille1, 3, 2, 6);
grille1 = add_case(grille1, 9, 3, 6);
grille1 = add_case(grille1, 2, 4, 6);
grille1 = add_case(grille1, 1, 5, 6);
grille1 = add_case(grille1, 5, 6, 6);
grille1 = add_case(grille1, 7, 7, 6);
grille1 = add_case(grille1, 6, 8, 6);

grille1 = add_case(grille1, 9, 0, 7);
grille1 = add_case(grille1, 5, 1, 7);
grille1 = add_case(grille1, 6, 2, 7);
grille1 = add_case(grille1, 8, 3, 7);
grille1 = add_case(grille1, 3, 4, 7);
grille1 = add_case(grille1, 7, 5, 7);
grille1 = add_case(grille1, 1, 6, 7);
grille1 = add_case(grille1, 4, 7, 7);
grille1 = add_case(grille1, 2, 8, 7);

grille1 = add_case(grille1, 2, 0, 8);
grille1 = add_case(grille1, 1, 1, 8);
grille1 = add_case(grille1, 7, 2, 8);
grille1 = add_case(grille1, 6, 3, 8);
grille1 = add_case(grille1, 5, 4, 8);
grille1 = add_case(grille1, 4, 5, 8);
grille1 = add_case(grille1, 8, 6, 8);
grille1 = add_case(grille1, 9, 7, 8);
grille1 = add_case(grille1, 3, 8, 8);


structGrille grille2 = create_grille();
grille2 = initGrille(grille2);

grille2 = add_case(grille2, 7, 0, 0);
grille2 = add_case(grille2, 9, 1, 0);
grille2 = add_case(grille2, 8, 2, 0);
grille2 = add_case(grille2, 1, 3, 0);
grille2 = add_case(grille2, 6, 4, 0);
grille2 = add_case(grille2, 2, 5, 0);
grille2 = add_case(grille2, 3, 6, 0);
grille2 = add_case(grille2, 5, 7, 0);
grille2 = add_case(grille2, 4, 8, 0);

grille2 = add_case(grille2, 6, 0, 1);
grille2 = add_case(grille2, 4, 1, 1);
grille2 = add_case(grille2, 5, 2, 1);
grille2 = add_case(grille2, 7, 3, 1);
grille2 = add_case(grille2, 8, 4, 1);
grille2 = add_case(grille2, 3, 5, 1);
grille2 = add_case(grille2, 2, 6, 1);
grille2 = add_case(grille2, 1, 7, 1);
grille2 = add_case(grille2, 9, 8, 1);

grille2 = add_case(grille2, 1, 0, 2);
grille2 = add_case(grille2, 3, 1, 2);
grille2 = add_case(grille2, 2, 2, 2);
grille2 = add_case(grille2, 4, 3, 2);
grille2 = add_case(grille2, 9, 4, 2);
grille2 = add_case(grille2, 5, 5, 2);
grille2 = add_case(grille2, 6, 6, 2);
grille2 = add_case(grille2, 8, 7, 2);
grille2 = add_case(grille2, 7, 8, 2);

structGrille grille3 = create_grille(); // grille niveau difficile selon sudoku.com
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







//regle1(grille2, 0, 0, 8, 0 ); // on check la premiere ligne
//structCase **test1 = regle1(grille2, 0, 0, 8, 0 );
//afficheGrille(grille2);

    //structCase **test2 = regle1(grille2, 0, 0, 2, 2 );
//structCase **test3 = regle1(grille2, 0, 0, 8, 0 );
//afficheGrille(test1);
    //afficheGrille(test2);
//afficheGrille(test3);
/*
structCase **grille3 = create_grille();
grille3 = initGrille(grille3);
afficheGrille(grille3);
grille3 = add_case(grille3, 7, 0, 0);
grille3 = add_case(grille3, 9, 1, 0);
*/

printf("\n");
printf("[0][0] -> |");
for(int i=0; i<TAILLE ; i++){
    

    printf("%d", getNote(grille1, 0, 0, i));
    

}
printf("|");

printf("\n[0][1] -> |");
for(int i=0; i<TAILLE ; i++){
    

    printf("%d", getNote(grille1, 0, 1, i));
    

}
printf("|");



//grille1 = implanterNote(grille1);
//grille1 = implanterNote(grille1); 
//afficheGrille(grille1);



printf("\n AVANT \n");

afficheGrille(grille0);

grille0 = implanterNote(grille0);

printf("\n\n APRES \n");

afficheGrille(grille0);

printf("[0][0] -> |");
for(int i=0; i<TAILLE ; i++){
    

    printf("%d", getNote(grille0, 8, 0, i));
    

}
printf("|");


printf("AVANT \n");
/*
afficheGrille(grille3);

grille3 = implanterNote(grille3);

printf("\n\n APRES \n");

afficheGrille(grille3);

printf("[0][0] -> |");

for(int i=0; i<TAILLE ; i++){
    

    printf("%d", grille3[0][0].note[i]);
    

}

printf("|");
*/





return EXIT_SUCCESS;

}
