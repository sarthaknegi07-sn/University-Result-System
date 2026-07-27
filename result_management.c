#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_ID_LEN 20
#define FILE_NAME "results.dat"

typedef struct {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    float marks[5];
    float percentage;
    char grade[3];
} Student;


// Function declarations
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int is_valid_name(const char *name);
int is_valid_id(const char *id);
int idExists(char id[]);
void calculateResult(Student *s);
void clear_input_buffer();


// Main Function
int main() {

    int choice;

    do {

        printf("\n====================================\n");
        printf(" UNIVERSITY RESULT MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Student Result\n");
        printf("2. View All Results\n");
        printf("3. Search Student By ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        clear_input_buffer();


        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }


    }while(choice!=6);


    return 0;
}



// Clear input buffer
void clear_input_buffer()
{
    int c;

    while((c=getchar())!='\n' && c!=EOF);
}



// Validate name
int is_valid_name(const char *name)
{
    int letter=0;

    for(int i=0; name[i]!='\0'; i++)
    {
        if(!isalpha(name[i]) && name[i]!=' ')
            return 0;

        if(isalpha(name[i]))
            letter=1;
    }

    return letter;
}



// Validate ID
int is_valid_id(const char *id)
{
    for(int i=0; id[i]!='\0'; i++)
    {
        if(!isalnum(id[i]))
            return 0;
    }

    return strlen(id)>0;
}



// Check duplicate ID
int idExists(char id[])
{
    Student s;

    FILE *fp=fopen(FILE_NAME,"rb");


    if(fp==NULL)
        return 0;


    while(fread(&s,sizeof(Student),1,fp))
    {
        if(strcmp(s.id,id)==0)
        {
            fclose(fp);
            return 1;
        }
    }


    fclose(fp);

    return 0;
}



// Calculate percentage and grade
void calculateResult(Student *s)
{

    float total=0;


    for(int i=0;i<5;i++)
    {
        total += s->marks[i];
    }


    s->percentage = total/5;



    if(s->percentage >= 90)
        strcpy(s->grade,"A+");

    else if(s->percentage >=80)
        strcpy(s->grade,"A");

    else if(s->percentage >=70)
        strcpy(s->grade,"B");

    else if(s->percentage >=60)
        strcpy(s->grade,"C");

    else
        strcpy(s->grade,"F");

}



// Add Student
void addStudent()
{

    Student s;


    FILE *fp=fopen(FILE_NAME,"ab");


    if(fp==NULL)
    {
        printf("File error!\n");
        return;
    }



    do
    {
        printf("\nEnter Student Name: ");

        fgets(s.name,MAX_NAME_LEN,stdin);

        s.name[strcspn(s.name,"\n")]='\0';


        if(!is_valid_name(s.name))
            printf("Invalid name!\n");


    }while(!is_valid_name(s.name));




    do
    {

        printf("Enter Student ID: ");

        scanf("%s",s.id);

        clear_input_buffer();



        if(!is_valid_id(s.id))
            printf("Invalid ID!\n");


        else if(idExists(s.id))
            printf("ID already exists!\n");


        else
            break;


    }while(1);





    for(int i=0;i<5;i++)
    {

        do
        {

            printf("Enter marks for Subject %d: ",i+1);

            scanf("%f",&s.marks[i]);


            if(s.marks[i]<0 || s.marks[i]>100)
                printf("Marks should be between 0-100\n");


        }while(s.marks[i]<0 || s.marks[i]>100);

    }


    clear_input_buffer();



    calculateResult(&s);



    fwrite(&s,sizeof(Student),1,fp);


    fclose(fp);


    printf("\nStudent added successfully!\n");

}




// View Students
void viewStudents()
{

    Student s;


    FILE *fp=fopen(FILE_NAME,"rb");


    if(fp==NULL)
    {
        printf("No records found!\n");
        return;
    }



    printf("\n========== STUDENT RESULTS ==========\n");



    while(fread(&s,sizeof(Student),1,fp))
    {

        printf("\nName : %s",s.name);

        printf("\nID : %s",s.id);


        printf("\nMarks:");

        for(int i=0;i<5;i++)
        {
            printf("\nSubject %d : %.2f",i+1,s.marks[i]);
        }


        printf("\nPercentage : %.2f%%",s.percentage);

        printf("\nGrade : %s\n",s.grade);

        printf("-----------------------------------\n");

    }



    fclose(fp);

}




// Search Student
void searchStudent()
{

    Student s;

    char id[MAX_ID_LEN];


    FILE *fp=fopen(FILE_NAME,"rb");



    if(fp==NULL)
    {
        printf("No records found!\n");
        return;
    }



    printf("Enter Student ID: ");

    scanf("%s",id);

    clear_input_buffer();




    while(fread(&s,sizeof(Student),1,fp))
    {

        if(strcmp(s.id,id)==0)
        {

            printf("\nStudent Found!\n");

            printf("Name : %s\n",s.name);

            printf("Percentage : %.2f%%\n",s.percentage);

            printf("Grade : %s\n",s.grade);


            fclose(fp);

            return;
        }

    }



    printf("Student not found!\n");


    fclose(fp);

}





// Update Student
void updateStudent()
{

    Student s;

    char id[MAX_ID_LEN];

    int found=0;



    FILE *fp=fopen(FILE_NAME,"rb+");



    if(fp==NULL)
    {
        printf("No records found!\n");
        return;
    }




    printf("Enter Student ID to update: ");

    scanf("%s",id);

    clear_input_buffer();



    while(fread(&s,sizeof(Student),1,fp))
    {

        if(strcmp(s.id,id)==0)
        {

            printf("Enter new name: ");

            fgets(s.name,MAX_NAME_LEN,stdin);

            s.name[strcspn(s.name,"\n")]='\0';



            for(int i=0;i<5;i++)
            {
                printf("Enter marks for Subject %d: ",i+1);

                scanf("%f",&s.marks[i]);
            }


            clear_input_buffer();



            calculateResult(&s);



            fseek(fp,-sizeof(Student),SEEK_CUR);


            fwrite(&s,sizeof(Student),1,fp);


            found=1;

            break;

        }

    }



    fclose(fp);



    if(found)
        printf("Record updated successfully!\n");

    else
        printf("Student not found!\n");

}




// Delete Student
void deleteStudent()
{

    Student s;

    char id[MAX_ID_LEN];


    FILE *fp=fopen(FILE_NAME,"rb");

    FILE *temp=fopen("temp.dat","wb");



    if(fp==NULL)
    {
        printf("No records found!\n");
        return;
    }



    printf("Enter Student ID to delete: ");

    scanf("%s",id);

    clear_input_buffer();



    int found=0;



    while(fread(&s,sizeof(Student),1,fp))
    {

        if(strcmp(s.id,id)!=0)
        {
            fwrite(&s,sizeof(Student),1,temp);
        }

        else
        {
            found=1;
        }

    }



    fclose(fp);

    fclose(temp);



    remove(FILE_NAME);

    rename("temp.dat",FILE_NAME);



    if(found)
        printf("Record deleted successfully!\n");

    else
        printf("Student not found!\n");

}
