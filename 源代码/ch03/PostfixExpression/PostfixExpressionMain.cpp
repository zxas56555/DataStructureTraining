#include <iostream>
using namespace std;
#include "SeqStack.cpp"
float PostExpression(char postexp[]) {
	SeqStack<float> S; /*³õÊ¼»¯¿ÕË³ÐòÕ»*/
	int i = 0;
	float a, b;
	while(postexp[i] != '\0') {
		switch(postexp[i]) {
			/*ÔËËã·û+ */
			case '+':
				a = S.Pop();
				b = S.Pop();
				S.Push(a + b);
				break;
			/*ÔËËã·û- */ 
			case '-':
				a = S.Pop();
				b = S.Pop();
				S.Push(b - a);
				break;
			/*ÔËËã·û* */ 
			case '*':
				a = S.Pop();
				b = S.Pop();
				S.Push(a * b);
				break;
			/*ÔËËã·û/ */ 
			case '/':
				a = S.Pop();
				b = S.Pop();
				if(a != 0) {
					S.Push(b / a);
				}
				else {
					throw "³ýÁã´íÎó£¡";
				}
				break;
			default:
				/*´¦ÀíÊý×Ö×Ö·û*/
				float d = 0;
				while(postexp[i] >= '0' && postexp[i] <= '9') {
					d = 10 * d + postexp[i] - '0';
					i++;
				}
				S.Push(d);
				break; 
		}
		i++;
	}
	return S.GetTop();
}

int main() { 
	char exp[] = "89#60#-12#8#-*";
	float result = PostExpression(exp);
	cout<<result;
    return 0;    
}

