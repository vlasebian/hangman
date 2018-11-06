#include "hiddenExpression.h"

int* create_hidden_expression(char* game_expression) {
    int i = 0, j = 0, *appearance_of_characters, expression_lenght = 0;
    
    expression_lenght = strlen(game_expression);
    appearance_of_characters = (int*)calloc(expression_lenght, sizeof(int));

    // Afisam prima si ultima litera
    appearance_of_characters[0] = 1;
    appearance_of_characters[expression_lenght - 1] = 1;

    for (i = 0; i < expression_lenght; i++) {
        // Afisam spatiile
        if (game_expression[i] == ' ') {
            appearance_of_characters[i] = 1;
        }

        // Afisam prima si ultima litera din fiecare cuvant
        if ((i  > 0 && i < expression_lenght - 1) && (game_expression[i-1] == ' ' 
                    || game_expression[i+1] == ' ')) {
           appearance_of_characters[i] = 1;
        }
    }

    for (i = 0; i <expression_lenght; i++) {
        // Conditie pentru cuvinte formate din doua litere
        if (i > 0 && i < expression_lenght - 2 && game_expression[i-1] == ' ' && game_expression[i] != ' ' && game_expression[i+1] != ' ' && game_expression[i+2] == ' ') {
            appearance_of_characters[i] = 1;
            appearance_of_characters[i+1] = 0;
        }
        
        // Conditie pentru cuvinte formate dintr-o litera
        if (i > 0 && i < expression_lenght - 1 && game_expression[i-1] == ' ' && game_expression[i+1] == ' ' && game_expression[i] != ' ') {
            appearance_of_characters[i] = 0;
        }
    }
   
    // Conditii pentru cuvinte aflate la sfarsitul sau la inceputul expresiei

    // Primul cuvant este format din doua litere
    if (game_expression[0] != ' ' && game_expression[1] != ' ' && game_expression[2] == ' ') {
        appearance_of_characters[0] = 1;
        appearance_of_characters[1] = 0;
    }
    // Ultimul cuvant este format din doua litere
    if ( game_expression[expression_lenght - 1] != ' ' && game_expression[expression_lenght - 2] != ' ' && game_expression[expression_lenght - 3] == ' ' ) {
        appearance_of_characters[expression_lenght - 1] = 0;
        appearance_of_characters[expression_lenght - 2] = 1;
    }
        
    // Primul cuvant este format dintr-o litera
    if (game_expression[0] != ' ' && game_expression[1] == ' ') {
        appearance_of_characters[0] = 0;
    }

    // Ultimul cuvant este format dintr-o litera
    if (game_expression[expression_lenght - 1] != ' ' && game_expression[expression_lenght - 2] == ' ') {
        appearance_of_characters[expression_lenght - 1] = 0;
    }
 
    // Afisam literele care se repeta 
    for (i = 0; i < expression_lenght; i++) {
        if(appearance_of_characters[i] == 1) {
            for(j=0; j < expression_lenght; j++) {
                if(game_expression[i] == game_expression[j]) {
                    appearance_of_characters[j] = 1;
                }
            }
        }
    }
     
    // Returnam vectorul de aparitii
    return appearance_of_characters;
}
