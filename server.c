/******************************************************************************
*
*
* File Name: Server.c
*
*
* Author: Abdelrahman Leithy
*
*******************************************************************************/
#pragma warning(disable : 4996)
#include "server.h"
#include"Terminal.h" 
#include"Card.h"  
#include"stdio.h" 
#include <stdlib.h>
#include <conio.h> 

#define No 0 
#define Yes 1 

void print_client_data() {

	printf("%c " , card_1.Expiration_Availability[0]); 
	printf("%c ", card_1.PAN_Availability[0]); 
	printf("%c \n ", card_1.Trasnsaction_availabilty[0]);  
	printf("%s \n ", card_1.Expiration_Date);  
	printf("%s \n", card_1.Name_Holder); 
	printf("%s \n", card_1.PAN_NUM);
} 
void WRITE_IN_FILE() {
	FILE* fopen(const char* path, const char* mode);  
	FILE* fp; 
	fp = fopen("imported transaction.txt" , "w");   
	fprintf(fp, "%s ", "Expiration date availability :  ");  
	if (card_1.Expiration_Availability[0]) {
	
		fprintf(fp, "%s ", "YES ");
	}
	else {
		fprintf(fp, "%s ", " NO ");
	}



	fprintf(fp, "%s ", "Card PAN availability :  ");
	if (card_1.PAN_Availability[0]) {

		fprintf(fp, "%s ", "YES ");
	}
	else {
		fprintf(fp, "%s ", " NO ");
	}
	fprintf(fp, "%s ", "Tansaction availability  :  ");
	fprintf( fp ,"%c \n ", card_1.Trasnsaction_availabilty[0]);    	
	fprintf(fp, "%s ", "Expiration date  :  ");
	fprintf(fp, "%s \n ", card_1.Expiration_Date);
	fprintf(fp, "%s ", "Name Holder :  ");
	fprintf(fp ,"%s \n", card_1.Name_Holder); 
	fprintf(fp, "%s ", "PAN Number:  ");
	fprintf(fp ,"%s \n", card_1.PAN_NUM); 
	fprintf(fp, "%s ", "Required Amount :  ");
	fprintf(fp, "%d ", card_1.Transaction_Amount_Card);

	fclose(fp); 


}
void READ_IN_FILE() {
	FILE* ptr;
	ptr = fopen("exported acccounts database", "r");
	fscanf(ptr, "%s %s ", cardex.Name_holder_ex , cardex.PAN_NUM , cardex.exported_money); 
	//printf("%s\n", cardex.Name_holder_ex); 
	//printf("%s\n", cardex.PAN_NUM); 
	fclose(ptr); 

}
void Hard_coded_data() {
	FILE* filename;
	filename = fopen("exported acccounts database", "w+");
	fprintf(filename, "%s %s ", "AhmedMohamed", "ABCJA1234A");
	fclose(filename);

}  
void Hard_coded_MONEY() {
	FILE* filename;
	filename = fopen("exported Money ", "w+");
	fprintf(filename," %lu", 2000000);
	fclose(filename);

}
void READ_IN_MONEY() {
	FILE* file = fopen("exported Money ", "r");
	cardex.exported_money = 0;

	fscanf(file, "%lu\n", &(cardex.exported_money));
	while (!feof(file))             //CHECK THE FILE ISNOT EMPTY 
	{
		printf("%lu ", cardex.exported_money);
		fscanf(file, "%lu\n", &(cardex.exported_money));
	}
	fclose(file);


} 
boolean isValidAccount() {
	if (strcmp(cardex.Name_holder_ex , card_1.Name_Holder)==0) {
		if (strcmp(cardex.PAN_NUM , card_1.PAN_NUM)==0) {
		
			printf("Valid PAN Matches with database \n");    //NOT SAME PAN IN THE DATA BASE 
			return Yes; 
		
		} 
		else { 
			printf("InValid PAN doesn't match database  \n");  // SMAE PAN IN THE DATA BASE 
			return No;
		}


	} 
	printf("InValid Name Holder doesn't match database \n");  //NOT THE SAME NAME HOLDER 
	exit(EXIT_SUCCESS);    //terminate program immediately 
	return No;

} 
boolean isAmountAvailable() {
	if ((cardex.exported_money >= card_1.Transaction_Amount_Card)) {
	
		printf("Valid amount of money \n"); 
		return Yes;
	
	}
	else {
		printf("InSufficient amount of money \n"); 
		exit(EXIT_SUCCESS);    //terminate program immediately
		return No;
	}


}
void saveTransaction() {
	if (isAmountAvailable() && isValidAccount()) {
		for (uint16 i = 0; i < 200; i++) {  
			/// DO NOTHING 
		 }  // Take some time before printing the screen 
		
		system("@cls||clear");  //CLEAR SYSTEM SCREEN 
		printf("Transation info\n"); 
		printf("Transaction Date : "); 
		getTransactionDate();  
		printf("Name Holder :"); 
		printf("%s \n ", cardex.Name_holder_ex);  
		printf("PAN Number : "); 
		printf("%s\n", cardex.PAN_NUM);  
		printf("Remind Money : "); 
		printf("%lu \n", (cardex.exported_money) - (card_1.Transaction_Amount_Card)); 
		printf("Transation saved thanks for banking with us \n");
		FILE* fopen(const char* path, const char* mode);
		FILE* fp;
		fp = fopen("saved transaction.txt", "w"); 
		fprintf(  fp," %s \n " , "Transation info");
		fprintf(fp, " %s \n", "Transaction Date : ");
		//char* pts; /* pointer to time string*/
		time_t now; /* current time*/
		char* ctime();
		(void)time(&now);
		fprintf(fp, "%s", ctime(&now));
		fprintf( fp ,"%s", "Name Holder :");
		fprintf( fp ,"%s \n ", cardex.Name_holder_ex);
		fprintf(fp, "%s", "PAN Number : ");
		fprintf(fp, "%s\n", cardex.PAN_NUM);
		fprintf(fp, "%s", "Remind Money : ");
		fprintf(fp, "%lu \n", (cardex.exported_money) - (card_1.Transaction_Amount_Card));
		fprintf(fp, "%s", "Transation saved thanks for banking with us \n");

		fclose(fp);
	
	} 
	else {
	
		printf("Bad Card\n");
		exit(EXIT_SUCCESS);    //terminate program immediately 
	}


}