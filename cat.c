#include <stdio.h>
#include <stdlib.h>

void read_file(char *file_name);

int main(int argc, char **argv) {

    for (int i = 1; i < argc; i++){ 
    read_file(argv[i]);
    printf("\n");         
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