#include "SeqStack.cpp"
#include <iostream>
#include <string.h>
using namespace std;
/*中缀表达式中包括{}、[]、()，以'#'结束，判断各种括号是否匹配*/
int IsBracketMatching() {
	SeqStack<char> S; /*初始化空顺序栈*/
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
	cout<<"请输入表达式（以'#'结束）："<<endl;
	int r = IsBracketMatching();
	if(!r) {
		cout<<"括号不匹配！"<<endl; 
	} 
	else {
		cout<<"括号匹配！"<<endl; 
	}
	return 0;
}
