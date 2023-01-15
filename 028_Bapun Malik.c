#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
char student[100][4][20];
int rollno[100];
int dob[100][3];
int i = 0;

void insert();
void display();
void update();
void delete();
int calculateAge(int birth_year, int birth_month, int birth_day);
int main()
{
    int opt;
    while (1)
    {
        printf("\t1.Insert\n\t2.Display\n\t3.Update\n\t4.Delete\n\t5.Exit\n\n");
        printf("Choose an Option :");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        case 4:
        delete();
        break;
        default:
            break;
        }
    }
}
void insert()
{
    int roll;
    printf("Enter Student Roll Number :");
    scanf("%d", &roll);
    for (int j = 0; j < 100; j++)
    {
        if (rollno[j] == roll)
        {
            printf("Rollnumber already Exist\n");
            exit(0);
        }
    }
    rollno[i] = roll;
    fflush(stdin);
    printf("Enter Student Name :");
    gets(student[i][0]);
    printf("Enter Department :");
    gets(student[i][1]);
    printf("Enter Semester in words :");
    gets(student[i][2]);
    printf("Enter Address :");
    gets(student[i][3]);
    printf("Enter Date of Birth(dd/mm/yyyy) :");
    scanf("%d/%d/%d", &dob[i][0], &dob[i][1], &dob[i][2]);
    fflush(stdin);
    i++;
}

void display()
{
    int roll,age,flag=0;
    printf("Enter Roll Number :");
    scanf("%d", &roll);
    for (int j = 0; rollno[j] != 0; j++)
    {
        if (rollno[j] == roll)
        {   
            flag=1;
            age=calculateAge(dob[j][2], dob[j][1], dob[j][0]);
            printf("Name :%s\nRoll No :%d\nDept :%s\nSem :%s\nAddress :%s\nDOB :%d/%d/%d\nAge :%d\n\n", student[j][0], rollno[j], student[j][1], student[j][2], student[j][3], dob[j][0], dob[j][1], dob[j][2],age);
        }
    }
    if(flag==0)
    {
        printf("Roll Number Not Found\n");
    }
}

void update()
{
    int roll, flag = 0;
    printf("Enter Roll Number you want to Update :");
    scanf("%d", &roll);
    for (int j = 0; rollno[j] != 0; j++)
    {
        if (rollno[j] == roll)
        {
            flag = 1;
            fflush(stdin);
            printf(" Enter Updated Student Name :");
            gets(student[j][0]);
            printf(" Enter Updated Department :");
            gets(student[j][1]);
            printf(" Enter Updated Semester in words :");
            gets(student[j][2]);
            printf(" Enter Updated Address :");
            gets(student[j][3]);
            printf(" Enter Updated Date of Birth(dd/mm/yyyy) :");
            scanf("%d/%d/%d", &dob[j][0], &dob[j][1], &dob[j][2]);
            fflush(stdin);
        }
    }
    if(flag==0)
    {
        printf("Roll Number Not Found !\n");
    }
}

void delete()
{
    int roll,flag=0;
    printf("Enter RollNumber You want to delete :");
    scanf("%d",&roll);
    for(int j=0;rollno[j]!=0;j++)
    {
        if(rollno[j]==roll)
        {   
            flag=1;
            for(int k=j;rollno[j]!=0;k++)
            {
            rollno[k]=rollno[k+1];
            strcpy(student[k][0],student[k+1][0]);
            strcpy(student[k][1],student[k+1][1]);
            strcpy(student[k][2],student[k+1][2]);
            strcpy(student[k][3],student[k+1][3]);
            dob[k][0]=dob[k+1][0];
            dob[k][1]=dob[k+1][1];
            dob[k][2]=dob[k+1][2];
            printf("RollNumber removed Successfully\n\n");
            }
        }
    }
    if(flag==0)
    {
        printf("Roll Number not found\n");
    }
}

int calculateAge(int birth_year, int birth_month, int birth_day) {
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);
    int current_year = current_tm->tm_year + 1900;
    int current_month = current_tm->tm_mon + 1;
    int current_day = current_tm->tm_mday;

    int age_year = current_year - birth_year;
    int age_month = current_month - birth_month;
    int age_day = current_day - birth_day;

    if (age_month < 0) {
        age_year--;
        age_month += 12;
    }
    if (age_day < 0) {
        age_month--;
        age_day += 30;
    }
    return age_year;
}