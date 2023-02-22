#include "SeqStack.cpp"
#include <iostream>
#include <string.h>
using namespace std;
/*��׺���ʽ�а���{}��[]��()����'#'�������жϸ��������Ƿ�ƥ��*/
int IsBracketMatching() {
	SeqStack<char> S; /*��ʼ����˳��ջ*/
	int i = 0;
	char c;
	c = getchar();
	while(c != '#') {
		switch(c) {
			case '{':
			case '[':
			case '(':
				S.Push(c);
				break;
			case '}':
				if(S.Pop() != '{')	
					return 0;
				break;
			case ']':
				if(S.Pop() != '[')
					return 0;
				break;
			case ')':
				if(S.Pop() != '(')
					return 0;
				break;
			default:
				break; 
		}
		c = getchar();
	}
	if(!S.Empty()) {
		return 0;
	}
	return 1;
}

int main() {	
	cout<<"��������ʽ����'#'��������"<<endl;
	int r = IsBracketMatching();
	if(!r) {
		cout<<"���Ų�ƥ�䣡"<<endl; 
	} 
	else {
		cout<<"����ƥ�䣡"<<endl; 
	}
	return 0;
}
