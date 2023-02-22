/*找词，在指定字符矩阵中按照*/ 
#include <iostream>
#include <string>
using namespace std;

/*字符矩阵的行列值*/
const int MaxSize = 16;
/*词典长度*/
const int WordsCount = 13; 
/*字符矩阵*/
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
/*词典*/
string words[WordsCount] = {"VENUS", "EARTH", "MARS", "CERES", "ASTEROIDS", "JUPITER", "SATURN", "NEPTUNE", "URANUS", "PLUTO", "DWARF", "PLANET", "MOON"};
/*标记矩阵*/
bool flag[MaxSize][MaxSize];
/*查找方向，分别对应上、下、左、右、右上、左下、右下、左上*/
int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
/*当前查找的步数*/
int step;
 
/*输出矩阵函数*/
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
 
/*在字符矩阵中搜索单词*/
void SearchWord(string word, int i, int j, int k) {
    /*查找步数*/
    step++;
    /*找到单词*/
    if(step == word.size()) {
        /*标记找到单词*/
        flag[i][j] = true;
        /*退出*/
        return;
    }
    int x, y;
    /*向着某方向寻找*/
    x = i + dir[k][0];
    y = j + dir[k][1];
    /*字符匹配则继续递归查找*/
    if (x >= 0 && x < MaxSize && y >= 0 && y < MaxSize && charMatrix[x][y] == word[step]) {
        SearchWord(word, x, y, k);
        /*找到完整的单词则做标记*/
        if(step == word.size()) 
			flag[i][j] = true;
    }
}
 
/*查找单词*/
void FindAllWords(string word) {
    int i, j;
    for(i = 0; i < MaxSize; i++) {
        for(j = 0;j < MaxSize;j++) {
            /*首字符匹配开始查找*/
            if(charMatrix[i][j] == word[0]) {
            	/*查找方向*/ 
                int k;
                /*向八个方向搜索*/
                for(k = 0; k < 8; k++) {
                    step = 0;
                    SearchWord(word, i, j, k);
                    /*找到单词则返回*/
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
