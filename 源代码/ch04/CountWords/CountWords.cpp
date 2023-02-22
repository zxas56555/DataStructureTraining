#include <iostream>
#include <string.h>
using namespace std;
int CountWordsOfTxtFile(char *FileName);
int CountWordsInOneLine(const char *Line);
int main() {
	char name[10] = {"tmp.txt"};
	cout<<"�ļ��еĵ��ʸ���Ϊ"<<CountWordsOfTxtFile(name);
	return 0;
}

int CountWordsOfTxtFile(char *FileName) {
	/*ͳ�Ƶ���������ʼֵΪ0*/
	int nWords = 0;
	/*�ļ�ָ��*/
	FILE *fp; 
	/*ÿ���ַ����壬ÿ�����1024���ַ�*/
	char carrBuffer[1024];
	/*���ļ����ɹ�*/ 
	if((fp = fopen(FileName, "r")) == NULL) {
		return -1;
	}
    /*���û�ж����ļ�ĩβ*/ 
	while (!feof(fp)) {
		/*���ļ��ж�һ��*/
		if (fgets(carrBuffer, sizeof(carrBuffer), fp) != NULL) {
			/*ͳ��ÿ�д���*/
			nWords += CountWordsInOneLine(carrBuffer);  
		} 
	}
	/*�ر��ļ�*/
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
