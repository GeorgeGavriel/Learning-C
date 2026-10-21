#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float grade;
} Student;

int main(void) {
    int initial_count, extra_count, total_count;
    Student *students = NULL;
    Student *temp_buffer = NULL;
    float sum = 0.0;
    float max_grade = -1.0;
    int top_student_id = -1;

    // 1. Διάβασμα αρχικού πλήθους και δέσμευση με calloc
    printf("Dwste to arxiko plithos foititon: ");
    scanf("%d", &initial_count);

    // TODO: Δέσμευση με calloc για τον πίνακα students και έλεγχος
    students=(Student *)calloc(initial_count,sizeof(Student));
    if(students==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }

    // TODO: Διάβασμα αρχικών φοιτητών (id και grade)
    for(int i=0;i<initial_count;i++){
        int id;
        float grade;
        printf("Give the ID and then the GRADE\n");
        scanf("%d %f",&id,&grade);
        (students+i)->id=id;
        (students+i)->grade=grade;

    }


    // 2. Διάβασμα επιπλέον πλήθους και δέσμευση προσωρινού με malloc
    printf("Dwste to plithos ton epipleon foititon: ");
    scanf("%d", &extra_count);

    // TODO: Δέσμευση με malloc για τον temp_buffer και έλεγχος
    temp_buffer=(Student *)malloc(extra_count*sizeof(Student));
    if (temp_buffer==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }


    // TODO: Διάβασμα επιπλέον φοιτητών στον temp_buffer
    for(int i=0;i<extra_count;i++){
        int id;
        float grade;
        printf("Give the ID and then the GRADE\n");
        scanf("%d %f",&id,&grade);
        (temp_buffer+i)->id=id;
        (temp_buffer+i)->grade=grade;

    }   

    // 3. Επέκταση αρχικού πίνακα με realloc
    total_count = initial_count + extra_count;

    // TODO: Χρησιμοποίησε την realloc για να μεγαλώσεις τον πίνακα students
    Student *p=(Student*)realloc(students,total_count*sizeof(Student));
    if(p==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }    
    students=p;
    // TODO: Αντέγραψε τα δεδομένα από τον temp_buffer και κάνε free τον temp_buffer
    for(int i=0;i<extra_count;i++){
        *(students+i+initial_count)=*(temp_buffer+i);
    }
    free(temp_buffer);

    // 4. Υπολογισμός μέσου όρου και εύρεση αριστούχου
    for(int i=0;i<total_count;i++){
        float grade=((students+i)->grade);
        sum=sum+grade;
        if(grade>=max_grade){
            max_grade=grade;
            top_student_id=((students+i)->id);
        }
    }
    
    // TODO: Υπολόγισε τον μέσο όρο βαθμολογίας και βρες ποιος έχει τον μεγαλύτερο βαθμό
    float avg=(float)sum/total_count;


    // TODO: Εμφάνισε τα αποτελέσματα και αποδέσμευσε την τελική μνήμη (free)
    printf("The average grade is %.2f\n",avg);
    printf("The top student ID IS %d and his top grade is %.2f\n",top_student_id,max_grade);
    free(students);
    return EXIT_SUCCESS;
}