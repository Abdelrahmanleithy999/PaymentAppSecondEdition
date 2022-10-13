/******************************************************************************
*
*
* File Name: Terminal.c
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#include "Terminal.h" 
#include <time.h> 
#include "Card.h"  
#include <stdlib.h>
#define TRUE 1 
#define FALSE 0 
#define NO '0'
#define YES '1'
uint32 Transaction_Amount;  /*GET TRANSACTION AMOUNT AND STORE IT*/
uint16 MAX_AMOUNT_FOR_TANSACTION = 50000;  /* MAX TRANSACTION AMOUNT */
uint8 num_23[2] = { '1' , '2' }; /*CHECKING THE DECADE */
uint8 num_2[3] = { '0' , '1' ,'2' }; /*CHCECKING THE LAST YEAR */
void getTransactionDate() {
	//char* pts; /* pointer to time string*/
	time_t now; /* current time*/
	char* ctime();
	(void)time(&now);
	printf("%s", ctime(&now));

}
void isCardExpried() {
    //char* pts; /* pointer to time string*/
    time_t now; /* current time*/
    char* ctime(); /*Built in function for the date */
    (void)time(&now); /*return the current date */
    printf("Transaction date is \n"); /*Print expiratiob date*/
    printf("%s", ctime(&now)); /*print the time at the beginning of the transaction */
    if (strcmp(ctime(&now), str_time) == 0) { /*CHECKING THE CURRENT TIME EQUALITY */

        printf("OUT OF DATE CONTACT SUPPORT FOR THE UPDATE \n "); 
        card_1.Expiration_Availability[0] = NO;   
        exit(EXIT_SUCCESS);    //terminate program immediately 
        

    }
    if (str_time[22] == num_23[0]) {
        for (int i = 0; i <= 9; i++) {
            uint8 num[10] = { '0' , '1' ,'2','3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
            if (str_time[23] == num[i]) {
                printf("OUT OF DATE CONTACT SUPPORT FOR THE UPDATE \n"); 
                card_1.Expiration_Availability[0] =  NO; 
                exit(EXIT_SUCCESS);    //terminate program immediately 

            }


        }

    }
    if ((str_time[22] == num_23[1])) {
        if (((str_time[23] == num_2[0]))) {
            printf("OUT OF DATE CONTACT SUPPORT  \n ");
            card_1.Expiration_Availability[0] = NO;
            exit(EXIT_SUCCESS);    //terminate program immediately 
        }
        else if (str_time[23] == num_2[1]) {

            printf("OUT OF DATE CONTACT SUPPORT   \n ");
            card_1.Expiration_Availability[0] = NO;
            exit(EXIT_SUCCESS);    //terminate program immediately 
        }
        else if ((str_time[23] == num_2[2]) && (str_time[22] == num_23[1])) {
            short counter = 0;
            uint8 last_day_year[6] = { 'D' , 'e' , 'c' ,'3' , '1' };
            for (int i = 0; i < 6; i++) {
                if (last_day_year[i] == str_time[i + 4]) {
                    counter++;

                }
            }
            if (counter == 5) {
                printf("OUT OF DATE CONTACT SUPPORT FOR THE UPDATE \n ");
                card_1.Expiration_Availability[0] = NO; 
                exit(EXIT_SUCCESS);    //terminate program immediately 
            }
            else {
                printf("continue  \n");
                card_1.Expiration_Availability[0] = YES;
            }

        }

        else
        {
            printf("continue  \n"); 
            card_1.Expiration_Availability[0] = YES ;
        }

    }


}
void setMaxAmount() {
    printf("Max Amount for day transation is %d LE  ", MAX_AMOUNT_FOR_TANSACTION);

}
void gatTransactionAmount() {
    printf("Enter your Transaction Amount \n");  
    scanf("%d", &Transaction_Amount);   
    printf("Your Transaction amount is %d LE \n", Transaction_Amount); 
    card_1.Transaction_Amount_Card = Transaction_Amount; 
} 
boolean isBelowMaxAmount(int parameter ){
    if (MAX_AMOUNT_FOR_TANSACTION > parameter) {
     
        return TRUE; /*RETURN YES IF THE TRANSACTION IS NOT MORE THAN MAX OF THE ATM*/ 
        
    } 
    else {
        return FALSE ; /*RETURN NO IF THE TRANSACTION IS  MORE THAN MAX OF THE ATM*/
       
    }


}