#include <stdio.h>
#include <stdlib.h>

void read_file(char *file_name);
void flags_parser(char *flags, int argc, char **argv, int *index);
void help_function();

int main(int argc, char **argv) {

    char flags[7] = "\0";
    int index_end_flags = 1;

    for (int i = 1; i < argc; i++){ 
    flags_parser(flags, argc, argv, &index_end_flags);
    read_file(argv[i]);
  }
  
  return 0;
}

void read_file(char *file_name){
    FILE *fptr;
    char c;
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }else{
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
  
    fclose(fptr);
    
    }
}

void flags_parser(char *flags, int argc, char **argv, int *index) {
  // loop through all arguments, except first -> (command name)
  for (int i = 1; i < argc; i++) {
    if(argv[i][0] == '-' && argv[i][i] == '-'){
      for (size_t j = 2; j < strlen(argv[i]); j++) {
        append_flags(flags, argv[i][j]);
        //printf("%c", argv[i][j]);
      }
      
    }else if(argv[i][0] == '-' && argv[i][i] != '-'){
            for (size_t j = 1; j < strlen(argv[i]); j++) {
              append_flags(flags, argv[i][j]);
                //printf("%c", argv[i][j]);
            }
        }                                                             
    } 
}