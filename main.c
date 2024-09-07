#include "treat_mask.h"
#include "treat_ip.h"
#include <stdio.h>
#include "without_class.h"
#define LENGTH 50
#define BIT_LENGTH 50
int main(){
	//entier
	int first_bit=256;
	int second_bit=256;
	int third_bit=256;
	int last_bit=256;
	int bit_network=-1;
	int first_bit_1;
	int second_bit_1;
	int third_bit_1;
	int last_bit_1;
	//caractere
	char last_word='\0';
	char class_indice;
	//chaine
	char network[LENGTH];
	char ip[LENGTH];
	char MSR[BIT_LENGTH];
	char first_byte[9];
	char second_byte[9];
	char third_byte[9];
	char last_byte[9];
	//traitement de l'ip
	input_ip(ip);
	treat_ip(ip,&first_bit,&second_bit,&third_bit,&last_bit,&last_word);
	verify_ip(first_bit,second_bit,third_bit,last_bit,last_word,&class_indice);
	//traitement de mask
	bit_network=input_bit_network(ip);
	convert_binary(ip,first_bit,second_bit,third_bit,last_word);
	verify_bit(bit_network);
	treat_msr(bit_network,MSR);
	sectioning(MSR,first_byte,second_byte,third_byte,last_byte);	
	reconvert_decimal(first_byte,second_byte,third_byte,last_byte,&first_bit,&second_bit,&third_bit,&last_bit);
	adressing_network(network,ip,MSR);
	cat_binary(network,first_byte,second_byte,third_byte,last_byte);
	reconvert_decimal(first_byte,second_byte,third_byte,last_byte,&first_bit_1,&second_bit_1,&third_bit_1,&last_bit_1);
	print(first_bit,second_bit,third_bit,last_bit,first_bit_1,second_bit_1,third_bit_1,last_bit_1);
	reconvert(MSR);
	adressing_broadcast(network,ip,MSR);
	sectioning(network,first_byte,second_byte,third_byte,last_byte);
	convert_decimal_mask(first_byte,second_byte,third_byte,last_byte,first_bit,second_bit,third_bit,last_bit);
	return 0;
}
