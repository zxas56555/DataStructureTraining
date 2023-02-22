#include "SeqStack.cpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define OperaterSetSize  7
using namespace std;
char OperaterSet[OperaterSetSize] = {'+', '-', '*', '/', '(', ')', '#'};
/*�����������ȹ�ϵ*/
unsigned char Prior[7][7] = {     
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>', 
   '<', '<', '<', '<', '<', '=', ' ',
   '>', '>', '>', '>', ' ', '>', '>',
   '<', '<', '<', '<', '<', ' ', '='
};
 
/*�ж�c�Ƿ��������*/
int IsOperator(char c) {
	int flag = 0;
	for(int i = 0; i < OperaterSetSize; i++) {
		if(c == OperaterSet[i]) {
			flag = 1;
			break;
		}
	}
	return flag;
} 

/*���������oper������������е����*/ 
int ReturnOpOrd(char oper) {
   for(int i = 0; i < OperaterSetSize; i++) {
   		if (oper == OperaterSet[i]) {
      		return i;
	  }
   }
   return -1;
}

/*�Ƚ���������������ȼ��������ַ�>,<,=*/ 
char Priority(char c1, char c2) {
	int i,j;
	i = ReturnOpOrd(c1);
	j = ReturnOpOrd(c2);
	return Prior[i][j];
}

/*�������㺯����ֻ��+,-,*,/ */ 
double Operate(double a, unsigned char c, double b) {
	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return 0;
	}
}

/*�������ʽ��ֵ����������㷨*/
void InToPostfix() {
	SeqStack<char> OPTR;
	OPTR.Push('#');
	char c, oper, cton[2];
	char tmp[10];
	float data;
	c = getchar();
	/*��tmp��Ϊ��*/
   	strcpy(tmp, "\0");
   	while (c != '#' || OPTR.GetTop() != '#') {
		/*c�ǲ�����,����������#�ָ������*/ 
		if(!IsOperator(c)) {
        	cton[0] = c;
        	cton[1] = '\0'; /*��ŵ�����*/
        	strcat(tmp, cton); /*������������tmp�У��γ��ַ���*/
        	c = getchar();
        	/*�����������������ַ���tmpת���ɸ���������ջ���������ÿ�*/
        	if(IsOperator(c)) {
        		data = (float)atof(tmp);
        		cout<<data;
        		cout<<"#"; 
            	strcpy(tmp, "\0");
        	}
    	}
    	/*c�������*/ 
   		else {
        	switch(Priority(OPTR.GetTop(), c)) { 
            	case '<': /*ջ��Ԫ������Ȩ��*/
                	OPTR.Push(c);
                 	c = getchar();
                 	break;
            	case '=': /*�����Ų�������һ�ַ�*/
                 	OPTR.Pop();   
                 	c = getchar();
                 	break;
            	case '>': /*��ջ���������������ǰ�ַ�*/ 
            		oper = OPTR.Pop();
            		cout<<oper; 
                 	break;
                default:
                	break;
         	}
        }
    }	
}

int main() {
	cout<<"��������׺���ʽ����'#'��������"<<endl;
	InToPostfix();
	return 0;
}
