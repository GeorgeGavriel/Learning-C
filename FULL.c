#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME 50




int load_data(const char *filename, char names[][MAX_NAME_LEN], double *averages) {
    FILE *fin=fopen(filename,"r");
    if (fin==NULL){
        perror("file not found");
        //exit(EXIT_FAILURE);
        return -1;
    }
    double avrg;
    int n1,n2,n3,sum,count=0;
    while (count<MAX_ITEMS && fscanf(fin,"%s %d %d %d",*(names + count),&n1,&n2,&n3)==4){
        sum=n1+n2+n3;
        avrg=(double)sum/3;
        *(averages+count)=avrg;
        count++; 
    }
    





    fclose(fin);
    return count;
}


void to_uppercase(char *str) {
    
    
    while(*str!='\0'){
        if(*str>='a'&& *str<='z'){
            *str=*str - ('a' - 'A');
        }
        str++;

    }
}


int find_highest_avg_index(const double *averages, int count) {
    if(count<=0){
        return -1;
    }
    int i=1;
    double max=*averages;
    int maxpos=0;
    averages++;
    while(i<count){
        if (*averages>=max){
            max=*averages;
            maxpos=i;
        }
        i++;averages++;

    }
    return maxpos;
}


void filter_and_save(const char *filename, const char names[][MAX_NAME_LEN], const double *averages, int count, double cutoff) {
    FILE *fout=fopen(filename,"w");
    int i=0;
    while(i<count){
        if(*averages>cutoff){
            fprintf(fout,"%s %.2f\n",*names,*averages);
        }
        names++;averages++;i++;

    }



}

int readNumbers(FILE *fp, int *arr, int n) {
    int *p = arr;
    while (p < arr + n) {
        if (fscanf(fp, "%d", p) != 1)
            break;
        p++;
    }
    return (int)(p - arr);
}

void printArray(FILE *fp, const int *arr, int n) {
    const int *p;
    for (p = arr; p < arr + n; p++)
        fprintf(fp, "%d ", *p);
    fprintf(fp, "\n");
}

int findMax(const int *arr, int n) {
    const int *p = arr + 1;
    int max = *arr;
    while (p < arr + n) {
        if (*p > max)
            max = *p;
        p++;
    }
    return max;
}

void countEvenOdd(const int *arr, int n, int *even, int *odd) {
    const int *p;
    *even = 0;
    *odd = 0;
    for (p = arr; p < arr + n; p++) {
        if (*p % 2 == 0)
            (*even)++;
        else
            (*odd)++;
    }
}

void reverseArray(int *arr, int n) {
    int *start = arr, *end = arr + n - 1, tmp;
    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

int myStrlen(const char *s) {
    const char *p = s;
    while (*p != '\0')
        p++;
    return (int)(p - s);
}

void myStrcpy(char *dst, const char *src) {
    while ((*dst = *src) != '\0') {
        dst++;
        src++;
    }
}

void reverseString(char *s) {
    char *start = s, *end = s + myStrlen(s) - 1, tmp;
    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

void toUpperStr(char *s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z')
            *s = *s - ('a' - 'A');
        s++;
    }
}

int countVowels(const char *s) {
    int count = 0;
    while (*s != '\0') {
        switch (tolower((unsigned char)*s)) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                count++;
        }
        s++;
    }
    return count;
}


int isPalindrome(const char *s) {
    const char *start = s, *end = s + myStrlen(s) - 1;
    while (start < end) {
        if (tolower((unsigned char)*start) != tolower((unsigned char)*end))
            return 0;
        start++;
        end--;
    }
    return 1;
}


void stripNewline(char *s) {
    while (*s != '\0') {
        if (*s == '\n' || *s == '\r') {
            *s = '\0';
            return;
        }
        s++;
    }
}



int strlength(const char *cs);
int strlength(const char *cs){
  if (cs == NULL) return 0;
  int count=0;
  while(*cs!='\0'){
    count++;
    cs++;
  }
  count++;
  return count;
}

char *strcopy(char *s, const char *ct);
char *strcopy(char *s, const char *ct){
    if (ct == NULL || s==NULL) return *s;
  
    char *orig_s = s; 

    while (*ct != '\0') {
        *s = *ct;
        s++;
        ct++;
    }
    *s = '\0'; // Append terminating null byte

    return orig_s;
  
}

char *strconcat(char *s, const char *ct);
char *strconcat(char *s, const char *ct){
  char *orig_s = s; 

  while(*s!='\0'){
    s++;
  }
  while(*ct!='\0'){
    *s=*ct;
    s++;ct++;
  }
  *s = '\0';
  return orig_s;
}

int strcompare(const char *cs, const char *ct);
int strcompare(const char *cs, const char *ct){
    while(*ct!='\0'&& *cs!='\0'){
      if (lcase(*cs) < lcase(*ct)){
        return -1;
      }
      if (lcase(*cs) > lcase(*ct)){
        return 1;
      }
      cs++;ct++;
    }


    // Compare the final character (one or both will be '\0')
    if (lcase(*cs) < lcase(*ct)) return -1;
    if (lcase(*cs) > lcase(*ct)) return 1;
    return 0;
}

char *stringstring(const char *cs, const char *ct);
char *stringstring(const char *cs, const char *ct){
  int counter;
	int size = strlength(ct) - 1;
	
	while(*cs != '\0') {
		
		counter = 0;
		if(*ct == *cs)
			while(*ct == *cs && *ct!='\0' && *cs!='\0') {
				ct++;
				cs++;
				counter++;
			}
		else
			cs++;
		
		// string ct was found in cs
		if (counter == size)
			return (char *)(cs - counter);
		else {
			ct = ct - counter; // pointer ct returs to the beginnning
			//cs = cs - counter + 1; 
		}
	}
	return NULL;
}





void processWords(char words[][MAX_LEN], int count, int *pShort, int *pLong) {
    // === ΓΡΑΨΤΕ ΤΟΝ ΚΩΔΙΚΑ ΣΑΣ ΕΔΩ ===
    int i=0;
    while(i<count){
        if(strlen(*words)<=5){
            (*pShort)++;
        }
        else{
            (*pLong)++;
        }
        reverseString(*words);
        i++;words++;
    }

}
void writeResultsToFile(const char *filename, char words[][MAX_LEN], int count, int shortCount, int longCount) {
    // === ΓΡΑΨΤΕ ΤΟΝ ΚΩΔΙΚΑ ΣΑΣ ΕΔΩ ===
    FILE *fout=fopen(filename,"w");
    if (fout == NULL) {
        perror("Error opening output file");
        return;
    }
    fprintf(fout,"--- STATISTICS ---\n");
    fprintf(fout," Short words (<= 5): %d\n",shortCount);
    fprintf(fout," Long words (> 5):  %d\n",longCount);
    fprintf(fout,"--- REVERSED WORDS ---\n");

    int i=0;
    while(i<count){
        fprintf(fout,"%s\n",*words);
        words++;
        i++;
    }
    fclose(fout);

}
void reverseString(char *str) {
    // === ΓΡΑΨΤΕ ΤΟΝ ΚΩΔΙΚΑ ΣΑΣ ΕΔΩ ===
    if (str == NULL || *str == '\0') {
        return;
    }
    char *start=str;
    char *end=str;

    while(*end!='\0'){
        end++;

    }
    end--;
    char temp;
    while(start<end){
        temp=*end;
        *end=*start;
        *start=temp;
        start++;end--;
    }

}

int readWordsFromFile(const char *filename, char words[][MAX_LEN]) {
    // === ΓΡΑΨΤΕ ΤΟΝ ΚΩΔΙΚΑ ΣΑΣ ΕΔΩ ===
    FILE *fin=fopen(filename,"r");
    if (fin==NULL){
        perror("Error file not found");
        return 0;
    }
    int count=0;
    while( count < MAX_WORDS && fscanf(fin, "%s", *words) == 1 ){
        words++;count++;

    }
    fclose(fin);
    return count; // Αλλάξτε το return
}
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