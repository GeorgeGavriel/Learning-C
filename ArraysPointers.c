#include <stdio.h>
#define N 10
void   readarray(int* table);
void printtable(int* table);
void printtable_reverse(int* table);
void findlargest(int* table);

int main(){
    int table[N];
    int *pa=NULL;
    pa=&table[0];    

    readarray(pa);
    printtable(pa);
    printtable_reverse(pa);
    findlargest(pa);



    return 0;
}
void   readarray(int* table){
    int x;
    //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΤΙΜΗΣ ------------------//
    /* for(int i=0;i<N;i++){
        printf("Give a number : ");
        scanf("%d",&x);
        *table=x;
        table++;
    } */
    //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΔΕΙΚΤΟΝ ------------------//
   for(int* p=table;p<table+N;p++){
        printf("Give a number : ");
        scanf("%d",p);      
    }
}  

void printtable(int* table){
    printf("The table is : \t");
    //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΤΙΜΗΣ ------------------//
    /* for (int i=0 ; i<N;i++){
       printf("%d    ",*table);
       table++;
    } */
   //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΔΕΙΚΤΟΝ ------------------//
    for (int* p=table ; p<table+N;p++){
       printf("%d    ",*p);
    }
    printf("\n");
}
void printtable_reverse(int* table){
    printf("The REVERSE table is : \t");
    //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΤΙΜΗΣ ------------------//
    /* for (int i=N-1; i>=0;i--){
       printf("%d    ",*(table+i));
    } */
   //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΔΕΙΚΤΟΝ ------------------//
   for (int* p=table+N-1; p>=table;p--){
       printf("%d    ",*p);
    }
    printf("\n");
}
void findlargest(int* table){
    int max=-2147440,* pmax=NULL;
   //------------ΑΡΙΘΜΙΤΙΚΗ ΔΙΑ ΔΕΙΚΤΟΝ ------------------//
    for(int* p=table;p<table+N;p++){
        if(*p>max){
            max=*p;
            pmax=p;
        }
    }
    printf("The largest Number is   :   %d    and is in the position   :   %p   \n",max,pmax);
}


