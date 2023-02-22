#include <iostream>
#include <cstdlib>
using namespace std;
int queenArr[8], nlen = 8, nSolution = 0;
void ShowQueens() {
	/*解法数量*/ 
	cout<<"第"<<nSolution<<"种解法："<<endl;
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
	/*8个皇后已放置完毕*/ 
	if(r == nlen) {
		nSolution++;
		ShowQueens();
		return;
	}
	/*寻找第r个皇后的位置*/ 
	for(int i = 0; i < nlen; i++) {
		queenArr[r] = i;
		int ok = 1;
		for(int j = 0; j < r; j++) {
			if(queenArr[r] == queenArr[j] || abs(r - j) == abs(queenArr[r] - queenArr[j])) {
				ok = 0;
				break;
			}
		}
		/*寻找第r+1个皇后的位置*/ 
		if(ok)
			Search(r + 1); 
	} 
}

int main() {
	Search(0);
	return 0; 
}

