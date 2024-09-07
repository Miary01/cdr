#include "class.h"
#include <stdio.h>
#include <string.h>
void recadre (char*mask) {
    char temp[36];
    strcpy(temp,"");
    for(int i=0;i<32;i++){
        if(i<8)             strcat(temp,mask[i]);
        if(i==8)            strcat(temp," ");
        if(i>8 && i<17)     strcat(temp,mask[i-1]);
        if(i==17)           strcat(temp," ");
        if(i>17 && i<25)    strcat(temp,mask[i-2]);
        if(i==25)           strcat(temp," ");
        if(i>25 && i<32)    strcat(temp,mask[i-3]);
    }
    printf("%s\n",temp);

}
void masking(int bit,char*mask) {
    strcpy(mask,"");
    for(int i=0;i<32;i++){
        if(i<bit)   strcat(mask,"1");
        else        strcat(mask,"0");
    }

}
int enter_bit_number(char*ip) {
    int bit;
    printf("Entrer le nombre de bit reseau :\n");
    printf("%s/",ip);
    scanf("%d",&bit);
    return bit;
}
