#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(char message[],char eMessage[], int lowLimit, int hiLimit, int estado)
{
    int comprobante,aux;
    do{
    printf("%s",message);
    fflush(stdin);
    comprobante = scanf("%d",&aux);
    if(comprobante == 1)
    {
        if((aux<=hiLimit && aux>=lowLimit) || estado==0)
        {
            return aux;
        }
    }
    printf("%s",eMessage);
    }while(1);
}


float getFloat(char message[],char eMessage[], float lowLimit, float hiLimit, int estado)
{
    float comprobante,aux;
    do{
    printf("\nIngrese un decimal: ");
    fflush(stdin);
    comprobante = scanf("%f",&aux);
    if(comprobante == 1)
    {
        if((aux<hiLimit && aux>lowLimit) || estado==0)
        {
                return aux;
        }
    }
    printf("%s",eMessage);
    }while(1);
}

char getChar(char message[],char eMessage[], char lowLimit, char hiLimit, int estado)
{
    char comprobante,aux;
    do{
    printf("%s",message);
    fflush(stdin);
    comprobante = scanf("%c",&aux);
    if(comprobante == 1)
    {
        if((aux<hiLimit && aux>lowLimit) || estado==0)
        {
            return aux;
        }
    }
    printf("%s",eMessage);
    }while(1);
}

char getString(char message[],char eMessage[], int lowLimit, int hiLimit, int estado)
{
    char auxs[100],aux[100];
    int largo;
    do{
    printf("%s",message);
    fflush(stdin);
    scanf("%s",auxs);
    strcpy(aux,auxs);
    largo = strlen(aux);
    if((largo<hiLimit && largo>lowLimit) || estado==0)
    {
            return *auxs;
    }
    printf("%s",eMessage);
    }while(1);
}
