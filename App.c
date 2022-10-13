/******************************************************************************
*
*
* File Name: App.c
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#include "App.h" 
void AppStart() {
    Hard_coded_MONEY();
    Hard_coded_data();
    getTransactionDate();
    getCardExpiryDate();
    isCardExpried();
    getCardHolderName();
    getCardPAN();
    setMaxAmount();
    gatTransactionAmount();
    if (isBelowMaxAmount(Transaction_Amount)) {

        printf("Valid \n"); 
        printf("Continue \n"); 
        card_1.Trasnsaction_availabilty[0] = YES;
    }
    else {
        printf("OUT OF THE MAX AMOUNT FOR THE ATM \n"); 
        printf("Please renter the amount of the money At Max 50000LE \n");  
        card_1.Trasnsaction_availabilty[0] = NO; 
        gatTransactionAmount(); 
    }
    WRITE_IN_FILE();
    READ_IN_FILE();
    READ_IN_MONEY();
    isValidAccount();
    isAmountAvailable();
    saveTransaction();


}