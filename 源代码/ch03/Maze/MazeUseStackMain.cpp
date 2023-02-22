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
/*初始化迷宫*/
int maze[ROW][COL] = { 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, 
        {1, 1, 0, 1, 0, 1, 1, 1, 1, 1}, 
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 1}, 
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 1}, 
        {1, 1, 0, 0, 1, 1, 0, 0, 0, 1}, 
        {1, 0, 1, 1, 0, 0, 1, 1, 0, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
/*初始化标志位，0代表没走过，1代表走过*/
int mark[ROW][COL] = {0}; 
/*方向*/
typedef struct{ 
    short int vert; 
    short int horiz; 
}offsets; 
/*当前位置的8个方向，右，下，左，上，左上，左下，右上，右下*/ 
offsets move[8] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
/*迷宫类型*/
typedef struct element{ 
    short int row; 
    short int col; 
    short int dir; 
}element;

/*打印迷宫*/
void printMaze(int maze[][COL], int row) {
	cout<<"迷宫为："<<endl;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < COL; j++) {
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*打印起点和终点*/
void printStartAndEnd() {
	cout<<"起点为：("<<START_I<<","<<START_J<<")"<<endl;
	cout<<"终点为：("<<END_I<<","<<END_J<<")"<<endl; 
}

/*迷宫函数*/
void path() { 
	SeqStack<element> S;
    element position; 
    int i, row, col, next_row, next_col, dir, top; 
    int found = 0; 
    /*从1，1开始，到6，8结束*/
    /*初始化标志数组元素*/
    mark[START_I][START_J] = 1;
    element start;
    start.row = START_I, start.col = START_J, start.dir = 0;
    /*将起点入栈*/ 
    S.Push(start);
    while(!S.Empty() && !found) { 
        position = S.Pop();  /*将栈顶元素取出*/
        row = position.row; /*利用中间变量row,col,dir等候判断*/
        col = position.col; 
        dir = position.dir; 
        while(dir < 8 && !found) { 
            next_row = row + move[dir].vert; 
            next_col = col + move[dir].horiz; 
            if(row == END_I && col == END_J) 
            	found = 1; 
            /*判断下一步可走并且没走过，则入栈*/ 
            else if(!maze[next_row][next_col] && !mark[next_row][next_col]) { 
                mark[next_row][next_col] = 1; 
                position.row = row; 
                position.col = col; 
                position.dir = ++dir; 
                /*合理则入栈*/
                S.Push(position);
                /*继续向下走*/
                row = next_row;
                col = next_col;
				dir = 0; 
            }
            else 
            	/*dir<8时，改变方向*/ 
                dir++;
        } 
        /*判断是否有出口*/
        if(found) { 
        	SeqStack<element> R;
        	/*将终点入栈*/ 
        	element end;
        	end.row = END_I;
        	end.col = END_J;
        	end.dir = 0;
        	S.Push(end);
			cout<<"存在路径:"<<endl;
			/*利用栈R将栈S中的路径按从栈底到栈顶的顺序输出*/ 
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
        cout<<"不存在路径！";
}

int main() {   
	printMaze(maze, ROW);
	printStartAndEnd();
    path(); 
    return 0; 
}
