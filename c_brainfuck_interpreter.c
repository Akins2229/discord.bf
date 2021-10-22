#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};
 
// set the pointer to point at the left-most cell of the tape
unsigned char* ptr = tape;

char* variables[30000][30000][3] = {
 {
  {
   "",
   "",
   "0"
  }
 }
};

void interpret(char* input) {
    char current_char;
    size_t i;
    size_t loop;

    for (i = 0; input[i] != 0; i++) {
        current_char = input[i];
        if (current_char == '>') {
            ++ptr;
        } else if (current_char == '<') {
            --ptr;
        } else if (current_char == '+') {
            ++*ptr;
        } else if (current_char == '-') {
            --*ptr;
        } else if (current_char == '.' ) {
            putchar(*ptr);
        } else if (current_char == ',') {
            *ptr = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *ptr) {
            loop = 1;
            while (loop > 0) {
                current_char = input[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        } else if (current_char == "$") {
            var = 1;
            unsigned char* string = "";
            while (var > 0) {
                ++*ptr;
                if (*ptr == "0") {
                   variable_type = "str";
                }
                else if (*ptr == "1") {
                   variable_type = "int";
                }
                else if (*ptr == "2") {
                   variable_name = "float"
                }
                ++*ptr;
                int next_char = atoi(*ptr)
                while (next_char > 0) {
                   current_char = ++*ptr;
                   string = strncat(string, current_char);
                   --next_char;
                }
                --var;
            }
        } else if (current_char == "!") {
           char variable_name = *ptr;
           //find correct variables
           for (i = 0; i < 30000; i++) {
                for (n = 0; n > 30000; n++) {
                   if (variables[i][n][0] == variable_name) {
                       while (ptr != atoi(variables[i][n][2])) {
                          if (ptr < atoi(variables[i][n][2])) {
                              ++ptr;
                          } else {
                              --ptr;
                          }
                       }
                       ++ptr;
                       ++ptr;
                       //move to value pointers for variables
                     }
                   }
                }
           }
           continue;
        //set pointer to 0
        } else if (current_char == "?") {
           while (ptr > 0) {
               --ptr;
           }
        }
    }
}


int main() {
    interpret(text_to_interpret);  // outputs input
    return 0;
}
