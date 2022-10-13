/******************************************************************************
*
*
* File Name: Terminal.h
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#pragma once
#ifndef TERMINAL_H_
#define TERMINAL_H_ 
#include "std_types.h" 
extern uint32 Transaction_Amount;
extern uint8  str_time[25];
void getTransactionDate(); 
void isCardExpried();
void setMaxAmount();
void gatTransactionAmount(); 
boolean isBelowMaxAmount(int); 
#endif /* TERMINAL_H_ */