#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50

int readStudents(const char *filename, char names[][MAX_NAME],int grades[], int maxStudents);
int readStudents(const char *filename, char names[][MAX_NAME],int grades[], int maxStudents){
    FILE *fin=fopen(filename,"r");
    if (fin==NULL)
        return -1;
    int count=0;
    char name[MAX_NAME];
    float grade;
    while(count<maxStudents && fscanf(fin,"%s %f",name,&grade)==2){
            strcpy(*names, name);
            *grades=grade;
            names++;grades++;count++;
    }   
    fclose(fin);
    return count;

}


void printStudents(char names[][MAX_NAME], int grades[], int count);
void printStudents(char names[][MAX_NAME], int grades[], int count){
    int i=0;
    while(i<count){
        printf("Name :\t%s\t Grade : \t%d\n",*names,*grades);
        names++;grades++;
        i++;
    }
}

int findStudent(char names[][MAX_NAME], int count, const char *name);
int findStudent(char names[][MAX_NAME], int count, const char *name){
    int i=0;
    while(i<count){
        if(strcmp(*names, name) == 0)
            return i;
    i++;names++;
    }
    return -1;


}

double calculateAverage(int grades[], int count);
double calculateAverage(int grades[], int count){
    int i=0;double sum=0;
    if (count==0){
        return 0;
    }
    while(i<count){
        sum+=*grades;
        i++;grades++;
    }
    return sum/count; 
    
}
void findHighest(char names[][MAX_NAME], int grades[], int count,char *highestName, int *highestGrade);
void findHighest(char names[][MAX_NAME], int grades[], int count,char *highestName, int *highestGrade){
    if (count <= 0) return;
    int i=0;
    *highestGrade=*grades;
    strcpy(highestName,*names);
    while(i<count){
        if(*grades>*highestGrade){
            *highestGrade=*grades;
            strcpy(highestName,*names);
        }
        grades++;
        names++;
        i++;
    }

}

void savePassedStudents(const char *filename, char names[][MAX_NAME],int grades[], int count, int minGrade);
void savePassedStudents(const char *filename, char names[][MAX_NAME],int grades[], int count, int minGrade){
    FILE *fout=fopen(filename,"w");
    int i=0;

    while(i<count){
        if (*grades>=minGrade){
            fprintf(fout,"%s %d\n",*names,*grades);

        }
        names++;grades++;i++;
    }
    fclose(fout);
}

int main(void)
{
        char names[MAX_STUDENTS][MAX_NAME];
        int grades[MAX_STUDENTS];
        int count;

        char searchName[MAX_NAME];

        char highestName[MAX_NAME];
        int highestGrade;

        count = readStudents("students.txt", names, grades, MAX_STUDENTS);

        if (count == -1)
        {
            printf("Error opening file.\n");
            return 1;
        }

        printf("Students:\n");
        printStudents(names, grades, count);

        printf("\nEnter a name to search: ");
        scanf("%49s", searchName);

        int position = findStudent(names, count, searchName);

        if (position == -1)
            printf("Student not found.\n");
        else
            printf("%s has grade %d.\n",
                names[position], grades[position]);

        printf("\nAverage grade: %.2f\n",
            calculateAverage(grades, count));

        findHighest(names, grades, count,
                    highestName, &highestGrade);

        printf("Highest grade: %s (%d)\n",
            highestName, highestGrade);

        savePassedStudents("passed.txt",
                        names, grades, count, 50);

        printf("\nPassed students saved to passed.txt\n");

        return 0;
}