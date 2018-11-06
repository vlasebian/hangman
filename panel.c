#include "panel.h"

void panel_and_info(int mistakes)
{
    // Aflam data si timpul curent
    time_t raw_time;
    raw_time = time(NULL);

    mvprintw( 1, 1, "%s", ctime(&raw_time));
    mvprintw( 2, 1, "Press Q for Menu");
    mvprintw( 3, 1, "Lives left: %d", 6-mistakes);
 
    return;
}

char generate_random_character() //(int *appearance_of_characters, char *game_expression, char *wrong_characters, int expression_lenght)
{
    //int i, check = 0;
    int max_generating_number = 0;
    char random_character = 0;

    // Codurile ASCII ale caracterelor printabile se afla intre 32 si 128. Deci vom genera un numar
    // intre 0 si 96, pe care il vom aduna apoi cu 32.
    max_generating_number = 96;

    // Generam un caracter
    srand(time(NULL));
    random_character = (rand() % max_generating_number) + 32;
    
    // Il prelucram in cazul in care este o majuscula
    if (isalpha(random_character) != 0)
        random_character = tolower(random_character);
    /*
    // Verificam daca se afla deja in sir sau printre caracterele gresite. In acest caz generam alt
    // caracter
    check = 1;
    while (check != 0) {
        check = 0;
        for (i = 0; i < expression_lenght; i++) {
            if (appearance_of_characters[i] == 1 && game_expression[i] == random_character) {
                random_character = (rand() % max_generating_number) + 32;
                if (isalpha(random_character) != 0) {
                    random_character = tolower(random_character);
                }
                check = 1;
            }
        }

        if (strchr(wrong_characters, random_character) != NULL) {
            random_character = (rand() % max_generating_number) + 32;
            if (isalpha(random_character) != 0) {
                random_character = tolower(random_character);
            }
            check = 1;
        }
    }   
    */

    // Returnam caracterul
    return random_character;
}


