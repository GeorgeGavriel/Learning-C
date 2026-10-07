#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50

/* 
 * Πρωτότυπα Συναρτήσεων (Function Prototypes)
 */
int load_data(const char *filename, char names[][MAX_NAME_LEN], double *averages);
void to_uppercase(char *str);
int find_highest_avg_index(const double *averages, int count);
void filter_and_save(const char *filename, const char names[][MAX_NAME_LEN], const double *averages, int count, double cutoff);


int main(void) {
    char names[MAX_ITEMS][MAX_NAME_LEN];
    double averages[MAX_ITEMS];
    int count;

    printf("=== ΕΝΑΡΞΗ ΠΡΟΓΡΑΜΜΑΤΟΣ ΕΞΕΤΑΣΗΣ (2o ΘΕΜΑ) ===\n\n");

    // 1. Ανάγνωση δεδομένων και υπολογισμός μέσων όρων
    count = load_data("data.txt", names, averages);
    if (count < 0) {
        printf("Σφάλμα κατά το άνοιγμα του αρχείου data.txt!\n");
        return EXIT_FAILURE;
    }

    printf("Διαβάστηκαν %d εγγραφές από το αρχείο data.txt.\n\n", count);

    // 2. Μετατροπή όλων των ονομάτων σε κεφαλαία (Uppercase)
    for (int i = 0; i < count; i++) {
        to_uppercase(names[i]);
    }

    // 3. Εύρεση της εγγραφής με τον μεγαλύτερο μέσο όρο
    int best_index = find_highest_avg_index(averages, count);
    if (best_index != -1) {
        printf("Υψηλότερος μέσος όρος: %.2f (Ονομασία: %s)\n\n", 
               *(averages + best_index), names[best_index]);
    }

    // 4. Φιλτράρισμα και εγγραφή σε νέο αρχείο (μόνο όσα έχουν μέσο όρο >= 50.0)
    filter_and_save("passed.txt", names, averages, count, 50.0);

    printf("Τα αποτελέσματα αποθηκεύτηκαν επιτυχώς στο passed.txt.\n");

    return EXIT_SUCCESS;
}


/* =========================================================================
 * ΖΗΤΟΥΜΕΝΑ ΣΥΝΑΡΤΗΣΕΩΝ (Πρέπει να συμπληρώσετε τον κώδικα)
 * ========================================================================= */

/**
 * ΖΗΤΟΥΜΕΝΟ 1:
 * Διαβάζει από το αρχείο 'filename' γραμμή προς γραμμή.
 * Κάθε γραμμή περιέχει ένα string (όνομα) και 3 ακέραιους βαθμούς (g1, g2, g3).
 * - Αποθηκεύει το όνομα στον πίνακα 'names'.
 * - Υπολογίζει τον μέσο όρο των 3 βαθμών: (g1 + g2 + g3) / 3.0 
 *   και τον αποθηκεύει στον πίνακα 'averages'.
 * - Χρησιμοποιήστε fopen (mode "r"), fscanf και fclose.
 * - Επιστρέφει το πλήθος των εγγραφών που διαβάστηκαν, ή -1 σε περίπτωση σφάλματος.
 * 
 * ΑΠΑΙΤΗΣΗ: Χρησιμοποιήστε ΑΡΙΘΜΗΤΙΚΗ ΔΕΙΚΤΩΝ για την προσπέλαση και την
 *           αποθήκευση στον πίνακα 'averages' (δηλαδή *(averages + i) = ...).
 */
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


/**
 * ΖΗΤΟΥΜΕΝΟ 2:
 * Μετατρέπει όλους τους μικρούς λατινικούς χαρακτήρες του 'str' σε κεφαλαίους.
 * (Υπόδειξη: Αν ένα char 'c' είναι μεταξύ 'a' και 'z', μετατρέπεται σε 'A' + (c - 'a')).
 * 
 * ΑΠΑΙΤΗΣΗ: Χρησιμοποιήστε ΑΡΙΘΜΗΤΙΚΗ ΔΕΙΚΤΩΝ (π.χ. μετακίνηση δείκτη ptr++)
 *           και ΟΧΙ αγκύλες [i].
 */
void to_uppercase(char *str) {
    
    
    while(*str!='\0'){
        if(*str>='a'&& *str<='z'){
            *str=*str - ('a' - 'A');
        }
        str++;

    }
}


/**
 * ΖΗΤΟΥΜΕΝΟ 3:
 * Βρίσκει και επιστρέφει τον δείκτη (index: 0, 1, 2...) του μεγαλύτερου στοιχείου 
 * στον πίνακα 'averages'. Αν ο πίνακας είναι κενός (count <= 0), επιστρέφει -1.
 * 
 * ΑΠΑΙΤΗΣΗ: Χρησιμοποιήστε ΑΡΙΘΜΗΤΙΚΗ ΔΕΙΚΤΩΝ για την προσπέλαση των στοιχείων 
 *           του πίνακα 'averages'.
 */
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


/**
 * ΖΗΤΟΥΜΕΝΟ 4:
 * Δημιουργεί ένα νέο αρχείο 'filename' (mode "w").
 * Γράφει στο αρχείο μόνο όσες εγγραφές έχουν μέσο όρο μεγαλύτερο ή ίσο με 'cutoff'.
 * 
 * Μορφή αρχείου εξόδου (παράδειγμα για cutoff = 50.0):
 * C_LANGUAGE: 85.00
 * STRINGS_AND_FILES: 95.00
 * POINTERS_AND_MEMORY: 51.67
 * 
 * ΑΠΑΙΤΗΣΗ:
 * - Χρήση fopen, fprintf, fclose.
 * - Χρησιμοποιήστε ΑΡΙΘΜΗΤΙΚΗ ΔΕΙΚΤΩΝ για την ανάγνωση των τιμών από τον πίνακα 'averages'.
 */
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