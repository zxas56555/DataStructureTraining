#include <bits/stdc++.h>

using namespace std;


//��������
void CreateArry(int arry[], int len){
    cout << "������λ�����Ԫ��:" << endl<<endl;
    int key;
    for (int i = 0; i < len; i++){
        cin >> key;
        arry[i] = key;
    }
}

//ֱ�Ӳ�������
void Inert_Sort(int arry[], int len){
    int i, j;
    for (i = 1; i < len; ++i){
        int temp = arry[i];
        for (j = i - 1; j >= 0; --j){
            if (temp < arry[j]){
                arry[j + 1] = arry[j];       
            }
            else { break; }//temp����������е����һλ����Ҫ�ƶ�
        }
        arry[j+1] = temp;//�����ڲ�ѭ��������ں��ʵ�λ��
    }
}

//��ӡ����
void Print(int arry[], int len){
	cout<<endl; 
	cout<<"��������飺"; 
    for (int i = 0; i < len; i++){
        cout << arry[i] << " ";
    }
    cout << endl<<endl;
}

void test01(){
    int arry[6];
    int len = sizeof(arry) / sizeof(arry[0]);
    CreateArry(arry, len);
    Inert_Sort(arry, len);
    Print(arry, len);
}

int main(){
    test01();
    cout << "������������" << endl; 
    system("pause");
    return 0;
}
