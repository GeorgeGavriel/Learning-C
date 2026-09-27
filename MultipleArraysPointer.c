#include <stdio.h>
#define rows 5
#define colums 5
void readarray(int* array);
void printarray(int* array);
void printtable_reverse(int* array);
void findlargestoftable(int* array);
void findlargestofrow(int* array);
void findlargestofcolum(int* array);

int main(){
    int* p=NULL;
    int  array[rows][colums]={
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    //int  array[rows][colums];
    p=&array[0][0];
    
    /* for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
        printf("Give a number : ");
        scanf("%d",&num);
        array[i][j]=num;
        }
    } */
    /* printf("The array is  \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<colums;j++){
        printf("%d\t",array[i][j]);
        }
        printf("\n");
    } */
    //readarray(p);
    printarray(p);
    printtable_reverse(p);
    findlargestoftable(p);
    findlargestofrow(p);
    findlargestofrow(&array[4][0]); // 4 is the last row
    //findlargestofcolum(p);//not working need modification
    return 0;
}
void readarray(int* array){
    printf("Give the numbers for the array   \n");
    int num;
    for(int* p=array;p<array+ (rows*colums);p++){
        printf("Give a number : ");
        scanf("%d",&num);
        *p=num;
    }



}
void printarray(int* array){
    printf("The array is  \n");
    for(int* p=array;p<array+ (rows*colums);p++){
        printf("%d\t",*p);
        if(((p - array) + 1) % colums == 0)
            printf("\n");
    }

}
void printtable_reverse(int* array){
    printf("The REVERSE table is : \n");
    for(int* p=array+rows*colums-1;p>=array;p--){
        printf("%d\t",*p);
        if ((p - array) % colums == 0) {
            printf("\n");
    }
}
}
void findlargestoftable(int* array){
    int max=*array,*pmax=array;
    for(int* p=array;p<array+ (rows*colums);p++){
        if(*p>max){
            max=*p;
            pmax=p;
        }
    }
    printf("\nThe largest Number FOR THE TABLE is   :   %d    and is in the position   :   %p   \n",max,pmax);


}
void findlargestofrow(int* array){
    int max=*array,*pmax=array;
    for(int* p=array;p<array+rows;p++){
        if(*p>max){
            max=*p;
            pmax=p;
        }
    }
    printf("\nThe largest Number FOR THE ROW is   :   %d    and is in the position   :   %p   \n",max,pmax);
}
/* void findlargestofcolum(int* array){
    int max=*array,*pmax=array;
    for(int* p=array;p<array+colums;p+=rows){
        if(*p>max){
            max=*p;
            pmax=p;
        }
    }
    printf("\nThe largest Number FOR THE COLUM is   :   %d    and is in the position   :   %p   \n",max,pmax);
} */








