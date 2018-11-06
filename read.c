#include "read.h"

char** read_input(int argc, char** argv, int *sent_number_of_lines)
{
    char **lines_read, current_char = 0, *auxiliary_line, check_if_line_is_empty = 0;
    FILE* input_file;
    int i = 0, number_of_lines_read = 0, double_array_capacity = 1000, line_lenght = 0,  line_capacity = 1;

    // Alocam 10 linii pentru matricea unde sunt salvate liniile
    lines_read = (char**)calloc(double_array_capacity, sizeof(char*));

    line_capacity = 1000;
    // Alocam memorie pentru sirul auxiliar
    auxiliary_line = (char*)calloc(line_capacity, sizeof(char));

    
    for (i = 1; i < argc; i ++) {   
        //Verificam daca fiserele date ca argument pot fi deschise
        input_file = fopen(argv[i], "rt");
        if (input_file == NULL) {
            printf("[Eroare]: Fisierul %s nu poate fi deschis.\n", argv[i]);
            return NULL;
        }

        current_char = fgetc(input_file);
        while (current_char != EOF) {
            // In cazul in care matricea atinge capacitatea maxima, reallocam memorie
            if (number_of_lines_read == double_array_capacity) {
                double_array_capacity = double_array_capacity * 2;
                lines_read = (char**)realloc(lines_read, double_array_capacity*sizeof(char*));
            }

            line_lenght = 0;
            // Citim cate un caracter cat timp acesta este diferit de '\n' pentru a extrage cate o linie
            while (current_char != '\n') {  
                // Daca caracterul este printabil, il salvam in sirul auxiliar
                if (isprint(current_char) != 0) {
                    // In cazul in care sirul auxiliar atinge capacitatea maxima, realocam memorie
                    if(line_lenght  == line_capacity) {
                        line_capacity = line_capacity * 2;
                        auxiliary_line = (char*)realloc(auxiliary_line, line_capacity * sizeof(char));
                    }

                    if (isalpha(current_char) != 0) {
                        current_char=tolower(current_char);
                    }

                    auxiliary_line[line_lenght] = current_char;
                    // Actualizam numarul de caractere (lungimea liniei) 
                    line_lenght++;
                }
                // Actualizam caracterul curent   
                current_char = fgetc(input_file);
            }

            //Adaugam NULL la sfarsitul liniei si salvam sirul auxiliar in matrice, apoi stergem
            //continutul sirului auxiliar
            auxiliary_line[line_lenght] = '\0';
            check_if_line_is_empty = auxiliary_line[0];
            if (check_if_line_is_empty != 0) {
                lines_read[number_of_lines_read] = strdup(auxiliary_line);
                number_of_lines_read++;
            }

            strcat(auxiliary_line, "");
            //Trecem la urmatorul caracter
            current_char = fgetc(input_file);
        }

        fclose(input_file);
    }
   
    // Eliberam memoria nefolosita
    for (i = number_of_lines_read;  i < line_capacity; i++) {
        free(lines_read[i]);
    }

    free(auxiliary_line);
      
    // Returnam valorile 
    *sent_number_of_lines = number_of_lines_read;
    return lines_read;
}
