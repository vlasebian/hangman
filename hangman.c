#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <sys/select.h>

#include "hiddenExpression.h"
#include "game.h"
#include "menu.h"
#include "read.h"
#include "drawing.h"
#include "panel.h"
#include "constants.h"


// Functie pentru alegerea aleatorie a unei expresii
char* random_expression_generator(int number_of_lines_read, char** lines_read)
{
    int random_line_number = 0, i = 0;
    char *game_expression;

    // Generam un numar aleatoriu de la 0 la numarul de linii din matricea de expresii citite pentru
    // a alege o expresie aleatoare
    i = time(NULL);
    srand(i);
    random_line_number = rand() % number_of_lines_read;
    game_expression = strdup(lines_read[random_line_number]);
    
    return game_expression;
}

int main (int argc, char** argv)
{
    // Daca functia nu are nici un argument, se va afisa o eroare
    if (argc == 1) {
        printf("[Eroare]: Nu s-au dat argumente de comanda.\n");
        return 1;
    }

    char** lines_read, *game_expression;
    int number_of_lines_read = 0, i = 0, menu_return = 0, game_return = 0;
        
    // Functia read_input (din fisierul read.c) se ocupa de citire si de prelucrarea expresiei. Daca un fisier nu poate fi
    // deschis, functia afiseaza o eroare care contine numele fisierului si returneaza NULL.
    lines_read = read_input(argc, argv, &number_of_lines_read);
    if (lines_read == NULL) {
        return 1;
    }

  
    // Initializam ecranul
    initscr();
    // Stergem ecranul
    clear();
    // Nu afisam caractere
    noecho();
    // Caracterele introduse sunt citite imediat, fara buffering
    cbreak();
    // Ascudem cursorul
    curs_set(0);

    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    refresh();

    while (FOREVER) {
        // Functia random_expression_generator alege aleatoriu o expresie din liniile citite.
        game_expression = random_expression_generator(number_of_lines_read, lines_read);
        // Functia game_menu (fisierul menu.c) creeaza meniul si gestioneaza alegerile jucatorului
        menu_return = game_menu(0);
        // Daca functia game_menu returneaza 2, jucatorul a ales optiunea New Game
        if (menu_return == 2) { 
            // Funtia work_on_expression (fisierul game.c) se ocupa de jocul propriu-zis. Daca
            // returneaza 2, jucatorul a apasat N.
            game_return = work_on_expression(game_expression);
            if (game_return == 2) {
                while(FOREVER) {
                // Se genereaza o noua expresie si se incepe un joc
                // nou. Daca work_on_expression returneaza 1 sau 4 jucatorul a apasat tasta Q sau a ales
                // optiunea Quit din meniu(in timpul unui joc neterminat cand optiunea resume game
                // devine valabila)
                    game_expression = random_expression_generator(number_of_lines_read, lines_read);
                    game_return = work_on_expression(game_expression);
                    if (game_return == 1 || game_return == 4) {
                        break;
                    }
                }
            }
        }
        
        // Daca functia game_menu returneaza 0 sau se alege Quit din meniu in timpul unui joc
        // neterminat, se inchide jocul.
        if (menu_return == 0 || game_return == 4) {
            break;
        }

        clear();
    }

    attroff(COLOR_PAIR(1));
    endwin();

    for (i = 0; i < number_of_lines_read; i ++) {
       free(lines_read[i]);
    }

    free(game_expression);
    free(lines_read);
    
    return 0;
}
