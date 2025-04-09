#include <stdio.h>
int StringLen(char str[]);  /* WordLen �Լ��� �̸��� ���� */
int IsOperator(char ch);
int StringToNumber(char str[], int sIdx, int eIdx);
 
int main(void)
{
    char exp[20];
    char oper;  /* ������ */
    char operIdx;
    
    int i;
    int strLen, isOp;
    int op1, op2;
    
    printf("���� �Է�: ");
    scanf("%s", exp);
    strLen=StringLen(exp);
    
    /* ������ ���� */
    for(i=0; i<strLen; i++)
    {
        isOp=IsOperator(exp[i]);
        if(isOp==1)
        {
            oper=exp[i];
            operIdx=i;
        }
    }
 
    /* �ǿ����� ���� */
    op1=StringToNumber(exp, 0, operIdx-1);
    op2=StringToNumber(exp, operIdx+1, strLen-1);
    
    switch(oper)
    {
    case '+':
        printf("%d+%d=%d \n", op1, op2, op1+op2);
        break;
 
    case '-':
        printf("%d-%d=%d \n", op1, op2, op1-op2);
        break;
 
    case '*':
        printf("%d*%d=%d \n", op1, op2, op1*op2);
        break;
 
    case '/':
        printf("%d/%d=%d \n", op1, op2, op1/op2);
        break;
    }
 
    return 0;
}
 
int IsOperator(char ch)
{
    if(ch=='+' ||ch=='-' ||ch=='*' ||ch=='/')
        return 1;
    else
        return 0;
}
 
int StringLen(char str[])
{
    int len=0;
    
    while(1)
    {
        if(str[len]=='\0')
            return len;
        
        len++;
    }
}
 
int StringToNumber(char str[], int sIdx, int eIdx)
{
    int num=0;
    int cipher=1;
    int i;
    int diff='1'-1;
 
    for(i=eIdx; i>=sIdx; i--)
    {
        num += cipher*(str[i]-diff);
        cipher*=10;
    }
    
    return num;
}


