#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// Macro for converting an uppercase character to lowercase.
#define lcase(x) ((x) >= 'A' && (x) <= 'Z' ? (x) + ('a' - 'A') : (x))


int main(void) {
      FILE *fin=fopen("file.txt","r");

      if(fin==NULL){
        printf("Error file not found");
      }

      char word[9999];
      int wordcount=0;
      int spacecount=0;
      int digitscount=0;
      int othercount=0;
      int charcount=0;
      while(fgets(word,sizeof(word),fin)!=NULL){
        int in_word = 0;
        //wordcount++;


        for(int i=0;i<sizeof(word)/sizeof(char);i++){
          if(word[i]==' '){
            spacecount++;
          }
          else if(word[i]>='1' && word[i]<='9'){
            digitscount++;
          }
          else if((word[i]>='a' && word[i]<='z')||(word[i]>='A' && word[i]<='Z')){
            charcount++;
          }
          else if (word[i] != '\n' && word[i] != '\r') {
            othercount++;
          }
          if (!isspace(word[i])) {
            if (!in_word) {
              wordcount++;
              in_word = 1;
            }
          }
          else {
            in_word = 0;
          }
      }






      }
 
    
 

 printf("\n=============================\n");
    printf("     FILE ANALYSIS RESULTS   \n");
    printf("=============================\n");
    printf(" Total Words      : %d\n", wordcount);
    printf(" Letters (A-Z/a-z): %d\n", charcount);
    printf(" Digits (0-9)     : %d\n", digitscount);
    printf(" Spaces           : %d\n", spacecount);
    printf(" Other Characters : %d\n", othercount);
    printf("=============================\n");






  
  return 0;
}
