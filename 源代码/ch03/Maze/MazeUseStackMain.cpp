#include <stdio.h> 
#include <iostream>
#include "SeqStack.cpp"
#define START_I 1
#define START_J 1
#define END_I 6
#define END_J 8
#define ROW 8
#define COL 10
using namespace std; 
/*��ʼ���Թ�*/
int maze[ROW][COL] = { 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, 
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1}, 
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 1}, 
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, 
        {1, 1, 0, 0, 1, 1, 0, 0, 0, 1}, 
        {1, 0, 1, 1, 0, 0, 1, 1, 0, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
/*��ʼ����־λ��0����û�߹���1�����߹�*/
int mark[ROW][COL] = {0}; 
/*����*/
typedef struct{ 
    short int vert; 
    short int horiz; 
}offsets; 
/*��ǰλ�õ�8�������ң��£����ϣ����ϣ����£����ϣ�����*/ 
offsets move[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
/*�Թ�����*/
typedef struct element{ 
    short int row; 
    short int col; 
    short int dir; 
}element;

/*��ӡ�Թ�*/
void printMaze(int maze[][COL], int row) {
	cout<<"�Թ�Ϊ��"<<endl;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < COL; j++) {
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*��ӡ�����յ�*/
void printStartAndEnd() {
	cout<<"���Ϊ��("<<START_I<<","<<START_J<<")"<<endl;
	cout<<"�յ�Ϊ��("<<END_I<<","<<END_J<<")"<<endl; 
}

/*�Թ�����*/
void path() { 
	SeqStack<element> S;
    element position; 
    int i, row, col, next_row, next_col, dir, top; 
    int found = 0; 
    /*��1��1��ʼ����6��8����*/
    /*��ʼ����־����Ԫ��*/
    mark[START_I][START_J] = 1;
    element start;
    start.row = START_I, start.col = START_J, start.dir = 0;
    /*�������ջ*/ 
    S.Push(start);
    while(!S.Empty() && !found) { 
        position = S.Pop();  /*��ջ��Ԫ��ȡ��*/
        row = position.row; /*�����м����row,col,dir�Ⱥ��ж�*/
        col = position.col; 
        dir = position.dir; 
        while(dir < 8 && !found) { 
            next_row = row + move[dir].vert; 
            next_col = col + move[dir].horiz; 
            if(row == END_I && col == END_J) 
            	found = 1; 
            /*�ж���һ�����߲���û�߹�������ջ*/ 
            else if(!maze[next_row][next_col] && !mark[next_row][next_col]) { 
                mark[next_row][next_col] = 1; 
                position.row = row; 
                position.col = col; 
                position.dir = ++dir; 
                /*��������ջ*/
                S.Push(position);
                /*����������*/
                row = next_row;
                col = next_col;
				dir = 0; 
            }
            else 
            	/*dir<8ʱ���ı䷽��*/ 
                dir++;
        } 
        /*�ж��Ƿ��г���*/
        if(found) { 
        	SeqStack<element> R;
        	/*���յ���ջ*/ 
        	element end;
        	end.row = END_I;
        	end.col = END_J;
        	end.dir = 0;
        	S.Push(end);
			cout<<"����·��:"<<endl;
			/*����ջR��ջS�е�·������ջ�׵�ջ����˳�����*/ 
			while(!S.Empty()) {
				element e = S.Pop();
				R.Push(e);
			}
			while(!R.Empty()) {
				element e = R.Pop();
				cout<<"("<<e.row<<","<<e.col<<")"; 
			}     
       	}                 
    }
    if(found == 0)
        cout<<"������·����";
}

int main() {   
	printMaze(maze, ROW);
	printStartAndEnd();
    path(); 
    return 0; 
}
