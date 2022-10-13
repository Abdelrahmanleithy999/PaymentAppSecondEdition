/******************************************************************************
*
*
* File Name: Server.h
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#pragma once
#ifndef SERVER_H_
#define SERVER_H_ 
#include "std_types.h" 
struct exported_data {
	uint32 exported_money;
	uint8 Name_holder_ex[20]; 
	uint8 PAN_NUM[11]; 

}cardex;
void print_client_data();
void WRITE_IN_FILE(); 
void READ_IN_FILE();
void READ_IN_MONEY(); 
void Hard_coded_MONEY();
void Hard_coded_data(); 
boolean isValidAccount(); 
boolean isAmountAvailable();
void saveTransaction(); 
#endif