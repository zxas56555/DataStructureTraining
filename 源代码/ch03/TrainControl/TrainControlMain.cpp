#include <iostream>
using namespace std;
int count = 1; /*满足出栈序列条件的序号*/
void Print(int array[], int n); /*判断array是否满足出栈序列条件，若满足，输出array*/
void Perm(int array[], int k, int n) {
	int i, temp;
	if(k == n - 1)
		Print(array, n); /*k和n-1相等，即一趟递归走完*/ 
	else {
		for(i = k; i < n; i++) { /*把当前节点元素与后续节点元素交换*/ 
			temp = array[k];/*交换*/
			array[k] = array[i]; 
			array[i] = temp;
			Perm(array, k + 1, n); /*把下一个节点元素与后续节点元素交换*/ 
			temp = array[i]; /*恢复原状*/
			array[i] = array[k]; 
			array[k] = temp;	
		}
	}
}

void Print(int array[], int n) {
	int i, j, k, l, m, flag = 1, b[2]; 
	/*对每个array[i] 判断其后比它小的数是否为降序*/
	for(i = 0; i < n; i++) {
		m = 0; 
		for(j = i + 1; j < n && flag; j++) { 
 			if(array[i] > array[j]) {
	 			if(m == 0) 
					b[m++] = array[j];/*记录array[i]后比它小的数*/ 
     			else {
			 		/*如果之后出现的数比记录的数还大，改变标记变量*/
		 			if(array[j] > b[0])
					 	flag = 0;
		 			/*否则记录这个更小的数*/ 
        			else 
						b[0] = array[j]; 
      			} 
      		}
		} 
	}
	/*如果满足出栈规则，输出array*/
	if(flag) {   
		cout<<"第";
		cout.width(2);
		cout<<count++;
		cout<<"种：";
        for(i = 0; i < n; i++) 
			cout<<array[i]<<" ";
        cout<<endl;
    } 
} 
int main() {
	int array[100], n, i; 
	cout<<"请输入元素个数n：";
	cin>>n; 
	for(i = 0; i < n; i++)
		array[i] = i + 1;
	cout<<"调度结果为："<<endl;
	Perm(array, 0, n);
	cout<<endl;
	return 0; 
} 
