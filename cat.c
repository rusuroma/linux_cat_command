#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

void read_file(char *file_name,bool number, bool number_nonblank);
const char* flags_parser(char *flags, int argc, char **argv);
void all_lines_counter(FILE *fptr, char c);
void non_blank_lines_counter(FILE *fptr, char c);
void help_function();



int main(int argc, char **argv) {

    bool number = false;
    bool number_nonblank = false;

    char flags[7] = "\0";
    int index_end_flags = 1;
    int n = 0;
    for (int i = 1; i < argc; i++){ 
    const char* flags_parser(flags, argc, argv);
    }
    char *given_flags = flags_parser(flags, argc, argv);
    n = strlen(given_flags) + 1;//point where starts files
    for (size_t i = 0; i < n-1; i++)
    {
        char f = given_flags[i];
        switch (f)
        {
        case 'n':
            number = true;
            break;
        case 'b':
            number_nonblank = true;
            break;
        default:
            help_function();
        }
    } 
    if(number && number_nonblank){
        for(int i = n; i<argc; i++ ){
            read_file(argv[i], number, number_nonblank);
        } //end for
    }else if (number && !number_nonblank){
        for(int i = n; i<argc; i++ ){
            read_file(argv[i], number, number_nonblank);
        }//end for
    }else if (!number && number_nonblank){
        for(int i = n; i<argc; i++ ){
            read_file(argv[i], number, number_nonblank);
        }//end for
    }else{
        for(int i = n; i<argc; i++ ){
            read_file(argv[i], number, number_nonblank);
        }//end for
        
    }
return 0;
}

void read_file(char *file_name, bool number, bool number_nonblank){
    FILE *fptr;
    char c;
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }else{
        if(number && !number_nonblank){
            all_lines_counter(fptr, c);
        }else if(!number && number_nonblank){
            non_blank_lines_counter(fptr, c);
        }else if(number_nonblank && number){
            non_blank_lines_counter(fptr, c);
        }else{
            c = fgetc(fptr);
            while (c != EOF)
            {
                printf("%c", c);
                c = fgetc(fptr);
            }
  
    fclose(fptr);
        }//end second else
    
    
    }// end else
}

void all_lines_counter(FILE *fptr, char c){
    int count = 1;
    c = fgetc(fptr);
    printf("    ");
    printf("%d", count);
    printf("	");
    while (c != EOF)
    {   
        if(c == '\n'){
            printf("%c", c);
            printf("    ");
            printf("%d", ++count);
            printf("  ");
            c = fgetc(fptr);
            //count++;
        }else{
            printf("%c", c);
            c = fgetc(fptr);
        }
        
    }
    printf("\n");
    fclose(fptr);

}

void non_blank_lines_counter(FILE *fptr, char c){
    char myString[1024] = "";
    memset(myString, '\0', sizeof(myString));
    int i = 0;
    int l = 0;
    while (c != EOF)
    {
        //if( fgets (myString, 1024, fptr)!=NULL ) {
      /* writing content to stdout */
        //puts(myString);
        c = fgetc(fptr);
        if(c == '\n'){
             fgets (myString, 1024, fptr);
        }
       
        
   }
    myString[i] = '\0';
    //puts(myString);
    printf("%s", myString);
    fclose(fptr);

}

const char* flags_parser(char *flags, int argc, char **argv) {
  // loop through all arguments, except first -> (command name)
  for (int i = 1; i < argc; i++) {
    //printf("%c", argv[i][1]);
    if(argv[i][0] == '-' && argv[i][1] == '-'){
      for (size_t j = 2; j < strlen(argv[i]); j++) {
       //append_flags(flags, argv[i][j]);
        printf("%c", argv[i][j]);
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