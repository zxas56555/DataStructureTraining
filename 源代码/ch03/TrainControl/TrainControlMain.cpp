#include <iostream>
using namespace std;
int count = 1; /*�����ջ�������������*/
void Print(int array[], int n); /*�ж�array�Ƿ������ջ���������������㣬���array*/
void Perm(int array[], int k, int n) {
	int i, temp;
	if(k == n - 1)
		Print(array, n); /*k��n-1��ȣ���һ�˵ݹ�����*/ 
	else {
		for(i = k; i < n; i++) { /*�ѵ�ǰ�ڵ�Ԫ��������ڵ�Ԫ�ؽ���*/ 
			temp = array[k];/*����*/
			array[k] = array[i]; 
			array[i] = temp;
			Perm(array, k + 1, n); /*����һ���ڵ�Ԫ��������ڵ�Ԫ�ؽ���*/ 
			temp = array[i]; /*�ָ�ԭ״*/
			array[i] = array[k]; 
			array[k] = temp;	
		}
	}
}

void Print(int array[], int n) {
	int i, j, k, l, m, flag = 1, b[2]; 
	/*��ÿ��array[i] �ж�������С�����Ƿ�Ϊ����*/
	for(i = 0; i < n; i++) {
		m = 0; 
		for(j = i + 1; j < n && flag; j++) { 
 			if(array[i] > array[j]) {
	 			if(m == 0) 
					b[m++] = array[j];/*��¼array[i]�����С����*/ 
     			else {
			 		/*���֮����ֵ����ȼ�¼�������󣬸ı��Ǳ���*/
		 			if(array[j] > b[0])
					 	flag = 0;
		 			/*�����¼�����С����*/ 
        			else 
						b[0] = array[j]; 
      			} 
      		}
		} 
	}
	/*��������ջ�������array*/
	if(flag) {   
		cout<<"��";
		cout.width(2);
		cout<<count++;
		cout<<"�֣�";
        for(i = 0; i < n; i++) 
			cout<<array[i]<<" ";
        cout<<endl;
    } 
} 
int main() {
	int array[100], n, i; 
	cout<<"������Ԫ�ظ���n��";
	cin>>n; 
	for(i = 0; i < n; i++)
		array[i] = i + 1;
	cout<<"���Ƚ��Ϊ��"<<endl;
	Perm(array, 0, n);
	cout<<endl;
	return 0; 
} 
