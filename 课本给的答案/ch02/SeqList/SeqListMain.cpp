#include <iostream>
using namespace std; /*ʹ��std�����ռ䣬����������ͻ*/
#include "SeqList.cpp"
int main() {
    int r[10] = {4, 2, 6, 8, 12, 10, 14, 16, 19, 18};
    SeqList<int> L(r, 10);
    cout<<"ִ�в������ǰ����Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    try{
		L.Insert(6, 11);
	}
    catch(char *str) {
        cout<<str<<endl;
    }
    cout<<"ִ�в������������Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    cout<<"ֵΪ16��Ԫ��λ��Ϊ:";
    cout<<L.Locate(16)<<endl; /*����Ԫ��16����������˳����е�λ��*/
    cout<<"ִ��ɾ����7��Ԫ�ز�����ɾ��ǰ����Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    try{
		L.Delete(7); /*ɾ����7��Ԫ��*/
	}
    catch(char *str) {
		cout<<str<<endl;
	}
    cout<<"ɾ��������Ϊ��"<<endl;
    L.PrintList(); /*�������Ԫ��*/
    return 0;
}
