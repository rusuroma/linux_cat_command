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
    bool show_ends = false;
    bool help_fct = false;
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
        case 'E':
            show_ends = true;
            break;    
        default:
            number = false;
            number_nonblank = false;
            show_ends = false;
            help_function();
            help_fct = true;
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
    }else if(!help_fct){
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
    char myString[1024] = "";
    memset(myString, '\0', sizeof(myString));
    int count = 1;

    while(fgets(myString, 1024, fptr)) {
      printf("    ");
      printf("%d", count);
      printf("	");
      printf("%s", myString);
      count++;
    }
    printf("\n");
    fclose(fptr);
    
}

void non_blank_lines_counter(FILE *fptr, char c){
    char myString[1024] = "";
    memset(myString, '\0', sizeof(myString));
    int i = 0;
    int l = 0;
    int count = 1;
  //   while (c != EOF)
  //   {
  //       //if( fgets (myString, 1024, fptr)!=NULL ) {
  //     /* writing content to stdout */
  //       //puts(myString);
  //       c = fgetc(fptr);
  //       fgets (myString, 1024, fptr);
  //       printf("%s", myString);
       
        
  //  }
    //myString[i] = '\0';
    //puts(myString);
    //printf("%s", myString);
    while(fgets(myString, 1024, fptr)) {
      if(strlen(myString)>1){
        printf("    ");
        printf("%d", count);
        printf("	");
        printf("%s", myString);
        count++;
      }else{
        printf("%s", myString);
      }
}


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