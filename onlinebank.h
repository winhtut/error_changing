//
// Created by National Cyber City on 2/18/2023.
//

#ifndef ONLINEBANKPJ_ONLINEBANK_H
#define ONLINEBANKPJ_ONLINEBANK_H
#include "stdio.h"
#include "stdlib.h"
#define USERSIZE 1000
#define DATA_COUNT 20

//Global Variable

int G_index=0; // for user counting
int email_found = -1; // for checking email exist
int space_array[DATA_COUNT];
int email_valid=-1;
int nrc_valid=-1;
int two_charArray=-1;
int strong_pass_valid=-1;
int phone_valid=-1;
int eKey_valid=-1;
int reKey_valid=-1;

// End of Global Variables

//function declaration
int check_input(char input[2]);
void rEgister();
void login();
int char_counting(char my_char[50]);
void loading_from_file();
void main_menu();
void space_counter();
void printing_all_data();
void email_validation(char to_check[50]);
void email_exist_checking(char email[50]);
void compare_two_charArray(char first[200],char second[200]);
void nrc_validation(char nrc[20]);
void strong_pass_validation(char pass[50]);
void phone_validation(unsigned int phone);
void encryption_key_validation(char eKey[30]);
void recovery_key_validation(char reKey[30]);
void copy_two_char_array(char receiver[200] ,char transmitter[200] );


struct trans{
    char note[200];
};
struct info{

    unsigned int id;
    char name[50];
    char nrc[20];
    char email[50];
    char password[50];
    unsigned int phoneNumber;
    char encryption_key[6];//>>
    char recovery_key[10];//>>
    char account_status[10]; //$
    int account_type; //1 personal ,2 business , 3 othersss...... //$
    int account_level;//$
    int minimum_opening_deposit;//$
    char currency[5];//>>
    unsigned long long int current_amount;//llu//>>
    char loanStatus[1];//$
    unsigned int monthly_income;//>>
    unsigned int loan_amount;//$
    float loan_rate;//$
    char address[100];//>>

    struct trans tr[300]; //transaction//>>

    // %u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s


};

struct info db[USERSIZE];


void main_menu(){

    char input[2];
    printf("Welcome to our OnlineBank-NCC!\n");
    printf("Press 1 to Login!\nPress 2 to Register!\nPress 3 to Exit!>>:");
    scanf(" %[^\n]",&input);

    int option = check_input(input);
    if(option == 49){
        login();
    }else if(option == 50){
        rEgister();
    } else if(option ==51){
        printf("Good Bye!\n");
        exit(2);
    } else{
        main_menu();
    }

}
//ascii value 0=48 , 9=57
int check_input(char input[2]){
    if( input[0]>=49 &&input[0]<= 57 && input[1]=='\0'){
        return input[0];
    } else{
        return -1;
    }
}

void login(){
    char l_email[50];
    printf("This is Online Bank Login!\n");
    printf("Enter your email to login!>>:");
    scanf(" %[^\n]",&l_email[0]);


}

void rEgister(){

    char re_email[50];
    char re_name[50];
    char re_nrc[20];
    char re_pass[50];
    unsigned int re_phone=0;
    char re_encrypt_key[30];
    char re_recovery_key[30];
    char re_currency[5];
    unsigned long long int re_current_amount=0;
    unsigned int re_monthly_income=0;
    char re_address[100];
    char re_note[200];
    printf("This is Online Bank Register !\n");
    email_valid=-1;
    while (email_valid==-1) {
        printf("Enter your email to register>>:");
        scanf(" %[^\n]", &re_email[0]);


        email_validation(re_email);
        if (email_valid == -1) {
            printf("Your email format was not valid\n");
        }
    }
    printf("Your email form was valid:\n");
    email_found=-1;
    email_exist_checking(re_email);
    if( email_found !=-1 ){
        printf("Your email was already register:\n");
        rEgister();
    } else{
        printf(" Del re_email %s\n",re_email);
        printf("Your email was saved:\n");
        printf("Enter your username:\n");
        scanf(" %[^\n]",&re_name);
        nrc_valid=-1;

        while (nrc_valid==-1){

            printf("Enter your NRC information:");
            scanf(" %[^\n]",&re_nrc);

            nrc_validation(re_nrc);

            if(nrc_valid==-1){
                printf("Your NRC Format was incorrect!\n");
            }
        }
        printf("[+]Your NRC format was correct:\n");
        printf(" del re_nrc test: %s",re_nrc);
        strong_pass_valid=-1;
        while (strong_pass_valid==-1){

            printf("Enter your password:");
            scanf(" %[^\n]",&re_pass);

            strong_pass_validation(re_pass);

            if(strong_pass_valid==-1){

                printf("[-]Your password format too weak and Try Again!\n");
            }

        }

        printf("[+]Your password format was correct and was saved!\n");
        phone_valid=-1;
        while (phone_valid==-1){
            printf("[X]Enter your Phone Number:");
            scanf("%u",&re_phone);

            phone_validation(re_phone);

            if(phone_valid == -1){

                printf("[-]Your phone number is already registered:\n");
            }

        }

        printf("[+] Your phone is correct and saved!\n");

        while (eKey_valid==-1){
            printf("[X]Enter your Encryption Key(from 4 to 6 char):");
            scanf(" %[^\n]",&re_encrypt_key);
            encryption_key_validation(re_encrypt_key);

            if(eKey_valid==-1){
                printf("[-]Your Encryption Key do not correspond with our pattern:\n");
            }

        }
        printf("[+]Your Encryption key valid and saved!\n");
        while (reKey_valid==-1){

            printf("[X]Enter your Recover Key carefully:");
            scanf(" %[^\n]",&re_recovery_key);

            recovery_key_validation(re_recovery_key);

            if(reKey_valid==-1){

                printf("[-]Your recovery Key do not correspond with our pattern:\n");
            }
        }
        printf("[+]Your recover key was saved!\n");

        printf("[X]Enter your currency to use:");
        scanf(" %[^\n]",&re_currency);
        printf("[X]Enter your amount:");
        scanf(" %llu",&re_current_amount);
        printf("[X]Enter your monthly income:");
        scanf(" %u",&re_monthly_income);
        printf("[X]Enter your address:");
        scanf(" %[^\n]",&re_address);
        printf("[X]Enter your opening note:");
        scanf(" %[^\n]",&re_note);
        db[G_index].id = G_index+1;

        copy_two_char_array(db[G_index].email,re_email);
        printf("del re_email %s\n",db[G_index].email);
        copy_two_char_array(db[G_index].nrc,re_nrc);
        copy_two_char_array(db[G_index].name,re_name);

        copy_two_char_array(db[G_index].password,re_pass);
        db[G_index].phoneNumber = re_phone;

        copy_two_char_array(db[G_index].encryption_key,re_encrypt_key);
        copy_two_char_array(db[G_index].recovery_key,re_recovery_key);

        copy_two_char_array(db[G_index].currency,re_currency);
        db[G_index].current_amount = re_current_amount;

        db[G_index].monthly_income = re_monthly_income;

        copy_two_char_array(db[G_index].address,re_address);
        copy_two_char_array(db[G_index].tr[0].note , re_note);



        copy_two_char_array(db[G_index].account_status,db[2].account_status);
        db[G_index].account_level=db[2].account_level;
        db[G_index].account_type = db[2].account_type;
        db[G_index].minimum_opening_deposit=db[2].minimum_opening_deposit;
        copy_two_char_array(db[G_index].loanStatus,db[2].loanStatus);
        db[G_index].loan_amount = db[2].loan_amount;
        db[G_index].loan_rate = db[2].loan_rate;

        G_index++;

        printing_all_data();


    }

}

void printing_all_data(){


    for(int user=0; user<G_index ; user++){

        printf("%u-%s-%s-%s-%s-%u-%s-%s-%s-%d-%d-%d-%s-%llu-%s-%u-%u-%f-%s",db[user].id ,db[user].name ,db[user].nrc,db[user].email,db[user].password,db[user].phoneNumber,db[user].encryption_key,db[user].recovery_key,db[user].account_status,db[user].account_type,db[user].account_level,db[user].minimum_opening_deposit,db[user].currency,db[user].current_amount,db[user].loanStatus,db[user].monthly_income,db[user].loan_amount,db[user].loan_rate,db[user].address);
        for(int gcc=0; gcc<= space_array[user]-19 ; gcc++){
            printf("-%s",db[user].tr[gcc].note);
        }
        printf("\n");

    }


void recovery_key_validation(char reKey[30]){
    int reKey_couunter = char_counting(reKey);

    if(reKey_couunter >=6 && reKey_couunter<=10){
        reKey_valid=1;
    }


}

void encryption_key_validation(char eKey[30]){

    int eKey_counter = char_counting(eKey);

    if( eKey_counter >=4 && eKey_counter<=6){
        eKey_valid=1;
    }


}

void phone_validation(unsigned int phone){
    int phone_counter=0;
    for(int i=0; i<G_index ; i++){

        if(phone != db[i].phoneNumber){

            phone_counter++;
        } else{
            phone_valid=-1;
            break;
        }

    }
    if(phone_counter == G_index){
        phone_valid=1;
    }

}
void strong_pass_validation(char pass[50]){

    int i=0;
    int special=0;
    int number=0;
    int smallChar=0;
    int capChar=0;


    int pass_counter = char_counting(pass);

    if(pass_counter >=6) {

        while (strong_pass_valid == -1) {
            if( i == pass_counter){
                strong_pass_valid=-1;
                break;
            }
            if(pass[i] >=33 && pass[i]<=42){
                special++;
            } else if( pass[i] >=48 && pass[i]<=57){
                number++;
            } else if( pass[i]>=97 && pass[i]<=122){
                smallChar++;
            } else if(pass[i]>=65 && pass[i]<=90){
                capChar++;
            }
            i++;
            if(special>0 && number>0 && capChar >0 && smallChar>0){
                strong_pass_valid=1;
            }

        }
    } else{
        printf("[-]we need at least 6 characters!\n");
        strong_pass_valid=-1;
    }


}

void nrc_validation(char nrc[20]){

    int nrc_counter = char_counting(nrc);

    for(int i=0; i<3; i++){

            two_charArray=-1;
        compare_two_charArray(nrc,db[i].nrc);
        if(two_charArray ==1){
            nrc_valid=1;
            break;
        }


    }

}

void compare_two_charArray(char first[200],char second[200]){

    int first_counter = char_counting(first);
    int second_counter = char_counting(second);

    int same_counter=0;

    if(first_counter == second_counter){

        for(register int i=0; i<first_counter; i++){

            if(first[i] != second[i]){
                break;
            }
            same_counter++;
        }

        if(first_counter == same_counter){
            two_charArray = 1;

        }

    }


}
void email_validation(char to_check[50]){

    int space=1;
    int format=1;
    char valid_form[10]={'@','g','m','a','i','l','.','c','o','m'};
    int check_counter = char_counting(to_check);

    int front_counter = check_counter-10;

    for(int i=0; i<front_counter ; i++){
        if(to_check[i]==' '){
            space=-1;
            break;
        }
    }
    for(int f=0; f<10; f++){
        if(to_check[front_counter] != valid_form[f]){
            format = -1;
            break;
        }
        front_counter++;
    }

    if(space == 1 && format==1){
        email_valid=1;
    }
}

void email_exist_checking(char email[50]){
    int counter = char_counting(email);

    int same_counting=0;
    for(register int gcc=0; gcc<G_index ; gcc++){
        int db_email_count = char_counting(db[gcc].email);

        if(counter == db_email_count){

            for(register int a=0; a<counter ; a++){
                if( email[a] !=db[gcc].email[a]){
                    break;
                }
                same_counting++;
            }
        }

        if(counter== same_counting){
            email_found=gcc;
            break;
        }


    }


}

int char_counting(char my_char[50]){

    int count=0;
    for(register int a=0; a<50; a++){

        if(my_char[a]  == '\0') {
            break;
        }
        count++;
    }

    return count;

}

void loading_from_file(){

    FILE *fptr = fopen("encrypted_data.txt","r");

    if( fptr != NULL){

        for(register int user=0; user < USERSIZE ; user++){

            fscanf(fptr ,"%u%s%s%s%s%u%s%s%s%d%d%d%s%llu%s%u%u%f%s",&db[user].id ,&db[user].name ,&db[user].nrc,&db[user].email,&db[user].password,&db[user].phoneNumber,&db[user].encryption_key,&db[user].recovery_key,&db[user].account_status,&db[user].account_type,&db[user].account_level,&db[user].minimum_opening_deposit,&db[user].currency,&db[user].current_amount,&db[user].loanStatus,&db[user].monthly_income,&db[user].loan_amount,&db[user].loan_rate,&db[user].address);

            for(register int trc=0; trc<= space_array[user]-19 ; trc++ ){
                fscanf(fptr , "%s",&db[user].tr[trc].note);
            }
            if(db[user].id == 0){
                break;
            }
            G_index++;

        }


    } else{
        printf("File opening error at Loading form file function!\n");
    }

    fclose(fptr);


}





}

void space_counter(){

    FILE *fptr = fopen("encrypted_data.txt","r");

    if(fptr != NULL){

        char c = fgetc(fptr);
        int index=0;

        while (!feof(fptr)){

            if(c !='\n'){
                if(c == ' '){
                    space_array[index] +=1;
                }
                c = fgetc(fptr);
            } else{

                index++;
                c = fgetc(fptr);
            }

        }


    } else{
        printf("\nFile opening error at space_counter function!\n");
    }

    for(int i=0; i<DATA_COUNT ; i++){

        printf(" %d",space_array[i]);
    }
    printf("\n");

}

void copy_two_char_array(char receiver[200] ,char transmitter[200] ){


    for(register int i=0; i<200; i++){
        receiver[i]='\0';
    }

    int transmit_counter =char_counting(transmitter);
    for(int i=0; i<transmit_counter; i++){

        receiver[i] = transmitter[i];
    }



}


#endif //ONLINEBANKPJ_ONLINEBANK_H
