#include <iostream>
using namespace std;
#define MaxSize 100
/*��ʼ������*/
void InitMatrix(int a[][MaxSize], int m, int n) {
    for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>a[i][j];
        }
	}
}
/*���������㲢���*/
void GetSaddlePoint(int a[][MaxSize], int m, int n) {
	/*flag���ڱ�ʶ�����Ƿ��������*/
	/*min���ڼ�¼ÿһ�е���СԪ�أ�ÿһ�п����ж����СԪ��*/
	int i, j, k, min, flag; 
	for(i = 0; i < m; i++) {
		min = a[i][0];
        /*�ҳ�i���е���Сֵ*/
        for(j = 0; j < n; j++)
			if(a[i][j] < min) {
				min = a[i][j];
            }
        /*�ж�min�ǲ��������е����ֵ*/
        for(j = 0; j < n; j++) {   
			if(a[i][j] == min) { /*�ҳ�i����������Сֵ*/
				for(k = 0; k < m; k++) /*������min�����бȽ�*/
					if(a[k][j] > min)  
						break;
                    if(k == m) { /*minΪ����*/
                        cout<<"�þ���������ǣ���"<<i<<"�У���"<<j<<"�У�"<<a[i][j]<<endl;
                        flag = 1;
					}
			}
		}
	}
	if(flag == 0)
		cout<<"�þ���û������!"<<endl;
}
int main() {
    int a[MaxSize][MaxSize];
    int m, n;
    cout<<"����������������"; /*������������*/
    cin>>m;          
    cout<<"����������������"; /*������������*/
    cin>>n;
    cout<<"���������"<<endl; 
    InitMatrix(a, m, n);
    GetSaddlePoint(a, m, n); 
	return 0;
}
