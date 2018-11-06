#include "drawing.h"

void drawing(int mistakes, int expression_lenght)
{
    int number_of_columns = 0, number_of_rows = 0, x = 0, y = 0, i = 0;
    int top_left_corner_x = 0, bottom_left_y = 0;
    int head_top_line_y = 0, head_bottom_line_y = 0, j = 0, bottom_body_line_y = 0;
    getmaxyx(stdscr, number_of_rows, number_of_columns);

    // Mijlocul ecranului
    x = number_of_columns / 2;
    // top_left_corner_y == y
    y = number_of_rows / 5;
    // top_left_corner_x == bottom of vertical line
    top_left_corner_x = x / 2 + x / 4;
    bottom_left_y = number_of_rows / 2 + number_of_rows / 4;

    head_top_line_y = bottom_left_y / 3 + 1;
    head_bottom_line_y = bottom_left_y / 3 + bottom_left_y / 6 - 1;
    bottom_body_line_y = number_of_rows / 2 + number_of_rows / 10;


    switch (mistakes) {
        case 0:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }

            break;
        }

        case 1:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }
            //Ochii
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            break;
        }

        case 2:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }
            //Ochii
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            //Linia pt corp
            for (i = head_bottom_line_y + 1; i < bottom_body_line_y; i++) {
                mvprintw(i, x, "|");
            }

            break;
        }

        case 3:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            {
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }
            // Ochii:
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            // Linia pentru corp
            for (i = head_bottom_line_y + 1; i < bottom_body_line_y; i++) {
                mvprintw(i, x, "|");
            }

            // Mana stanga
            i = head_bottom_line_y + 2;
            j = x - 1;
            while (i < ( number_of_rows/2 + number_of_rows/10) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }

            break;
        }

        case 4:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }
            // Ochii:
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            // Linia pentru corp
            for (i = head_bottom_line_y + 1; i < bottom_body_line_y; i++) {
                mvprintw(i, x, "|");
            }

            // Mana stanga
            i = head_bottom_line_y + 2;
            j = x - 1;
            while (i < ( number_of_rows/2 + number_of_rows/10) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }

            // Mana stanga
            i = head_bottom_line_y + 2;
            j = x + 1;
            while (i < ( number_of_rows/2 + number_of_rows/10) && j <= (x + x/16)) {  
                mvprintw(i, j, "\\");
                i++;
                j++;
            }

            break;
        }

        case 5:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }
            // Ochii:
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            // Linia pentru corp
            for (i = head_bottom_line_y + 1; i < bottom_body_line_y; i++) {
                mvprintw(i, x, "|");
            }

            // Mana stanga
            i = head_bottom_line_y + 2;
            j = x - 1;
            while (i < (number_of_rows/2 + number_of_rows/10) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }

            // Mana dreapta
            i = head_bottom_line_y + 2;
            j = x + 1;
            while (i < (number_of_rows/2 + number_of_rows/10) && j <= (x + x/16)) {  
                mvprintw(i, j, "\\");
                i++;
                j++;
            }

            // Piciorul stang
            i = bottom_body_line_y;
            j = x - 1;
            while (i < ( bottom_body_line_y + number_of_rows/2) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }
            break;
        }
        
        case 6:
        {
            // Linia orizontala de sus
            for (i = x; i >= top_left_corner_x; i--) {
                mvprintw(y, i, "_");
            }
            // Linia verticala din dreapta
            for (i = y + 1; i <= bottom_left_y/3; i++) {
                mvprintw(i, x, "|");
            }
            // Linia verticala din stanga
            for (i = y + 1; i < bottom_left_y; i++) {
                mvprintw(i, top_left_corner_x, "|");
            }
            // Linia orizontala de jos
            for (i = top_left_corner_x - x/10 + 2; i < top_left_corner_x + x/10; i++) {
                mvprintw(bottom_left_y, i, "_");
            }
            // Cap :
            // Liniile orizontale
            for (i = x - x/16; i <= x + x/16; i++) {
                mvprintw(head_top_line_y, i, "_");
                mvprintw(head_bottom_line_y, i, "_");
            }
            // Liniile verticale
            for (i = head_top_line_y + 1; i <= head_bottom_line_y; i++) {
                mvprintw(i, x - x/16, "|");
                mvprintw(i, x + x/16, "|");
            }

            // Ochii:
            mvprintw(head_top_line_y + 2, x-x/30, "X");
            mvprintw(head_top_line_y + 2, x+x/30, "X");

            // Linia pentru corp
            for (i = head_bottom_line_y + 1; i < bottom_body_line_y; i++) {
                mvprintw(i, x, "|");
            }

            // Mana stanga
            i = head_bottom_line_y + 2;
            j = x - 1;
            while (i < ( number_of_rows/2 + number_of_rows/10) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }

            // Mana dreapta
            i = head_bottom_line_y + 2;
            j = x + 1;
            while (i < ( number_of_rows/2 + number_of_rows/10) && j <= (x + x/16)) {  
                mvprintw(i, j, "\\");
                i++;
                j++;
            }

            // Piciorul stang
            i = bottom_body_line_y;
            j = x - 1;
            while (i < ( bottom_body_line_y + number_of_rows/2) && j >= (x - x/16)) {  
                mvprintw(i, j, "/");
                i++;
                j--;
            }   
            
            // Piciorul drept
            i = bottom_body_line_y;
            j = x + 1;
            while (i < ( bottom_body_line_y + number_of_rows/2) && j <= (x + x/16)) {  
                mvprintw(i, j, "\\");
                i++;
                j++;
            }   

            break;
        }
    }
}
}
}
