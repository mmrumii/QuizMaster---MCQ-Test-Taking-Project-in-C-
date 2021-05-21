//
//  main.c
//  theStudyManagementSystemProject
//
//  Created by Masud Rumii on 8/10/15.
//  Copyright (c) 2015 Masud Rumii. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function Prototype here ...

int userReigstration(char name[100], char email[100], int phone, int studentid, char department[100], char address[100], char userid[100], char pass[100]){
    FILE *fp;
    fp = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//registration.txt", "a");
    
    fprintf(fp,"%s\n",name);
    fprintf(fp,"%s\n",email);
    fprintf(fp,"%d\n",phone);
    fprintf(fp,"%d\n",studentid);
    fprintf(fp,"%s\n",department);
    fprintf(fp,"%s\n",address);
    fprintf(fp,"%s\n",userid);
    fprintf(fp,"%s\n",pass);
    
    printf("Great ! Account successfully created .");
    
    fclose(fp);
    return 0;
}

int readBooks();
int factorial(int);
int fibonacci(int);
int takeTest();
int profileDetails();
int accountManagement();

// Global Variables
int userLocation = 0;
// Struct Here .....

struct login{
    char user[100];
    char pass[100];
    char name[100];
    int thePhone[100];
    int theID[100];
    char theEmail[100];
    char theDepartment[100];
    char theAddress[100];
};
struct book{
    char bookTitle[100];
    int bookID;
    char bookContent[1000];
};
struct question{
    char theQuestion[100];
    char posibleQuestion[100];
    int theAnswer;
};
int main() {
    int startingChoice;
    char name[100];
    char email[100];
    char userId[100];
    char password[100];
    int studentId;
    int phone;
    char department[100];
    char address[100];
    int userChoice;
    struct login info[100];
    int mainMenu;
    int N;
    int signUp;
    int caltulatorTryAgain = 0;
    int tryLoginAgain = 0;
    char userName[100];
    char passWord[100];
    int userSize;
    
    printf("=========*******=======**=========*******=========   Welcome ! Lets learn something new  =========*******========**========*******=========   \n");
    printf("=========*******=======**=========*******=========   Program Created by Masud Rumii      =========*******=======**=========*******=========   \n");
    printf("=========*******=======**=========*******=========   Contribution by Mahmud Akash        =========*******=======**=========*******=========   \n");
    printf("=========*******=======**=========*******=========             Lets get started          =========*******=======**=========*******=========   \n");
    printf("\n\n=========*******=========******* Press 1 to start Program : ");
    scanf("%d",&startingChoice);
    
    while (!(startingChoice == 1)) {
        printf("\n\nYou entered wrong number !! Please try again .\n");
        printf("Press 1 to Login or Press 2 for Registration : ");
        scanf("%d",&startingChoice);
        continue;
    }
    if (startingChoice == 1) {
        printf("Do you already have an account here ? Press 1 Registration | Press any other number to Login : ");
        scanf("%d",&signUp);
        while (signUp == 1) {
            printf("\n\n");
            printf("-----------------Registration--------------\n");
            printf("Your Nick Name : ");
            scanf("%s",name);
            printf("Your Email : ");
            scanf("%s",email);
            printf("Your Phone : ");
            scanf("%d",&phone);
            printf("Your Student ID : ");
            scanf("%d",&studentId);
            printf("Department : ");
            scanf("%s",department);
            printf("Address : ");
            scanf("%s",address);
            printf("Username : ");
            scanf("%s",userId);
            printf("Password : ");
            scanf("%s",password);
            
            userReigstration(name, email, phone, studentId, department, address, userId, password);
            break;
        }
        do {
            printf("\n\n");
            printf("=========******* Login *******=========\n");
            printf("Your Username : ");
            scanf("%s",userName);
            printf("Password : ");
            scanf("%s",passWord);
            
            FILE *fp;
            fp = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/registration.txt", "r");
            int i = 0;
            
            while (!feof(fp)) {
                fscanf(fp, "%s", info[i].name);
                fscanf(fp, "%s", info[i].theEmail);
                fscanf(fp, "%d ", info[i].thePhone);
                fscanf(fp, "%d ", info[i].theID);
                fscanf(fp, "%s", info[i].theDepartment);
                fscanf(fp, "%s", info[i].theAddress);
                fscanf(fp, "%s", info[i].user);
                fscanf(fp, "%s", info[i].pass);
                i++;
            }
            userSize = i;
            for (i = 0; i < userSize; i++) {
                if ((strcmp(userName, info[i].user))==0){
                    userLocation = i;
                }
            }
            if ((strcmp(userName, info[userLocation].user))==0 && (strcmp(passWord, info[userLocation].pass))==0) {
                time_t rawtime;
                struct tm*  time_;
                
                time(&rawtime);
                time_ = localtime(&rawtime);
                
                printf("\n\n=========*******=========   Current Time : %i:%i:%i    =====     Today's Date :  %i %i %i   =========********=======\n", time_->tm_hour, time_->tm_min,
                       time_->tm_sec, time_->tm_mday, time_->tm_mon+1,
                       time_->tm_year+1900);
                switch (time_->tm_hour) {
                    case 6 ... 11:
                        printf("\n=========*******=========    Hi %s ,Good Morning, You are successfully Logged in.     =========*******=========   \n\n", info[userLocation].name);
                        break;
                    case 12 ... 15:
                        printf("\n=========*******=========    Hi %s ,Good Noon, You are successfully Logged in.        =========*******=========   \n\n", info[userLocation].name);
                        break;
                    case 16 ... 18:
                        printf("\n=========*******=========    Hi %s ,Good Afternoon, You are successfully Logged in.   =========*******=========   \n\n", info[userLocation].name);
                        break;
                    case 19 ... 20:
                        printf("\n=========*******=========    Hi %s ,Good Evening, You are successfully Logged in.     =========*******=========   \n\n", info[userLocation].name);
                        break;
                    case 21 ... 23:
                        printf("\n=========*******=========    Hi %s ,Good Night, You are successfully Logged in.       =========*******=========   \n\n", info[userLocation].name);
                        break;
                    case 0 ... 5:
                        printf("\n=========*******========= Hi %s ,Good Early Morning, You are successfully Logged in.  =========*******=========   \n\n", info[userLocation].name);
                    default:
                        printf("\n=========*******=========    Hi %s ,Good Day, You are successfully Logged in.         =========*******=========   \n\n", info[userLocation].name);
                        break;
                }
                
                do {
                    printf("\n\n=========*******=========  Press 1 to read | Press 2 to take a test | Press 3 to view profile | Press 4 to use special calculator : ");
                    scanf("%d",&userChoice);
                    
                    while (!(userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 4)) {
                        printf("\n=========*******=========   Oops ! You entered wrong number . Please try again=========*******=========\n\n");
                        printf("\n\n=========*******=========  Press 1 to read | Press 2 to take a test | Press 3 to view profile | Press 4 to use special calculator : ");
                        scanf("%d",&userChoice);
                        continue;
                    }
                    
                    if (userChoice == 1) {
                        readBooks();
                    }
                    
                    else if (userChoice == 2){
                        takeTest();
                        
                    }
                    else if (userChoice == 3){
                        printf("\n\nName : %s\n",info[userLocation].name);
                        printf("Email : %s\n",info[userLocation].theEmail);
                        printf("Phone : %d\n",*info[userLocation].thePhone);
                        printf("ID : %d\n",*info[userLocation].theID);
                        printf("Department : %s\n",info[userLocation].theDepartment);
                        printf("Address : %s\n",info[userLocation].theAddress);
                        printf("User id : %s\n",info[userLocation].user);
                        printf("Password : %s\n",info[userLocation].pass);
                    }
                    else if (userChoice == 4){
                        int calculatorChoice;
                        do {
                            printf("\n\n=========*******=========  Press 1 to calculate fibonacci series | Press 2 to calculate factorial | Press 3 to check prime number : ");
                            scanf("%d",&calculatorChoice);
                            if (calculatorChoice == 1) {
                                printf("\n\nEnter the Number : ");
                                scanf("%d",&N);
                                printf("\nThe result is : %d",fibonacci(N));
                            }
                            else if (calculatorChoice == 2) {
                                printf("\n\nEnter an positive integer: ");
                                scanf("%d",&N);
                                printf("\nFactorial of %d = %d", N, factorial(N));
                            }
                            else if (calculatorChoice == 3){
                                int inputNumber, C = 2;
                                
                                printf("\n\nEnter a number to check if it is prime : ");
                                scanf("%d",&inputNumber);
                                
                                for ( C = 2 ; C <= inputNumber - 1 ; C++ )
                                {
                                    if ( inputNumber%C == 0 )
                                    {
                                        printf("\n\n%d is not prime.\n", inputNumber);
                                        break;
                                    }
                                }
                                if ( C == inputNumber )
                                    printf("%d is prime.\n", inputNumber);
                            }
                            else if(!(calculatorChoice == 1 || calculatorChoice == 2 || calculatorChoice == 3)) {
                                printf("\n\n=========*******=========  Wrong Choice ! =========*******=========");
                                printf("\n\n=========*******=========  Press 1 to try again | Press any other button to skip : ");
                                scanf("%d",&caltulatorTryAgain);
                            }
                            
                        }
                        while (caltulatorTryAgain == 1);
                        }
                    printf("\n\n\n ============= ********** Press 1 to go back to the main menu. ************ ============== : ");
                    scanf("%d",&mainMenu);
                    printf("\n\n\n");
                }
                while (mainMenu == 1);
                fclose(fp);
            }
            else{
                printf("=========*******========= Sorry, User id and password didn't match .=========*******=========\n");
                printf("\n=========*******========= Press 1 to try again . : ");
                scanf("%d",&tryLoginAgain);
                printf("\n\n");
            }
        }
        while (tryLoginAgain == 1);
        
    }
    
    return 0;
}

// Functions Here ....


// -------- Book Reading Function ---------

int readBooks(){
    struct book read[1000];
    int articleChoice;
    int i = 0;
    FILE *bookOne;
    FILE *bookTwo;
    FILE *bookThree;
    FILE *bookFour;
    FILE *bookFive;
    
    bookOne = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//passageOne.txt", "r");
    bookTwo = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//passageTwo.txt", "r");
    bookThree = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//passageThree.txt", "r");
    bookFour = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//passageFour.txt", "r");
    bookFive = fopen("//Files//Education//c programming ( NSU )//programming c project//theProject//theProject//passageFive.txt", "r");
    printf("\n\n========== ******* Article List ******* ==========\n\n");
    printf("1. Bangladesh national cricket team. \n2. Mobile Phone \n3. Sundarban \n4. A solid math foundation is vital for children to succeed \n5. General knowledge\n\n");
    printf("Please press any index number to read the article | Press any other number to skip : ");
    scanf("%d",&articleChoice);
    printf("\n\n");
    if (articleChoice == 1) {
        while (!feof(bookOne)) {
            fgets(read[i].bookContent, 1000, bookOne);
            i++;
        }
        int k;
        for (k = 0; k<=i; k++) {
            printf("%s",read[k].bookContent);
        }

    }
    else if (articleChoice == 2) {
        while (!feof(bookTwo)) {
            fgets(read[i].bookContent, 1000, bookTwo);
            i++;
        }
        int k;
        for (k = 0; k<=i; k++) {
            printf("%s",read[k].bookContent);
        }

    }
    else if (articleChoice == 3){
        while (!feof(bookThree)) {
            fgets(read[i].bookContent, 1000, bookThree);
            i++;
        }
    int k;
    for (k = 0; k<=i; k++) {
        printf("%s",read[k].bookContent);
    }
    }
    else if (articleChoice == 4){
        while (!feof(bookFour)) {
            fgets(read[i].bookContent, 1000, bookFour);
            i++;
        }
        int k;
        for (k = 0; k<=i; k++) {
            printf("%s",read[k].bookContent);
        }

    }
    else if (articleChoice == 5){
        while (!feof(bookFive)) {
            fgets(read[i].bookContent, 1000, bookFive);
            i++;
        }
        int k;
        for (k = 0; k<=i; k++) {
            printf("%s",read[k].bookContent);
        }

    }
    fclose(bookOne);
    fclose(bookTwo);
    fclose(bookThree);
    fclose(bookFour);
    fclose(bookFive);
    return 0;
}

// -------- Test Taking Function -----------

int takeTest(){
    struct question test[100];
    int Answer;
    int testChoice;
    int i = 0;
    int k;
    int theScore = 0;
    FILE *questionOne;
    FILE *questionTwo;
    FILE *questionThree;
    FILE *questionFour;
    FILE *questionFive;
    questionOne = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/questionOne.txt", "r");
    questionTwo = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/questionTwo.txt", "r");
    questionThree = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/questionThree.txt", "r");
    questionFour = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/questionFour.txt", "r");
    questionFive = fopen("/Volumes/Files/Files/Education/c programming ( NSU )/programming c project/theProject/theProject/questionFive.txt", "r");
    printf("\n\n================ ************ Test List ************* =================\n\n");
    printf("1. Bangladesh national cricket team. \n2. Mobile Phone \n3. Sundarban \n4. A solid math foundation is vital for children to succeed \n5. General knowledge\n\n");
    printf("Please press any index number to take a test | Press any other number to skip : ");
    scanf("%d",&testChoice);
    switch (testChoice) {
        case 1:
            while (!feof(questionOne)) {
                fgets(test[i].theQuestion, 100, questionOne);
                fgets(test[i].posibleQuestion, 100, questionOne);
                fscanf(questionOne, "%d ", &test[i].theAnswer);
                i++;
            }
            for (k = 0; k<i; k++) {
                printf("\n%s", test[k].theQuestion);
                printf("%s\n", test[k].posibleQuestion);
                printf("Your answer : ");
                scanf("%d",&Answer);
                if (Answer == test[k].theAnswer) {
                    theScore+=1;
                }
                else{
                    printf("\n ---***--- Wrong Answer ! . ----***---\n");
                }
            }
            printf("\n\n====== **** Thanks for the test . *** ====== \n\n");
            printf("Your score is %d out of 10",theScore);
            if (theScore < 5) {
                printf("\n====== **** The result is very poor. *** ======");
                printf("\n====== *** You Need More Study *** ======");
            }
            else if (theScore == 6 || theScore == 7){
                printf("\n====== **** The result is Good. *** ======");
            }
            else if (theScore == 8 || theScore == 9 || theScore == 10){
                printf("\n====== **** The result is very good. *** ======");
                printf("\n====== **** Good Job Buddy **** ======");
            }

            break;
        case 2:
            while (!feof(questionTwo)) {
                fgets(test[i].theQuestion, 100, questionTwo);
                fgets(test[i].posibleQuestion, 100, questionTwo);
                fscanf(questionTwo, "%d ", &test[i].theAnswer);
                i++;
            }
            
            for (k = 0; k<i; k++) {
                printf("\n%s", test[k].theQuestion);
                printf("%s\n", test[k].posibleQuestion);
                printf("Your answer : ");
                scanf("%d",&Answer);
                if (Answer == test[k].theAnswer) {
                    theScore+=1;
                }
                else{
                    printf("-------***** Wrong Answer ! *****---------\n");
                }

            }
            printf("\n\n====== **** Thanks for the test . *** ====== \n\n");
            printf("Your score is %d out of 10",theScore);
            if (theScore < 5) {
                printf("\n====== **** The result is very poor.*** ======");
                printf("\n====== *** You Need More Study *** ======");
            }
            else if (theScore == 6 || theScore == 7){
                printf("\n====== **** The result is Good. *** ======");
            }
            else if (theScore == 8 || theScore == 9 || theScore == 10){
                printf("\n====== **** The result is very good. *** ======");
                printf("\n====== **** Good Job Buddy **** ======");
            }

            break;
        case 3:
            while (!feof(questionThree)) {
                fgets(test[i].theQuestion, 100, questionThree);
                fgets(test[i].posibleQuestion, 100, questionThree);
                fscanf(questionThree, "%d ", &test[i].theAnswer);
                i++;
            }
            
            for (k = 0; k<i; k++) {
                printf("\n%s", test[k].theQuestion);
                printf("%s\n", test[k].posibleQuestion);
                printf("Your answer : ");
                scanf("%d",&Answer);
                if (Answer == test[k].theAnswer) {
                    theScore+=1;
                }
                else{
                    printf("-------***** Wrong Answer ! *****---------\n");
                }

            }
            printf("\n\n====== **** Thanks for the test . *** ====== \n\n");
            printf("Your score is %d out of 10",theScore);
            if (theScore < 5) {
                printf("\n====== **** The result is very poor. *** ======");
                printf("\n====== *** You Need More Study *** ======");
            }
            else if (theScore == 6 || theScore == 7){
                printf("\n====== **** The result is Good. ----");
            }
            else if (theScore == 8 || theScore == 9 || theScore == 10){
                printf("\n====== ****The result is very good. *** ======");
                printf("\n====== **** Good Job Buddy **** ======");
            }
            
            break;
        case 4:
            while (!feof(questionFour)) {
                fgets(test[i].theQuestion, 100, questionFour);
                fgets(test[i].posibleQuestion, 100, questionFour);
                fscanf(questionFour, "%d ", &test[i].theAnswer);
                i++;
            }
            
            for (k = 0; k<i; k++) {
                printf("\n%s", test[k].theQuestion);
                printf("%s\n", test[k].posibleQuestion);
                printf("Your answer : ");
                scanf("%d",&Answer);
                if (Answer == test[k].theAnswer) {
                    theScore+=1;
                }
                else{
                    printf("-------***** Wrong Answer ! *****---------\n");
                }

            }
            printf("\n\n====== **** Thanks for the test .  **** ====== \n\n");
            printf("Your score is %d out of 10",theScore);
            if (theScore < 5) {
                printf("\n\n====== **** The result is very poor. **** ======");
                printf("\n\n====== *** You Need More Study *** ======");
            }
            else if (theScore == 6 || theScore == 7){
                printf("\n\n====== **** The result is Good. **** ======");
            }
            else if (theScore == 8 || theScore == 9 || theScore == 10){
                printf("\n\n====== **** The result is very good. **** ======");
                printf("\n\n====== **** Good Job Buddy **** ======");
            }
            
            break;
        case 5:
            while (!feof(questionFive)) {
                fgets(test[i].theQuestion, 100, questionFive);
                fgets(test[i].posibleQuestion, 100, questionFive);
                fscanf(questionFive, "%d ", &test[i].theAnswer);
                i++;
            }
            
            for (k = 0; k<i; k++) {
                printf("\n%s", test[k].theQuestion);
                printf("%s\n", test[k].posibleQuestion);
                printf("Your answer : ");
                scanf("%d",&Answer);
                if (Answer == test[k].theAnswer) {
                    theScore+=1;
                }
                else{
                    printf("-------***** Wrong Answer ! *****---------\n");
                }
            }
            printf("\n\n====== *** Thanks for the test . *** ======\n\n");
            printf("Your score is %d out of 10",theScore);
            if (theScore < 5) {
                printf("\n====== *** The result is very poor. *** ======");
                printf("\n====== *** You Need More Study *** ======");
            }
            else if (theScore == 6 || theScore == 7){
                printf("\n====== *** The result is Good. *** ======");
            }
            else if (theScore == 8 || theScore == 9 || theScore == 10){
                printf("\n====== ****The result is very good. *** ======");
                printf("\n====== **** Good Job Buddy **** ======");
            }
            
            break;

        default:
            break;
    }
    fclose(questionOne);
    fclose(questionTwo);
    fclose(questionThree);
    fclose(questionFour);
    fclose(questionFive);
    return 0;
}

// ---------- fibonacci series Function ----------
int fibonacci(int N){
    if(N==0)
        return 0;
    else if(N==1)
        return 1;
    else return factorial(N-1) + factorial(N-2);
    return 0;
}
// ----------- Factorial Function -----------
int factorial(int n)
{   if(n == 0){
    return 0;
}
    else if(n == 1){
        return 1;
    }
    else return n*factorial(n-1);
};
