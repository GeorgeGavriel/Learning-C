#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fin,*fout;
    char inputfile[100],outputfile[100];
    printf("Please enter the name of the input file. \nFilename :");
    scanf("%s",inputfile);
    printf("Please enter the name of the output file. \nFilename :");
    scanf("%s",outputfile);
    fin=fopen(inputfile,"r");
    fout=fopen(outputfile,"r");

    if (fin == NULL)
    {
        printf("Error: Could not open input file.\n");
        exit(EXIT_FAILURE);
    }
    if (fout == NULL)
    {
        printf("Error: Could not open output file.\n");
        exit(EXIT_FAILURE);        
    }
    fprintf(fout,"Statistics for file: %s\n",outputfile);
    fprintf(fout,"------------------------------------------------------------------------ \n");















    printf("Processing complete. \n");
    fclose(fin);fclose(fout);
    return 0;
}