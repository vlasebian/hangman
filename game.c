#include "game.h"

int work_on_expression(char* game_expression)
{
    char *wrong_characters, current_char;
    int i = 0, *appearance_of_characters, mistakes = 0;
    int expression_lenght = 0, check = 0, number_of_columns = 0;
    int number_of_rows = 0, x_expression = 0, y_expression = 0;
    int wrong_characters_lenght = 0, menu_return = 0;

    expression_lenght = strlen(game_expression);
    wrong_characters = (char*)calloc(expression_lenght, sizeof(char));

    // Functia create_hidden_expression formeaza sirul ascuns. Ne vom folosi de un vector de
    // aparitii pentru a marca caracterele ascunse (valoarea 0) si cele afisate (valoarea 1).
    appearance_of_characters = create_hidden_expression(game_expression);

    // Folosim functia select pentru introducerea unui caracter aleatoriu daca utilizatorul nu apasa
    // pe nici o tasta timp de 7 secunde

    clear();
    // Salvam numarul de linii si de coloane al ecranului, si pozitia unde afisam expresia
    getmaxyx(stdscr, number_of_rows, number_of_columns);
    x_expression = number_of_columns/2 - expression_lenght/2;
    y_expression = number_of_rows/6;
 
   
    // Afisam sirul ascuns
    for (i = 0; i < expression_lenght; i++) {
        if(appearance_of_characters[i] == 1) {
                mvprintw(y_expression, x_expression + i, "%c", game_expression[i]);
         } else {
                mvprintw(y_expression, x_expression + i, "%c", '_');
         }
    }

    panel_and_info(mistakes);
    drawing(mistakes, expression_lenght);

    while (FOREVER) {
        do {
            current_char = getch();

            if (current_char == 'Q') {
                clear();
                menu_return = game_menu(1);

                if (menu_return == 0) {
                    return 4;
                }

                if (menu_return == 2) {
                    return 2;   
                }

                for (i = 0; i < expression_lenght; i++) {
                    if (appearance_of_characters[i] == 1) {
                        current_char = game_expression[i];
                        break;
                    }
                }
            }
         } while(strchr(wrong_characters, current_char) != NULL);    

        // Adaugam caracterul la vectorul de aparitii in cazul in care se afla in expresie. Daca
        // nu se afla in expresie, adaugam caracterul in vectorul de caractere gresite si marim
        // numarul de greseli
        if (strchr(game_expression, current_char) != NULL) {
            for(i = 0; i < expression_lenght; i++) {
                if(game_expression[i] == current_char) {
                    appearance_of_characters[i] = 1;
                }
            }
        } else {
            wrong_characters[mistakes] = current_char;
            mistakes++;
        }

        // Verificam cate elemente din vectorul de aparitii sunt egale cu 1
        check = 0;
        for (i = 0; i < expression_lenght; i++) {
            if(appearance_of_characters[i] == 1) {
                check ++;
            }
        }

        // Afisam expresia, desenul si panoul
        clear();
        for (i = 0; i < expression_lenght; i++) {
            if(appearance_of_characters[i] == 1) {
                mvprintw(y_expression, x_expression + i, "%c", game_expression[i]);
            } else {
                mvprintw(y_expression, x_expression + i, "%c", '_');
            }
        }

        panel_and_info(mistakes);
        drawing(mistakes, expression_lenght);
        wrong_characters_lenght = strlen(wrong_characters);
        // Afisam caracterele introduse care nu se afla in cuvant
        for (i = 0; i < mistakes; i ++) {
            mvprintw(number_of_rows/2 + number_of_rows/3 - 1, number_of_columns/2 - wrong_characters_lenght/2 + i, "%c", wrong_characters[i]);
        }

        // In cazul in care numarul de elemente egale cu 1 din vectorul de apartii este egal cu
        // lungimea expresiei atunci jocul este castigat. Daca numarul de greseli ajunge la 6
        // jocul este pierdut
        if (check == expression_lenght) {
            mvprintw(number_of_rows/2 + number_of_rows/3 + 1, number_of_columns/2 - (strlen("WIN")/2), "WIN");
            mvprintw(number_of_rows/2 + number_of_rows/3 + 2, number_of_columns/2 - (strlen("-- Press N for New Game --")/2), "-- Press N for New Game --");
            mvprintw(number_of_rows/2 + number_of_rows/3 + 3, number_of_columns/2 - (strlen("-- Press Q for Menu --")/2), "-- Press Q for Menu --");
            break;
        }

        if (mistakes == 6) {
            mvprintw(number_of_rows/2 + number_of_rows/3 + 1, number_of_columns/2 - (strlen("-- Game Over --")/2), "-- Game Over --");
            mvprintw(number_of_rows/2 + number_of_rows/3 + 2, number_of_columns/2 - (strlen("-- Press N for New Game --")/2), "-- Press N for New Game --");
            mvprintw(number_of_rows/2 + number_of_rows/3 + 3, number_of_columns/2 - (strlen("-- Press Q for Menu --")/2), "-- Press Q for Menu --");
            break;
        }
    }
   
    while (FOREVER) {
        current_char = getch();

        if (current_char == 'Q') {    
            free(appearance_of_characters);
            free(wrong_characters);
            clear();

            return 1;
        }

        if (current_char == 'N') {  
            free(appearance_of_characters);
            free(wrong_characters);
            clear();

            return 2;
        }
    }
}
