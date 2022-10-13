/******************************************************************************
*
*
* File Name:card.c
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#pragma warning(disable : 4996)

#include<string.h>
#include<stdio.h>
#include"Terminal.h"
#include<time.h>
#include"Card.h"   
#include <ctype.h> 
#define YES '1'
#define NO  '0'
#define MAX_CHAR_TAG 3 
uint8  str_time[25];
uint8 gender[MAX_CHAR_TAG];  /**************  MR OR MRS   ******/
uint8 Name_Holde_Array[50] ;   /**************HOLD NAME THEN SAVE IT ON STRUCT */ 
uint8 PAN_Number_Array[11]; 
uint8 Firm_Char[10] = {'C' , 'P' , 'F' , 'A' , 'B' , 'L' , 'G' , 'H' , 'J'}; 
uint8 Nums_To_Check[10] = { '0' , '1' , '2' , '3' , '4' ,'5' ,'6' ,'7' , '8' , '9' };

void getCardExpiryDate() {
    printf("Pleas enter the expiration date in Form of  ""Sat May 15 12:00:00 2027 "" "); 
    for (int i = 0; i < 25; i++) {
        scanf_s("%c" , &str_time[i]);
    }
   
    //fgets(str_time, 25 , stdin);
    for (int i = 0; i < 25; i++) {
        card_1.Expiration_Date[i] = str_time[i]; 
    
    } 
    //strcpy(card_1.Expiration_Date, str_time); 
    printf("Your Expiray Date is \n");  
    for (int i = 0; i < 25; i++) {
        printf("%c", card_1.Expiration_Date[i]);
    } 
    printf("%s", card_1.Expiration_Date); 

}
void  getCardHolderName() { 
    printf("Enter Nickname  Name \n "); 
    printf("Choose :   (   Mr   ,  Mrs ) \n ");    
    fgets(gender, MAX_CHAR_TAG, stdin);  
    printf("Enter the Holder Name :  Like *   AbdelrahmanMahmoud   * Without space    \n  "); 
     scanf("%s", Name_Holde_Array); 
     strcpy(card_1.Name_Holder, Name_Holde_Array); 

     printf(strcat(strcat(gender, " : "), card_1.Name_Holder) ); 
     printf("\n"); 
} 
void  getCardPAN() {
    printf("PAN NUMBER In Form  ACBPA1258S \n");
    scanf("%s", PAN_Number_Array);
    printf("Your PAN Is \n");
    printf("%s \n", PAN_Number_Array); 
    strcpy(card_1.PAN_NUM, PAN_Number_Array); 
    int main_counter = 0;
    for (uint8 i = 0; i < 9; i++) {
        if (PAN_Number_Array[3] == Firm_Char[i]) {
            main_counter++;

        }
    }
    if (main_counter == 1) {
        if (isalpha(PAN_Number_Array[4]) == 1) {

            uint8 counter = 0;
            for (uint8 i = 0; i < 3; i++) {
                if (isalpha(PAN_Number_Array[i]) == 1) {
                    counter++;
                }
            }
            if (counter == 3) {
                uint8 counter_F = 0;
                if (isalpha(PAN_Number_Array[9]) == 1) {
                    uint8 i = 5;
                    while (i < 9) {
                        for (uint8 j = 0; j < 9; j++) {
                            if (PAN_Number_Array[i] == Nums_To_Check[j]) {
                                counter_F ++;

                            }


                        }
                        i++;

                    
                    
                    }
                    if (counter_F == 4) {

                        printf("correct PAN \n");  
                        card_1.PAN_Availability[0] = YES; 
                        

                    } 
                    else {

                        printf("Incorrect PAN \n");
                        card_1.PAN_Availability[0] = NO;
                    }


                }
                else {
                    printf("Invalid Card \n"); 
                    card_1.PAN_Availability[0] = NO;
                    
                }
            }
            else {  // A5RY
                printf("Invalid Card \n");
                card_1.PAN_Availability[0] = NO ;
                
            }

        }
        else {
            printf("Invalid Card \n");
            card_1.PAN_Availability[0] = NO;
        }


    }
    else {
        printf("Invalid Card \n");
        return NO; 
    
    }
}
