#include <stdio.h> 
#include <iostream>
#define START_I 1
#define START_J 1
#define END_I 6
#define END_J 8
#define ROW 8
#define COL 10
using namespace std; 

int main() {
    int i, j;
    printMaze(maze, ROW);
    printStartAndEnd();
	if(VisitMaze(maze, START_I, START_J) == 0) {
		cout<<"û��·�����ߣ�"<<endl;
		return 0;
	}
	else {
		cout<<"����·����·��Ϊ���2��λ�ã�"<<endl;
		printMaze(maze, ROW); 
	}
	return 0;
}
