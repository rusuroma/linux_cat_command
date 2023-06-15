#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

void read_file(char *file_name);
const char* flags_parser(char *flags, int argc, char **argv);
void help_function();



int main(int argc, char **argv) {

    bool number = false;
    bool number_nonblank = false;

    char flags[7] = "\0";
    int index_end_flags = 1;
    
    //for (int i = 1; i < argc; i++){ 
    const char* flags_parser(flags, argc, argv);

 // }
  //printf("%s", flags_parser(flags, argc, argv));
    char *given_flags = flags_parser(flags, argc, argv);
    for (size_t i = 0; i < strlen(given_flags); i++)
    {
        char f = given_flags[i];

        switch (f)
        {
        case 'b':
            
            break;
        
        default:
            help_function();
        }
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

const char* flags_parser(char *flags, int argc, char **argv) {
  // loop through all arguments, except first -> (command name)
  for (int i = 1; i < argc; i++) {
    //printf("%c", argv[i][1]);
    if(argv[i][0] == '-' && argv[i][1] == '-'){
      for (size_t j = 2; j < strlen(argv[i]); j++) {
       //append_flags(flags, argv[i][j]);
        //printf("%c", argv[i][j]);
         if(!isdigit(argv[i][j])){
            strncat(flags, &argv[i][j], 1);
        }else{
            printf("The flag is not valid, must be a letter ! \n");
            exit(0);
        }

            }
        
      
    }else if(argv[i][0] == '-' && argv[i][1] != '-'){
            for (size_t j = 1; j < strlen(argv[i]); j++) {
              //append_flags(flags, argv[i][j]);
                //printf("%c", argv[i][j]);
                if(!isdigit(argv[i][j])){
                    strncat(flags, &argv[i][j], 1);
                }else{
                    printf("The flag is not valid, must be a letter ! \n");
                    exit(0);
                }   
            }
        }                                                             
    } 
    return flags;
}

void help_function(){

     printf("Usage: cat [OPTION]... [FILE]...\n");
     printf("Concatenate FILE(s) to standard output.\n");
     printf("\n");
     printf("With no FILE, or when FILE is -, read standard input.\n");
     printf("\n");
     fputs (("\
\n\
  -A, --show-all           display TAB characters as ^I, display $ at end of each line and \n\
  -b, --number-nonblank    number nonempty output lines, overrides -n\n\
  -E, --show-ends          display $ at end of each line\n\
  -n, --number             number all output lines\n\
  -T, --show-tabs          display TAB characters as ^I\n\
"), stdout);

    printf("\
\n\
Examples:\n\
  cat file  Output file's contents.\n\
  cat        Copy standard input to standard output.\n\
");
}