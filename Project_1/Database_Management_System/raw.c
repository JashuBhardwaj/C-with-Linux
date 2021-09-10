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
    if(c > 10) {
        return false;
    }

    return true;

}


// function for inserting new record
void insert() {


    // opening file using file pointer
    // opening it for appending data
    ptr = fopen("student.txt", "ab");

    // removing the data stored in buffer
    fflush(stdin);

    printf("Enter Student name : ");
    gets(s.name);
    fflush(stdin);
    printf("Enter Phone No : ");
    gets(s.phoneno);

    while(!validation(s.phoneno)) {
        printf("Invalid Phone No!!!\n");
        printf("Enter again \n");
        fflush(stdin);
        printf("Enter Phone No : ");
        gets(s.phoneno);
    }
    fflush(stdin);
    printf("Enter Rollno : ");
    scanf("%d", &s.rollno);
    fflush(stdin);
    printf("Enter Branch : ");
    gets(s.branch);
    fflush(stdin);


    // writing the data in file after
    // getting it from user
    fwrite(&s, sizeofstd, 1, ptr);
    printf("Record saved successfully !\n");

    fflush(stdin);

    // closing the file after inserting data
    fclose(ptr);


}


// function for displaying the data
void display() {

    system("cls");
    int i =1;
    ptr = fopen("student.txt", "rb");

    if(ptr == NULL) {
        printf("File not present");
        exit(0);
    }

    printf("\n<<==========STUDENT INFORMATION==========>>\n");

    printf("\n%-10s%-30s%-20s%-10s%-10s\n","S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH");
    printf("--------------------------------------------------------------------------------\n");


    // reading the file
    // until end of file
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        printf("%-10d %-30s %-20s %-10d %-10s\n", i, s.name, s.phoneno, s.rollno, s.branch);
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


    // getting the rollno from user to search
    printf("Enter Roll No to search : ");
    scanf("%d", &rno);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-10s%-10s\n", "S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH");
    printf("--------------------------------------------------------------------------------\n");

    // reading the file until EOF
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // if the record rollno is equal to the searched no
        // display the content of that student
        if(rno == s.rollno) {
            printf("%-10d%-30s %-20s %-10d %-10s\n", i, s.name, s.phoneno, s.rollno, s.branch);
            i++;
            found = 1;
            break;
        }

    }

    if(found == 1){
        printf("\nRecord Found...\n\n");

    }
    else {
        printf("\nRecord Not Found !!!\n\n");
    }

    fclose(ptr);

}


// function to search the record by name
void search_by_name() {

    char name[50];
    int found = 0;
    int i = 1;
    fflush(stdin);

    // getting the name from user to search
    printf("Enter Name of student : ");
    gets(name);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-10s%-10s\n", "S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH");
    printf("--------------------------------------------------------------------------------\n");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // you can use strcmpi , it ignores the case sensitivity while comapiring
        // you can campare Jashu with jashu , result will be found
        if(strcmp(name,s.name) == 0) {
            printf("%-10d%-30s %-20s %-10d %-10s\n", i, s.name, s.phoneno, s.rollno, s.branch);
            i++;
            found = 1;
            break;

        }


    }

    if(found == 1) {
        printf("\nRecord Found...\n\n");
    }
    else {
        printf("\nRecord Not Found !!!\n\n");
    }

    fclose(ptr);

}


// function for searching the record by rollno
void search_by_phoneno() {

    char pno[11];
    int found = 0;
    int i = 1;

    fflush(stdin);

    printf("Enter Phone_no of student : ");
    gets(pno);

    ptr = fopen("student.txt", "rb");

    printf("\n%-10s%-30s%-20s%-10s%-10s\n", "S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH");
    printf("--------------------------------------------------------------------------------\n");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        // compairing the phone no to search
        if(strcmp(pno,s.phoneno) == 0) {
            printf("%-10d%-30s %-20s %-10d %-10s\n", i, s.name, s.phoneno, s.rollno, s.branch);
            i++;
            found = 1;
            break;

        }


    }

    if(found == 1) {
        printf("\nRecord Found...\n\n");
    }
    else {
        printf("\nRecord Not Found !!!\n\n");
    }

    fclose(ptr);






}

// function to initiate the search process
void search() {

    int option;

    while(1) {

        system("cls");
        printf("Enter how to search : \n");
        printf("-----------------------\n");
        printf("1. Search by Roll No\n");
        printf("2. Search by Name \n");
        printf("3. Search by Phone No \n");
        printf("0. Back to main menu \n");
        printf("Enter choice : ");
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
        printf("Press any key to continue....");
        getch();


    }


}

// function for modifying the record
void modify() {

    int rno = 0;
    int modified = 0;

    printf("Enter Roll No to Modify : ");
    scanf("%d", &rno);

    ptr = fopen("student.txt", "rb+");

    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        if(rno == s.rollno) {
            printf("\nRecord Found...\n\n");
            fflush(stdin);
            printf("Enter Student name : ");
            gets(s.name);
            fflush(stdin);
            printf("Enter Phone No : ");
            gets(s.phoneno);
            fflush(stdin);
            printf("Enter Rollno : ");
            scanf("%d", &s.rollno);
            fflush(stdin);
            printf("Enter Branch : ");
            gets(s.branch);
            fflush(stdin);

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
        printf("\nRecord Updated...\n\n");

    }
    else {
        printf("\nRecord Not Found !!!\n\n");
    }

}

// function for deleting the record from the file
void delete_record(){

    int rno = 0;

    int del = 0;

    printf("Enter Roll No to Delete : ");
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
        printf("\nRecord Deleted Successfully\n\n");

    }

    else{
        printf("\nRecord not present\n\n");
    }


}


// function for swaping record while sorting
void swap(struct student stu[], int i, int temp) {

    struct student t;

    t = stu[i];
    stu[i] = stu[temp];
    stu[temp] = t;
}



// function for sorting the record on display
void sort() {

    ptr = fopen("student.txt", "rb");
    int k = 1;
    int c = 0;

    struct student stu[100];
    int t;


    // counting and storing all record in a struct student array
    while(fread(&s, sizeofstd, 1, ptr) == 1) {

        stu[c++] = s;

    }

    // sorting the data using selection sort
    for(int i = 0; i < c - 1; i++) {

        for(int j = i + 1; j < c; j++) {
            if(stu[i].rollno > stu[j].rollno) {
                t = j;
            }
        }

        if(i != t) {
            swap(stu, i, t);
        }

    }


    printf("\n%-10s%-30s%-20s%-10s%-10s\n", "S.NO", "STUDENT NAME", "PHONE NO", "ROLL NO", "BRANCH");
    printf("--------------------------------------------------------------------------------\n");

    for(int i = 0; i < c; i++) {
        printf("%-10d%-30s %-20s %-10d %-10s\n", k, stu[i].name, stu[i].phoneno, stu[i].rollno, stu[i].branch);
        k++;
    }

    fclose(ptr);

}


// main function
int main() {

    int option;

    while(1){

        system("cls");
        printf("Enter Option \n");
        printf("--------------------\n");
        printf("1. Add Record\n");
        printf("2. Display Record\n");
        printf("3. Search Record\n");
        printf("4. Modify Record\n");
        printf("5. Delete Record\n");
        printf("6. Sort Record\n");
        printf("0. Exit\n");

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

        printf("Press any key to continue.....");
        getch();

    }

    return 0;


}
