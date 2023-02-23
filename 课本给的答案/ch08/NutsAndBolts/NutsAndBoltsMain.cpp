#include<iostream>
using namespace std;

/*����ָ��������Ԫ��*/
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*���*/
void PrintArray(int a[], int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*ƥ��nut��bolt�������飬leftΪ��������rightΪ��������lenΪ����ĳ���*/
void Match(int *nut, int *bolt, int left, int right, int len) {
    if (left < right) {
    	/*���ݶ���ƥ����ĸ*/ 
        int tmp = nut[left];
        int i = left, j = right;
        while (i < j) {
            while (i < j && bolt[i] < tmp)
				i++;
            while (i < j && bolt[j] > tmp)
                j--;
            if (i < j)
                swap(bolt[i], bolt[j]);
        }
        bolt[i] = tmp;
        /*��ƥ����ݶ��������*/
        swap(bolt[left], bolt[i]);
        cout << "���ݶ���ƥ����ĸ��" <<tmp<<endl; 
		PrintArray(nut, len); 
		PrintArray(bolt, len); 
        /*����ĸ��ƥ���ݶ�*/ 
        tmp = bolt[left + 1];
        i = left + 1, j = right;
        while (i < j) {
            while (i < j && nut[i] < tmp)
            	i++;
            while (i < j && nut[j] > tmp)
            	j--;
            if (i < j)
				swap(nut[i], nut[j]);
        }
        nut[i] = tmp;
        /*��ƥ�����ĸ�������*/ 
        swap(nut[left + 1], nut[i]);
        cout << "����ĸ��ƥ���ݶ���" <<tmp<<endl; 
		PrintArray(nut, len); 
		PrintArray(bolt, len); 
		/*�ݹ鴦��*/
        Match(nut, bolt, left + 2, i, len);
        Match(nut, bolt, i + 1, right, len);
    }
    
}

int main() {
	int nut[9] = { 5, 2, 3, 7, 1, 8, 9, 4, 6 };
    int bolt[9] = { 6, 3, 1, 2, 5, 7, 9, 8, 4 };
    int len = 9;
    cout<<"��ʼ״̬��"<<endl;
    PrintArray(nut, len);
    PrintArray(bolt, len);
    Match(nut, bolt, 0, 8,9);
    return 0;
}
