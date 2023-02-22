#include "SeqStack.cpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define OperaterSetSize  7
using namespace std;
char OperaterSet[OperaterSetSize] = {'+', '-', '*', '/', '(', ')', '#'};
/*运算符间的优先关系*/
unsigned char Prior[7][7] = {     
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '<', '<', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>',
   '>', '>', '>', '>', '<', '>', '>', 
   '<', '<', '<', '<', '<', '=', ' ',
   '>', '>', '>', '>', ' ', '>', '>',
   '<', '<', '<', '<', '<', ' ', '='
};
 
/*判断c是否是运算符*/
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

/*返回运算符oper在运算符数组中的序号*/ 
int ReturnOpOrd(char oper) {
   for(int i = 0; i < OperaterSetSize; i++) {
   		if (oper == OperaterSet[i]) {
      		return i;
	  }
   }
   return -1;
}

/*比较两个运算符的优先级，返回字符>,<,=*/ 
char Priority(char c1, char c2) {
	int i,j;
	i = ReturnOpOrd(c1);
	j = ReturnOpOrd(c2);
	return Prior[i][j];
}

/*符号运算函数，只有+,-,*,/ */ 
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

/*算术表达式求值的算符优先算法*/
void InToPostfix() {
	SeqStack<char> OPTR;
	OPTR.Push('#');
	char c, oper, cton[2];
	char tmp[10];
	float data;
	c = getchar();
	/*将tmp置为空*/
   	strcpy(tmp, "\0");
   	while (c != '#' || OPTR.GetTop() != '#') {
		/*c是操作数,将操作数用#分隔并输出*/ 
		if(!IsOperator(c)) {
        	cton[0] = c;
        	cton[1] = '\0'; /*存放单个数*/
        	strcat(tmp, cton); /*将单个数连到tmp中，形成字符串*/
        	c = getchar();
        	/*如果遇到运算符，则将字符串tmp转换成浮点数，入栈，并重新置空*/
        	if(IsOperator(c)) {
        		data = (float)atof(tmp);
        		cout<<data;
        		cout<<"#"; 
            	strcpy(tmp, "\0");
        	}
    	}
    	/*c是运算符*/ 
   		else {
        	switch(Priority(OPTR.GetTop(), c)) { 
            	case '<': /*栈顶元素优先权低*/
                	OPTR.Push(c);
                 	c = getchar();
                 	break;
            	case '=': /*脱括号并接收下一字符*/
                 	OPTR.Pop();   
                 	c = getchar();
                 	break;
            	case '>': /*退栈并输出，继续处理当前字符*/ 
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
	cout<<"请输入中缀表达式（以'#'结束）："<<endl;
	InToPostfix();
	return 0;
}
