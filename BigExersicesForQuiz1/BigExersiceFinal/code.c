#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_LEN 50

/* Πρωτότυπα Συναρτήσεων */
int readWordsFromFile(const char *filename, char words[][MAX_LEN]);
void processWords(char words[][MAX_LEN], int count, int *pShort, int *pLong);
void reverseString(char *str);
void writeResultsToFile(const char *filename, char words[][MAX_LEN], int count, int shortCount, int longCount);

/******************************************************************************
 * MAIN - ΕΤΟΙΜΗ (Δεν χρειάζεται να τροποποιήσετε τη main)
 *****************************************************************************/
int main(void) {
    char words[MAX_WORDS][MAX_LEN];
    int count = 0;
    int shortWords = 0;
    int longWords = 0;

    // 1. Ανάγνωση λέξεων από το αρχείο εισόδου
    count = readWordsFromFile("data.txt", words);
    if (count == 0) {
        printf("Δεν διαβάστηκαν λέξεις ή το αρχείο δεν βρέθηκε.\n");
        return 1;
    }

    printf("Διαβάστηκαν %d λέξεις από το data.txt.\n", count);

    // 2. Επεξεργασία λέξεων (καταμέτρηση και αντιστροφή)
    processWords(words, count, &shortWords, &longWords);

    // 3. Εγγραφή των αποτελεσμάτων στο αρχείο εξόδου
    writeResultsToFile("output.txt", words, count, shortWords, longWords);

    printf("Η επεξεργασία ολοκληρώθηκε. Ελέγξτε το output.txt!\n");

    return 0;
}

/******************************************************************************
 * ΖΗΤΟΥΜΕΝΟ 1: readWordsFromFile
 * 
 * Περιγραφή:
 *   Ανοίγει το αρχείο 'filename' για ανάγνωση. Διαβάζει συμβολοσειρές (strings)
 *   μία-μία και τις αποθηκεύει στον 2D πίνακα 'words'.
 *   Η ανάγνωση σταματά όταν φτάσουμε στο τέλος του αρχείου (EOF) ή όταν
 *   συμπληρωθεί ο μέγιστος αριθμός λέξεων (MAX_WORDS).
 * 
 * Παράμετροι:
 *   - filename: Το όνομα του αρχείου εισόδου (π.χ. "data.txt")
 *   - words: 2D πίνακας χαρακτήρων για την αποθήκευση των λέξεων
 * 
 * Επιστρέφει:
 *   - Τον συνολικό αριθμό των λέξεων που διαβάστηκαν επιτυχώς.
 *   - Αν το αρχείο αποτύχει να ανοίξει, εμφανίζει μήνυμα σφάλματος (perror) 
 *     και επιστρέφει 0.
 *****************************************************************************/
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

/******************************************************************************
 * ΖΗΤΟΥΜΕΝΟ 2: reverseString
 * 
 * Περιγραφή:
 *   Αντιστρέφει το περιεχόμενο ενός string "in-place" (στην ίδια θέση μνήμης).
 * 
 * ΚΑΝΟΝΑΣ:
 *   ΠΡΕΠΕΙ να χρησιμοποιήσετε ΑΡΙΘΜΗΤΙΚΗ ΔΕΙΚΤΩΝ (Pointer Arithmetic).
 *   ΑΠΑΓΟΡΕΥΕΤΑΙ η χρήση αγκυλών [] μέσα στη συνάρτηση.
 * 
 * Παράδειγμα:
 *   Αν str = "Apple", μετά την κλήση θα γίνει "elppA".
 * 
 * Παράμετροι:
 *   - str: Δείκτης στο πρώτο στοιχείο του string.
 *****************************************************************************/
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

/******************************************************************************
 * ΖΗΤΟΥΜΕΝΟ 3: processWords
 * 
 * Περιγραφή:
 *   Διασχίζει όλες τις λέξεις του πίνακα 'words':
 *   1. Υπολογίζει το μήκος κάθε λέξης με την strlen().
 *   2. Αν το μήκος είναι <= 5, αυξάνει την τιμή που δείχνει ο δείκτης pShort.
 *      Αλλιώς (μήκος > 5), αυξάνει την τιμή που δείχνει ο δείκτης pLong.
 *   3. Καλεί τη συνάρτηση reverseString() για να αντιστρέψει τη λέξη.
 * 
 * Παράμετροι:
 *   - words: Ο πίνακας με τις λέξεις
 *   - count: Ο αριθμός των λέξεων στον πίνακα
 *   - pShort: Δείκτης σε ακέραιο που κρατά το πλήθος των μικρών λέξεων (<=5)
 *   - pLong: Δείκτης σε ακέραιο που κρατά το πλήθος των μεγάλων λέξεων (>5)
 *****************************************************************************/
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

/******************************************************************************
 * ΖΗΤΟΥΜΕΝΟ 4: writeResultsToFile
 * 
 * Περιγραφή:
 *   Ανοίγει το αρχείο 'filename' για εγγραφή ("w").
 *   Γράφει τα στατιστικά στοιχεία και τις αντιστραμμένες λέξεις.
 * 
 * Μορφή Αρχείου Εξόδου (output.txt):
 *   --- STATISTICS ---
 *   Short words (<= 5): X
 *   Long words (> 5): Y
 *   --- REVERSED WORDS ---
 *   elppA
 *   gnimmargorp
 *   ... (κτλ)
 * 
 * Παράμετροι:
 *   - filename: Το όνομα του αρχείου εξόδου ("output.txt")
 *   - words: Ο πίνακας με τις τροποποιημένες (αντιστραμμένες) λέξεις
 *   - count: Το πλήθος των λέξεων
 *   - shortCount: Το πλήθος των μικρών λέξεων
 *   - longCount: Το πλήθος των μεγάλων λέξεων
 *****************************************************************************/
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