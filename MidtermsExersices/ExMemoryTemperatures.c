#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int initial_count, extra_count, total_count;
    float *temperatures = NULL;
    float *temp_buffer = NULL;
    float sum = 0.0;

    // 1. Διάβασμα αρχικού πλήθους και δέσμευση με calloc
    printf("Dwste to arxiko plithos thermokrasion: ");
    scanf("%d", &initial_count);

    // TODO: Χρησιμοποιήστε την calloc για τον πίνακα temperatures
    // Ελέγξτε αν η δέσμευση πέτυχε
    temperatures=(float *)calloc(initial_count,sizeof(float));
    if(temperatures==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }

    // TODO: Διαβάστε τις αρχικές θερμοκρασίες με επανάληψη
    printf("give the temperatures :\n");
    for(int i=0;i<initial_count;i++){
        float val=0;
        scanf("%f",&val);
        *temperatures=val;
        temperatures++;
    }
    for(int i=0;i<initial_count;i++){
        temperatures--;
    }


    // 2. Διάβασμα επιπλέον πλήθους και δέσμευση προσωρινού πίνακα με malloc
    printf("Dwste to plithos ton epipleon thermokrasion: ");
    scanf("%d", &extra_count);

    // TODO: Χρησιμοποιήστε την malloc για τον temp_buffer
    // Ελέγξτε αν η δέσμευση πέτυχε
    temp_buffer=(float *)malloc(extra_count*sizeof(float));
    if(temp_buffer==NULL){
        exit(EXIT_FAILURE);
    }

    // TODO: Διαβάστε τις επιπλέον θερμοκρασίες στον temp_buffer
    for(int i=0;i<extra_count;i++){
        float val=0;
        scanf("%f",&val);
        *temp_buffer=val;
        temp_buffer++;
    }
    for(int i=0;i<extra_count;i++){
        temp_buffer--;
    }


    // 3. Επέκταση αρχικού πίνακα με realloc
    total_count = initial_count + extra_count;
   
   
    
    // TODO: Χρησιμοποιήστε την realloc για να μεγαλώσετε τον πίνακα temperatures
    // Ελέγξτε αν η επέκταση πέτυχε
    float *p;
    p=(float *)realloc(temperatures,total_count*sizeof(float));
    if(p==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }

    // TODO: Αντιγράψτε τα δεδομένα από τον temp_buffer στις νέες θέσεις του temperatures
    // Αποδεσμεύστε τον temp_buffer
    //free(temperatures); h reallco katharizi moni ths automata to temperatures
    temperatures=p;
    for(int i=0;i<initial_count;i++){
        temperatures++;
    }
    for(int i=0;i<extra_count;i++){
        *temperatures=*temp_buffer;
        temperatures++;temp_buffer++;
    }
    for(int i=0;i<total_count;i++){
        temperatures--;
    }
    for(int i=0;i<extra_count;i++){
        temp_buffer--;
    }
    free(temp_buffer);
    // 4. Υπολογισμός μέσου όρου και εκτύπωση
    // TODO: Υπολογίστε το άθροισμα και τη μέση τιμή όλων των στοιχείων

    float avg=0;
    for(int i=0;i<total_count;i++){
        sum=sum+*temperatures;
        temperatures++;
    }
    avg=(float)sum/total_count;
    printf("The average of all the tempratures is :%.2f\n",avg);
    // TODO: Αποδέσμευση τελικής μνήμης
    free(p);
    return EXIT_SUCCESS;
} 