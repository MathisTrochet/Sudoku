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

    //structCase **grille = create_grille(9);

/*
    grille = add_case(grille, 2, 2, 1);

    printf("%d", grille[2][1]->valeur);

    grille = rem_case(grille, 2, 1);

*/

    structCase **grille1 = create_grille();

    //remplirGrille(grille1);
    //afficheGrille(grille1);



//GRILLE JUSTE


grille1 = add_case(grille1, 7, 0, 0);
grille1 = add_case(grille1, 9, 1, 0);
grille1 = add_case(grille1, 8, 2, 0);
grille1 = add_case(grille1, 1, 3, 0);
grille1 = add_case(grille1, 6, 4, 0);
grille1 = add_case(grille1, 2, 5, 0);
grille1 = add_case(grille1, 3, 6, 0);
grille1 = add_case(grille1, 5, 7, 0);
grille1 = add_case(grille1, 4, 8, 0);

grille1 = add_case(grille1, 6, 0, 1);
grille1 = add_case(grille1, 4, 1, 1);
grille1 = add_case(grille1, 5, 2, 1);
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

    //afficheGrille(grille1);


structCase **grille2 = create_grille();
//structCase **bitch = initGrille(grille2);
//printf("yo");
afficheGrille(grille2);

grille2 = add_case(grille2, 7, 0, 0);
grille2 = add_case(grille2, 9, 1, 0);
grille2 = add_case(grille2, 8, 2, 0);
grille2 = add_case(grille2, 1, 3, 0);
grille2 = add_case(grille2, 0, 4, 0);
grille2 = add_case(grille2, 2, 5, 0);
grille2 = add_case(grille2, 3, 6, 0);
grille2 = add_case(grille2, 5, 7, 0);
grille2 = add_case(grille2, 4, 8, 0);
//regle1(grille2, 0, 0, 8, 0 ); // on check la premiere ligne
structCase **test = regle1(grille2, 0, 0, 8, 0 );
afficheGrille(test);


return EXIT_SUCCESS;

}
