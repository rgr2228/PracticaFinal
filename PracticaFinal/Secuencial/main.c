#include <stdio.h>
#include "string.h"

int getColumnSize(char *column);
int getDotProduct(char *vector1, char *vector2, int rowSize, int columnSize);

int main(int argc, char const *argv[])
{
    FILE *fp, *fp2;
    int MAXCHAR = 1000, result = 0;
    char str[MAXCHAR];
    char str2[MAXCHAR];
    char vector1[MAXCHAR], vector2[MAXCHAR];
    int rowSize1 = 0, rowSize2 = 0, columnSize1 = 0, columnSize2 = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Could not open file %s", argv[1]);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL){
        if(columnSize1 == 0){
            columnSize1 = getColumnSize(str);
        }
        else{
            if(columnSize1 != getColumnSize(str))
            {
                printf("\ncolumnSize1=%d y la otra=%d \n",columnSize1,getColumnSize(str));
                printf("All the column sizes must have the same value\n");
                return 1;
            } else
            {
                printf("\ncolumnSize1=%d y la otra=%d \n",columnSize1,getColumnSize(str));
            }
                
        }
        rowSize1 = rowSize1 + 1;
        strcat(vector1, str);
        printf("\nstr=%s\n", str);
        printf("\nvector1=%s\n",str);
    }
        
    fclose(fp);
    fp2 = fopen(argv[2],"r");
    if (fp == NULL)
    {
        printf("Could not open file %s", argv[2]);
        return 1;
    }
    while (fgets(str2, MAXCHAR, fp2) != NULL){
        printf("\nfirst str2=%s\n",str2);
        if(columnSize2 == 0)
            columnSize2 = getColumnSize(str2);
        else{
            if(columnSize2 != getColumnSize(str2))
            {
                printf("All the column sizes must have the same value\n");
                return 1;
            }
                
        }
        rowSize2 = rowSize2 + 1;
        strcat(vector2, str2);
        printf("\nstr2=%s\n", str2);
        printf("\nvector2=%s\n",vector2);
    }
    &vector2[0] = &vector2[0] + 1;
     printf("\nvector2 después=%s\n",vector2);
    fclose(fp2);

    if(rowSize1 != rowSize2 || columnSize1 != columnSize2){
        printf("Vectors with different sizes");
        return 1;
    }
    //vector1[0]=' ';
    //vector2[0]=' ';

    printf("Size row 1:%d\nSize row 2:%d\nSize column 1:%d\nSize column 2:%d\n",rowSize1, rowSize2,columnSize1,columnSize2);
    printf("Vector1:%s \nVector2:%s", vector1, vector2);


    result = getDotProduct(vector1,vector2, rowSize1, columnSize1);

    printf("\nThe dot pruduct is equal to: %d", result);
    return 0;
}

int getColumnSize(char *column){
    int size = 0;
    int i = 0;
    while(column[i]!='\0'){
        if((column[i]!=' ')&&(column[i]!='\n')){
            size = size + 1;
        }
        i = i + 1;
    }
    return size;

}

int getDotProduct(char *charVector1, char *charVector2, int rowSize, int columnSize){
    int j = 0, i = 0, x = 0;
    int numVector1[rowSize][columnSize];
    int numVector2[rowSize][columnSize];
    int aux=0, aux1,aux2;
    while(charVector1[x]!='\0'){
        if(charVector1[x] == '\n'){
            j = j + 1;
            i=0;
        }
        else{
            if(charVector1[x] != ' '){
                i = i + 1;
                aux1 = charVector1[x] - 48;
                aux2 = charVector2[x] - 48;
                //numVector1[i][j] = aux1;
                //printf("\nResult1:%d",numVector1[i][j]);
                //numVector2[i][j] = aux2;
                //printf("\nResult2:%d",numVector2[i][j]);
                //aux= aux + (numVector1[i][j]*numVector2[i][j]);
                aux= aux + (aux1*aux2);
            }
        }
        x = x + 1;
    }
    printf("\naux=%d",aux);
    return aux;
}