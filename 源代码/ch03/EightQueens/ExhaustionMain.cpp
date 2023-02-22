#include <iostream>
#include <cstdlib>
using namespace std;

/*��ӡ���̺ͻʺ�*/ 
void ShowQueens(int queenArr[], int nlen, int nSolution) {
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

/*�ж��Ƿ���Ϲ���*/
bool Rule(int queenArr[]) {  
    for(int i = 0; i <= 7; ++i) {
        for(int j = 0; j <= i-1; ++j) {
        		/*�жϻʺ��Ƿ���ͬһ��*/
                if(queenArr[i] == queenArr[j]) {
                    return true;
                }
                /*�жϻʺ��Ƿ���ͬһб����*/ 
                if(abs(queenArr[i] - queenArr[j]) == abs(i - j)) {
                    return true;
                }
        }
    }
    return false;
}

/*�ƶ��ʺ�*/
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
    /*ÿ�������ʾһ���*/
	int queenArr[8]; 
	/*�ⷨ����*/
    int nSolution = 0;
    EnumQueensPositon(queenArr, nSolution);
    return 0; 
}
