#include "menu.h"

int game_menu(int resume_state)
{
    int i = 0, highlighted_option = 0, pressed_key = 0;
    char menu_options[4][20] = {0};
    int number_of_rows = 0, number_of_columns = 0;
    
    // Scriem optiunile pentru meniu
    strcat(menu_options[0], "New Game");
    strcat(menu_options[1], "Resume Game");
    strcat(menu_options[2], "Quit");

    
    // Salvam numarul de randuri si de coloane al ecranului
    getmaxyx(stdscr, number_of_rows, number_of_columns);

    // Prima optiune evidentiata este primul cuvant din meniu
    highlighted_option=0;
    pressed_key=0;

    while (FOREVER) {
        for (i = 0; i < 3; i ++) {
            if (i == highlighted_option) {
                attron(A_REVERSE);
            }
            mvprintw(i + number_of_rows/3, (number_of_columns / 2) - (strlen(menu_options[i]) / 2), menu_options[i]);
            attroff(A_REVERSE);
            mvprintw(number_of_rows / 3 - 2, (number_of_columns / 2) - (strlen("HANGMAN") / 2), "HANGMAN");
        }

        pressed_key = getch();
        clear();
        switch (pressed_key) {
            case KEY_UP:
            {
                highlighted_option --;
                if (highlighted_option == -1) {
                    highlighted_option = 2;
                }
                break;
            }
            case KEY_DOWN:
            {
                highlighted_option++;
                if (highlighted_option == 3) {
                    highlighted_option = 0;
                }
    
                break;
            }
            default: 
                break;
        }
        
        if (pressed_key == 10 && highlighted_option != 1) {
            break;
        }
        if (pressed_key == 10 && highlighted_option == 1 && resume_state == 1) {
            break;
        } 

        if (pressed_key == 10 && highlighted_option == 1 && resume_state == 0) {
            mvprintw(number_of_rows / 3 + 4, (number_of_columns / 2) - (strlen("You don't have a game to resume, start a game first!") / 2),
                    "You don't have a game to resume, start a game first!");
        }
    }

    if (highlighted_option == 0) {
        clear();
        return 2;
    }

    if (highlighted_option == 1) {
        clear();
        return 1;
    }
        
    if (highlighted_option == 2) {   
        endwin();
        return 0;
    }

    return 0;
}

