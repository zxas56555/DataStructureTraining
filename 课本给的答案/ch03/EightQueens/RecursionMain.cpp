#include <iostream>
#include <cstdlib>
using namespace std;
int queenArr[8], nlen = 8, nSolution = 0;
void ShowQueens() {
	/*�ⷨ����*/ 
	cout<<"��"<<nSolution<<"�ֽⷨ��"<<endl;
	for(int i = 0; i < nlen; i++) {
		for(int j = 0; j < nlen; j++) {
			if(j == queenArr[i])
				cout<<"Q ";
			else
				cout<<"1 ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void Search(int r) {
	/*8���ʺ��ѷ������*/ 
	if(r == nlen) {
		nSolution++;
		ShowQueens();
		return;
	}
	/*Ѱ�ҵ�r���ʺ��λ��*/ 
	for(int i = 0; i < nlen; i++) {
		queenArr[r] = i;
		int ok = 1;
		for(int j = 0; j < r; j++) {
			if(queenArr[r] == queenArr[j] || abs(r - j) == abs(queenArr[r] - queenArr[j])) {
				ok = 0;
				break;
			}
		}
		/*Ѱ�ҵ�r+1���ʺ��λ��*/ 
		if(ok)
			Search(r + 1); 
	} 
}

int main() {
	Search(0);
	return 0; 
}

