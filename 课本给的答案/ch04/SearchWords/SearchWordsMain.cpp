/*�Ҵʣ���ָ���ַ������а���*/ 
#include <iostream>
#include <string>
using namespace std;

/*�ַ����������ֵ*/
const int MaxSize = 16;
/*�ʵ䳤��*/
const int WordsCount = 13; 
/*�ַ�����*/
char charMatrix[MaxSize][MaxSize] = {{'D','H','O','B','S','H','N','E','P','T','U','N','E','Y','T','M'},
	              {'U','E','J','I','H','U','N','Y','S','T','H','A','O','R','T','M'},
	              {'D','N','A','U','U','E','E','E','M','A','E','N','W','A','T','M'},
	              {'W','N','A','I','P','L','U','T','O','N','A','O','D','H','T','M'},
	              {'A','G','H','P','L','I','Z','O','O','E','R','U','S','U','T','M'},
	              {'R','D','E','I','H','C','T','M','N','W','T','N','S','H','T','M'},
	              {'F','H','Y','H','O','P','B','E','O','Q','H','I','U','E','T','M'},
	              {'R','A','C','O','E','A','A','R','R','T','E','O','A','E','T','M'},
	              {'U','S','A','T','U','R','N','C','P','L','A','N','E','T','T','M'},
	              {'R','T','A','E','H','F','T','U','E','U','L','E','E','E','T','M'},
	              {'I','E','U','C','U','F','A','R','O','V','C','E','I','O','T','M'},
	              {'A','R','F','A','I','R','A','Y','A','O','E','I','R','H','T','M'},
	              {'T','O','A','I','N','I','A','B','E','A','R','N','A','E','T','M'},
	              {'O','I','A','T','E','O','E','N','A','A','E','H','U','A','T','M'},
	              {'E','D','I','D','D','O','E','D','U','T','S','E','T','S','T','M'},
	              {'E','S','Z','E','E','H','O','P','H','S','L','U','M','S','T','M'}};
/*�ʵ�*/
string words[WordsCount] = {"VENUS", "EARTH", "MARS", "CERES", "ASTEROIDS", "JUPITER", "SATURN", "NEPTUNE", "URANUS", "PLUTO", "DWARF", "PLANET", "MOON"};
/*��Ǿ���*/
bool flag[MaxSize][MaxSize];
/*���ҷ��򣬷ֱ��Ӧ�ϡ��¡����ҡ����ϡ����¡����¡�����*/
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
/*��ǰ���ҵĲ���*/
int step;
 
/*���������*/
void PrintResult() {
    int i,j;
    for(i = 0; i < MaxSize; i++) {
        for(j = 0;j < MaxSize; j++) {
            if(flag[i][j] == true)
                cout<<charMatrix[i][j]<<" ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }    
}
 
/*���ַ���������������*/
void SearchWord(string word, int i, int j, int k) {
    /*���Ҳ���*/
    step++;
    /*�ҵ�����*/
    if(step == word.size()) {
        /*����ҵ�����*/
        flag[i][j] = true;
        /*�˳�*/
        return;
    }
    int x, y;
    /*����ĳ����Ѱ��*/
    x = i + dir[k][0];
    y = j + dir[k][1];
    /*�ַ�ƥ��������ݹ����*/
    if (x >= 0 && x < MaxSize && y >= 0 && y < MaxSize && charMatrix[x][y] == word[step]) {
        SearchWord(word, x, y, k);
        /*�ҵ������ĵ����������*/
        if(step == word.size()) 
			flag[i][j] = true;
    }
}
 
/*���ҵ���*/
void FindAllWords(string word) {
    int i, j;
    for(i = 0; i < MaxSize; i++) {
        for(j = 0;j < MaxSize;j++) {
            /*���ַ�ƥ�俪ʼ����*/
            if(charMatrix[i][j] == word[0]) {
            	/*���ҷ���*/ 
                int k;
                /*��˸���������*/
                for(k = 0; k < 8; k++) {
                    step = 0;
                    SearchWord(word, i, j, k);
                    /*�ҵ������򷵻�*/
                    if(step == word.size()) 
						return;
                }
            }
        }
    }
}

int main() {
    int i;
    for(i = 0; i < WordsCount; i++)
    	FindAllWords(words[i]);
    PrintResult();
    return 0;
}
