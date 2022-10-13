/******************************************************************************
*
*
* File Name: Card.h
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#pragma once
#ifndef CARD_H_
#define CARD_H_ 
#include "std_types.h"
#define MAX_CHAR_TAG 3 
extern uint8 PAN_Number_Array[11]; 
extern uint8 gender[MAX_CHAR_TAG];
struct Card {
	uint8 Name_Holder [50];
	uint8 Expiration_Date[27]; 
	uint8 PAN_NUM[11]; 
	uint8 Trasnsaction_availabilty[2]; 
	uint8 Expiration_Availability[2]; 
	uint8 PAN_Availability[2];  
	uint32 Transaction_Amount_Card; 

} card_1 ;
void getCardExpiryDate(); 
void getCardHolderName(); 
void  getCardPAN();
#endif /* CARD_H_ */ 

  