#include <iostream>
using namespace std; /*ʹ��std�����ռ䣬����������ͻ*/
#include "SeqList.cpp"

int main() {
    int r[10] = {3,6,9,15,17,13,12,15,11,20};
    SeqList<int> L(r, 10);
    cout<<"ִ�в������ǰ����Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    try{
		L.Insert(6, 16);
	}
    catch(char *str) {
        cout<<str<<endl;
    }
    cout<<"ִ�в������������Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    cout<<"ֵΪ16��Ԫ��λ��Ϊ:";
    cout<<L.Locate(11)<<endl; /*����Ԫ��11����������˳����е�λ��*/
    cout<<"ִ��ɾ����7��Ԫ�ز�����ɾ��ǰ����Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    try{
		L.Delete(9); /*ɾ����9��Ԫ��*/
	}
    catch(char *str) {
		cout<<str<<endl;
	}
    cout<<"ɾ��������Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    cout<<"\n�˲��������������"<<endl;
    return 0;
}
