#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// creating a datatype to store the data of
// different students
struct student {

    char name[50];
    char phoneno[11];
    int rollno;
    char branch[30];
    int maths,eng,cse,sci;
    float res;
    char grade;

}s;


// file pointer for
// accessing and manipulating file
FILE *ptr;


// size of the student struct
long sizeofstd = sizeof(s);

// validation for phone no
bool validation(char phone[11]) {

    int c = 0;

    for(int i = 0; phone[i] != '\0'; i++) {

        // it should only contain numbers
        if(phone[i] < '0' || phone[i] > '9') {
            return false;
        }
        c++;

    }

    // length should not exceed 10 digits
    if(c > 10 || c < 10) {
        return false;
    }

    return true;

}

bool name_validation(char name[50]) {

    if(name[0] >= 'A' && name[0] <= 'Z') {

            for(int i = 1; name[i] != '\0'; i++) {

                if(((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')) || name[i] == ' ') {
                    continue;
                }
                else {
                    return false;
                }

            }

            return true;

    }

    return false;


}

bool marks_validator(int num) {

    if(num < 0 || num > 100) {
        return false;
    }

    return true;

}

char grade_calc(float per) {

    if(per >= 90) {
        return 'A';
    }
    else if(per < 90 && per >= 80) {
        return 'B';
    }
    else if(per < 80 && per >= 70) {
        return 'C';
    }
    else if(per < 70 && per >= 33) {
        return 'D';
    }
    else{
        return 'F';
    }



}


// function for inserting new record
void insert() {


    system("cls");

    // opening file using file pointer
    // opening it for appending data
    ptr = fopen("student.txt", "ab");

    // removing the data stored in buffer
    fflush(stdin);

    int sum = 0;
    float per = 0;

    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    printf("\n\t\t\t\t\tEnter Student name : ");
    gets(s.name);
    while(!name_validation(s.name)) {

        printf("\n\t\t\t\t\tInvalid Name !!!\n");
        printf("\n\t\t\t\t\tEnter again \n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Student name : ");
        gets(s.name);

    }
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Phone No : ");
    gets(s.phoneno);

    while(!validation(s.phoneno)) {
        printf("\n\t\t\t\t\tInvalid Phone No!!!\n");
        printf("\n\t\t\t\t\tEnter again \n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Phone No : ");
        gets(s.phoneno);
    }
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Rollno : ");
    scanf("%d", &s.rollno);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Branch : ");
    gets(s.branch);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Marks of Maths out of 100 : ");
    scanf("%d", &s.maths);

    while(!marks_validator(s.maths)) {
        printf("\n\t\t\t\t\tInvalid marks ...\n");
        printf("\n\t\t\t\t\tEnter marks again\n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Marks of Maths out of 100 : ");
        scanf("%d", &s.maths);
    }
    fflush(stdin);

    printf("\n\t\t\t\t\tEnter Marks of English out of 100 : ");
    scanf("%d", &s.eng);

    while(!marks_validator(s.eng)) {
        printf("\n\t\t\t\t\tInvalid marks ...\n");
        printf("\n\t\t\t\t\tEnter marks again\n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Marks of English out of 100 : ");
        scanf("%d", &s.eng);
    }
    fflush(stdin);

    printf("\n\t\t\t\t\tEnter Marks of Computer out of 100 : ");
    scanf("%d", &s.cse);

    while(!marks_validator(s.cse)) {
        printf("\n\t\t\t\t\tInvalid marks ...\n");
        printf("\n\t\t\t\t\tEnter marks again\n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Marks of Computer out of 100 : ");
        scanf("%d", &s.cse);
    }
    fflush(stdin);

    printf("\n\t\t\t\t\tEnter Marks of Science out of 100 : ");
    scanf("%d", &s.sci);

    while(!marks_validator(s.sci)) {
        printf("\n\t\t\t\t\tInvalid marks ...\n");
        printf("\n\t\t\t\t\tEnter marks again\n");
        fflush(stdin);
        printf("\n\t\t\t\t\tEnter Marks of Science out of 100 : ");
        scanf("%d", &s.sci);
    }
    fflush(stdin);

    sum = s.maths + s.eng + s.cse + s.sci;
    per = ((float)sum / 400) * 100;
    s.res = per;

    s.grade = grade_calc(per);

    // writing the data in file after
    // getting it from user
    fwrite(&s, sizeofstd, 1, ptr);
    printf("\n\t\t\t\t\tRecord saved successfully !\n");

    fflush(stdin);

    // closing the file after inserting data
    fclose(ptr);


}


// function for displaying the data
void display() {

    system("cls");
    int i =1;
    ptr = fopen("student.txt", "rb");

    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");

    if(ptr == NULL) {
        printf("\n\t\t\t\t\tFile not present");
        exit(0);
    }


    printf("\n%-10s%-30s%-23s%-15s%-15s%-20s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH", "PERCENTAGE", "GRADE");
    printf("----------------------------------------------------------------------------------------------------------------------\n");


    // reading the file
    // until end of file
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        printf("%-10d %-29s %-22s %-15d %-14s %-16.2f %-10c\n\n", i, s.name, s.phoneno, s.rollno, s.branch, s.res, s.grade);
        i++;
    }

    // closing the file after displaying the data
    fclose(ptr);


}


// function for searching by rollno
void search_by_rollno() {

    int rno = 0;
    int found = 0;
    int i = 1;


    system("cls");
    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    // getting the rollno from user to search
    printf("\n\t\t\t\t\tEnter Roll No to search : ");
    scanf("%d", &rno);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-15s%-15s%-20s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH", "PERCENTAGE", "GRADE");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    // reading the file until EOF
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // if the record rollno is equal to the searched no
        // display the content of that student
        if(rno == s.rollno) {
            printf("%-10d %-30s %-20s %-15d %-15s %-20.2f %-10c\n\n", i, s.name, s.phoneno, s.rollno, s.branch, s.res, s.grade);
            i++;
            found = 1;
            break;
        }

    }

    if(found == 1){
        printf("\n\t\t\t\t\tRecord Found...\n\n");

    }
    else {
        printf("\n\t\t\t\t\tRecord Not Found !!!\n\n");
    }

    fclose(ptr);

}


// function to search the record by name
void search_by_name() {

    char name[50];
    int found = 0;
    int i = 1;
    fflush(stdin);

    system("cls");
    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    // getting the name from user to search
    printf("\n\t\t\t\t\tEnter Name of student : ");
    gets(name);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-15s%-15s%-20s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH", "PERCENTAGE", "GRADE");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // you can use strcmpi , it ignores the case sensitivity while comapiring
        // you can campare Jashu with jashu , result will be found
        if(strcmp(name,s.name) == 0) {
            printf("%-10d %-30s %-20s %-15d %-15s %-20.2f %-10c\n\n", i, s.name, s.phoneno, s.rollno, s.branch, s.res, s.grade);
            i++;
            found = 1;
            break;

        }


    }

    if(found == 1) {
        printf("\n\t\t\t\t\tRecord Found...\n\n");
    }
    else {
        printf("\n\t\t\t\t\tRecord Not Found !!!\n\n");
    }

    fclose(ptr);

}


// function for searching the record by rollno
void search_by_phoneno() {

    char pno[11];
    int found = 0;
    int i = 1;

    fflush(stdin);

    system("cls");
    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    printf("\n\t\t\t\t\tEnter Phone_no of student : ");
    gets(pno);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-15s%-15s%-20s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH", "PERCENTAGE", "GRADE");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // compairing the phone no to search
        if(strcmp(pno,s.phoneno) == 0) {
            printf("%-10d %-30s %-20s %-15d %-15s %-20.2f %-10c\n\n", i, s.name, s.phoneno, s.rollno, s.branch, s.res, s.grade);
            i++;
            found = 1;
            break;

        }


    }

    if(found == 1) {
        printf("\n\t\t\t\t\tRecord Found...\n\n");
    }
    else {
        printf("\n\t\t\t\t\tRecord Not Found !!!\n\n");
    }

    fclose(ptr);






}

// function to initiate the search process
void search() {

    int option;

    while(1) {

        system("cls");
        printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
        printf("\n\t\t\t\t\t--------------------------------------------\n");
        printf("\n\t\t\t\t\tEnter how to search : \n");
        printf("\n\t\t\t\t\t-----------------------\n");
        printf("\n\t\t\t\t\t1. Search by Roll No\n");
        printf("\n\t\t\t\t\t2. Search by Name \n");
        printf("\n\t\t\t\t\t3. Search by Phone No \n");
        printf("\n\t\t\t\t\t0. Back to main menu \n");
        printf("\n\t\t\t\t\tEnter choice : ");
        scanf("%d", &option);

        switch(option){

            case 1:
                search_by_rollno();
                break;

            case 2:
                search_by_name();
                break;

            case 3:
                search_by_phoneno();
                break;

            case 0:
                main();
                break;

        }
        printf("\n\t\t\t\t\tPress any key to continue....");
        getch();


    }


}

// function for modifying the record
void modify() {

    int rno = 0;
    int modified = 0;
    int sum = 0;
    float per = 0;

    system("cls");
    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    printf("\n\t\t\t\t\tEnter Roll No to Modify : ");
    scanf("%d", &rno);

    ptr = fopen("student.txt", "rb+");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        if(rno == s.rollno) {
            printf("\n\t\t\t\t\tRecord Found...\n\n");
            fflush(stdin);
            printf("\n\t\t\t\t\tEnter Student name : ");
            gets(s.name);
            while(!name_validation(s.name)) {

                printf("\n\t\t\t\t\tInvalid Name !!!\n");
                printf("\n\t\t\t\t\tEnter again \n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Student name : ");
                gets(s.name);

            }
            fflush(stdin);
            printf("\n\t\t\t\t\tEnter Phone No : ");
            gets(s.phoneno);

            while(!validation(s.phoneno)) {
                printf("\n\t\t\t\t\tInvalid Phone No!!!\n");
                printf("\n\t\t\t\t\tEnter again \n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Phone No : ");
                gets(s.phoneno);
            }
            fflush(stdin);
            printf("\n\t\t\t\t\tEnter Rollno : ");
            scanf("%d", &s.rollno);
            fflush(stdin);
            printf("\n\t\t\t\t\tEnter Branch : ");
            gets(s.branch);
            fflush(stdin);
            printf("\n\t\t\t\t\tEnter Marks of Maths out of 100 : ");
            scanf("%d", &s.maths);

            while(!marks_validator(s.maths)) {
                printf("\n\t\t\t\t\tInvalid marks ...\n");
                printf("\n\t\t\t\t\tEnter marks again\n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Marks of Maths out of 100 : ");
                scanf("%d", &s.maths);
            }
            fflush(stdin);

            printf("\n\t\t\t\t\tEnter Marks of English out of 100 : ");
            scanf("%d", &s.eng);

            while(!marks_validator(s.eng)) {
                printf("\n\t\t\t\t\tInvalid marks ...\n");
                printf("\n\t\t\t\t\tEnter marks again\n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Marks of English out of 100 : ");
                scanf("%d", &s.eng);
            }
            fflush(stdin);

            printf("\n\t\t\t\t\tEnter Marks of Computer out of 100 : ");
            scanf("%d", &s.cse);

            while(!marks_validator(s.cse)) {
                printf("\n\t\t\t\t\tInvalid marks ...\n");
                printf("\n\t\t\t\t\tEnter marks again\n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Marks of Computer out of 100 : ");
                scanf("%d", &s.cse);
            }
            fflush(stdin);

            printf("\n\t\t\t\t\tEnter Marks of Science out of 100 : ");
            scanf("%d", &s.sci);

            while(!marks_validator(s.sci)) {
                printf("\n\t\t\t\t\tInvalid marks ...\n");
                printf("\n\t\t\t\t\tEnter marks again\n");
                fflush(stdin);
                printf("\n\t\t\t\t\tEnter Marks of Science out of 100 : ");
                scanf("%d", &s.sci);
            }
            fflush(stdin);

            sum = s.maths + s.eng + s.cse + s.sci;
            per = ((float) sum / 400) * 100;
            s.res = per;

            s.grade = grade_calc(per);

            // as the file pointer automatically increments
            // so bringing it back to the previous record
            // which we want to modify
            fseek(ptr, -sizeofstd, 1);
            fwrite(&s, sizeofstd, 1, ptr);

            modified = 1;
            fclose(ptr);
            break;
        }

    }

    if(modified == 1){
        printf("\n\t\t\t\t\tRecord Updated...\n\n");

    }
    else {
        printf("\n\t\t\t\t\tRecord Not Found !!!\n\n");
    }

}

// function for deleting the record from the file
void delete_record(){

    int rno = 0;

    int del = 0;

    system("cls");
    printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
    printf("\n\t\t\t\t\t--------------------------------------------\n");
    printf("\n\t\t\t\t\tEnter Roll No to Delete : ");
    scanf("%d", &rno);

    FILE *temp;

    ptr = fopen("student.txt", "rb");

    // opening another file for copying the data
    temp = fopen("second.txt", "ab");


    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        if(rno != s.rollno) {
            fwrite(&s, sizeofstd, 1, temp);
        }
        else{
            del = 1;
        }


    }

    // after the data is transfered
    // close the files
    fclose(ptr);
    fclose(temp);

    // remove the old file
    remove("student.txt");

    // rename the new file to old file
    rename("second.txt", "student.txt");

    if(del == 1) {
        printf("\n\t\t\t\t\tRecord Deleted Successfully\n\n");

    }

    else{
        printf("\n\t\t\t\t\tRecord not present\n\n");
    }


}




// function for sorting the record on display
void sort() {

    ptr = fopen("student.txt", "rb");
    int k = 1;
    int c = 0;

    struct student stu[100], t;


    // counting and storing all record in a struct student array
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        stu[c++] = s;

    }

    // sorting the data using selection sort
    for(int i = 0; i < c - 1; i++) {

        for(int j = i + 1; j < c; j++) {
            if(stu[i].rollno > stu[j].rollno) {
                t = stu[i];
                stu[i] = stu[j];
                stu[j] = t;
            }
        }


    }


    printf("\n%-10s%-30s%-20s%-15s%-15s%-20s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH", "PERCENTAGE", "GRADE");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < c; i++) {
        printf("%-10d %-30s %-20s %-15d %-15s %-20.2f %-10c\n\n", k, stu[i].name, stu[i].phoneno, stu[i].rollno, stu[i].branch, stu[i].res, stu[i].grade);
        k++;
    }

    fclose(ptr);

}


// main function
int main() {

    int option;

    while(1){

        system("cls");
        printf("\n\n\n\t\t\t\t\t<<==========STUDENT INFORMATION==========>>\n");
        printf("\n\t\t\t\t\t--------------------------------------------\n");
        printf("\n\t\t\t\t\t1. Add Record\n");
        printf("\n\t\t\t\t\t2. Display Record\n");
        printf("\n\t\t\t\t\t3. Search Record\n");
        printf("\n\t\t\t\t\t4. Modify Record\n");
        printf("\n\t\t\t\t\t5. Delete Record\n");
        printf("\n\t\t\t\t\t6. Sort Record\n");
        printf("\n\t\t\t\t\t0. Exit\n");

        printf("\n\n\n\t\t\t\t\tEnter Option : ");
        scanf("%d", &option);


        switch(option) {

            case 0:
                exit(0);

            case 1:
                insert();
                break;

            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                modify();
                break;
            case 5:
                delete_record();
                break;
            case 6:
                sort();
                break;


        }

        printf("\n\n\n\t\t\t\t\tPress any key to continue.....");
        getch();

    }

    return 0;


}
