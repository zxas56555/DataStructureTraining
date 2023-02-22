#include <iostream>
#include <string.h>
using namespace std;
int CountWordsOfTxtFile(char *FileName);
int CountWordsInOneLine(const char *Line);
int main() {
	char name[10] = {"tmp.txt"};
	cout<<"文件中的单词个数为"<<CountWordsOfTxtFile(name);
	return 0;
}

int CountWordsOfTxtFile(char *FileName) {
	/*统计单词数，初始值为0*/
	int nWords = 0;
	/*文件指针*/
	FILE *fp; 
	/*每行字符缓冲，每行最多1024个字符*/
	char carrBuffer[1024];
	/*打开文件不成功*/ 
	if((fp = fopen(FileName, "r")) == NULL) {
		return -1;
	}
    /*如果没有读到文件末尾*/ 
	while (!feof(fp)) {
		/*从文件中读一行*/
		if (fgets(carrBuffer, sizeof(carrBuffer), fp) != NULL) {
			/*统计每行词数*/
			nWords += CountWordsInOneLine(carrBuffer);  
		} 
	}
	/*关闭文件*/
	fclose(fp);
	return nWords;
}

int CountWordsInOneLine(const char *Line) {
	int nWords = 0;
	for (int i = 0; i < strlen(Line); i++) {
		if (*(Line+i) != ' ') {
			nWords++;
			while ((*(Line+i) != ' ') && (*(Line+i) != '\0')) {
				i++;
			}
		}
	}
	return nWords;
}
