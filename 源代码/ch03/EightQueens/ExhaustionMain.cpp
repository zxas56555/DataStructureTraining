#include <iostream>
#include <cstdlib>
using namespace std;

/*打印棋盘和皇后*/ 
void ShowQueens(int queenArr[], int nlen, int nSolution) {
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

/*判断是否符合规则*/
bool Rule(int queenArr[]) {  
    for(int i = 0; i <= 7; ++i) {
        for(int j = 0; j <= i-1; ++j) {
        		/*判断皇后是否在同一列*/
                if(queenArr[i] == queenArr[j]) {
                    return true;
                }
                /*判断皇后是否在同一斜线上*/ 
                if(abs(queenArr[i] - queenArr[j]) == abs(i - j)) {
                    return true;
                }
        }
    }
    return false;
}

/*移动皇后*/
void EnumQueensPositon(int queenArr[], int &nSolution) {
    for(queenArr[0] = 0; queenArr[0] < 8; ++queenArr[0])
        for(queenArr[1] = 0; queenArr[1] < 8; ++queenArr[1])
            for(queenArr[2] = 0; queenArr[2] < 8; ++queenArr[2])
                for(queenArr[3] = 0; queenArr[3] < 8; ++queenArr[3])
                    for(queenArr[4] = 0; queenArr[4] < 8; ++queenArr[4])
                        for(queenArr[5] = 0; queenArr[5] < 8; ++queenArr[5])
                            for(queenArr[6] = 0; queenArr[6] < 8; ++queenArr[6])
                                for(queenArr[7] = 0; queenArr[7] < 8; ++queenArr[7]) {
                                    if(Rule(queenArr)) {
                                        continue;
                                    }
                                    else {
                                        ++nSolution;
                                        ShowQueens(queenArr, 8, nSolution);
                                    }
								}
}

int main() {
    /*每个数组表示一组解*/
	int queenArr[8]; 
	/*解法数量*/
    int nSolution = 0;
    EnumQueensPositon(queenArr, nSolution);
    return 0; 
}
