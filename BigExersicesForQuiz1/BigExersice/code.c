#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50

int readProducts(const char *filename,char names[][MAX_NAME],double prices[],int quantities[],int maxProducts);
int readProducts(const char *filename,char names[][MAX_NAME],double prices[],int quantities[],int maxProducts){
    FILE *fin=fopen(filename,"r");
    if (fin==NULL){
        printf("file cannot be opened\n");
        return -1;
    }
    int count=0;
    int qnt=0;
    double price=0;
    char name[MAX_NAME];
    while(count<maxProducts && fscanf(fin,"%s %lf %d",name,&price,&qnt)==3){
        strcpy(*names,name);names++;
        *prices=price;prices++;
        *quantities=qnt;quantities++;
        count++;
    }

    fclose(fin);
    return count;


}

void printProducts(char names[][MAX_NAME],double prices[],int quantities[],int count);
void printProducts(char names[][MAX_NAME],double prices[],int quantities[],int count){
    int i=0;
    while(i<count){
        printf("%s - $%lf - %d\n",*names,*prices,*quantities);
        names++;prices++;quantities++;i++;
    }


}
int findProduct(char names[][MAX_NAME],int count,const char *searchName);
int findProduct(char names[][MAX_NAME],int count,const char *searchName){
    int i=0;
    while(i<count){
        if (strcmp(*names,searchName)==0)
            return i;
        names++;i++;
    }   
    return -1;
}

double calculateInventoryValue(double prices[],int quantities[],int count);
double calculateInventoryValue(double prices[],int quantities[],int count){
    int i=0;
    double sum=0;
    while(i<count){
        sum+=(*prices)*(*quantities);
        prices++;quantities++;i++;        
    }
    return sum;
}

void findMostExpensive(char names[][MAX_NAME],double prices[],int count,char *productName,double *price);
void findMostExpensive(char names[][MAX_NAME],double prices[],int count,char *productName,double *price){
    *price=*prices;
    prices++;
    strcpy(productName,*names);
    names++;
    int i=1;
    while(i<count){
        if (*prices>*price){
            strcpy(productName,*names);
            *price=*prices;    
        }     
        i++;prices++;names++;
    }



}

void saveLowStock(const char *filename,char names[][MAX_NAME],double prices[],int quantities[],int count,int limit);
void saveLowStock(const char *filename,char names[][MAX_NAME],double prices[],int quantities[],int count,int limit){
    FILE *fout=fopen(filename,"w");
    int i=0;
    while (i < count) {
        if (*quantities <= limit) {
            fprintf(fout, "%s %.2f %d\n", *names, *prices, *quantities);
        }
        names++;
        prices++;
        quantities++;
        i++;
    }


    fclose(fout);


}


int main(void)
{
    char names[MAX_PRODUCTS][MAX_NAME];
    double prices[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];

    int count;

    char searchName[MAX_NAME];

    char expensiveName[MAX_NAME];
    double expensivePrice;

    count = readProducts("products.txt",
                         names,
                         prices,
                         quantities,
                         MAX_PRODUCTS);

    if (count == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("PRODUCTS\n");
    printf("--------\n");

    printProducts(names, prices, quantities, count);

    printf("\nEnter product name to search: ");
    scanf("%49s", searchName);

    int position = findProduct(names, count, searchName);

    if (position == -1)
    {
        printf("Product not found.\n");
    }
    else
    {
        printf("Product found: %s %.2f %d\n",
               names[position],
               prices[position],
               quantities[position]);
    }

    printf("\nTotal inventory value: %.2f\n",
           calculateInventoryValue(prices,
                                   quantities,
                                   count));

    findMostExpensive(names,
                      prices,
                      count,
                      expensiveName,
                      &expensivePrice);

    printf("Most expensive product: %s (%.2f)\n",
           expensiveName,
           expensivePrice);

    saveLowStock("lowstock.txt",
                 names,
                 prices,
                 quantities,
                 count,
                 5);

    printf("\nLow-stock products saved to lowstock.txt\n");

    return 0;
}