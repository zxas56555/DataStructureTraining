#include <bits/stdc++.h>

using namespace std;


//创建数组
void CreateArry(int arry[], int len){
    cout << "输入六位数组的元素:" << endl<<endl;
    int key;
    for (int i = 0; i < len; i++){
        cin >> key;
        arry[i] = key;
    }
}

//直接插入排序
void Inert_Sort(int arry[], int len){
    int i, j;
    for (i = 1; i < len; ++i){
        int temp = arry[i];
        for (j = i - 1; j >= 0; --j){
            if (temp < arry[j]){
                arry[j + 1] = arry[j];       
            }
            else { break; }//temp大于有序表中的最后一位则不需要移动
        }
        arry[j+1] = temp;//跳出内层循环后插入在合适的位置
    }
}

//打印数组
void Print(int arry[], int len){
	cout<<endl; 
	cout<<"排序后数组："; 
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
    cout << "是李树臻做的" << endl; 
    system("pause");
    return 0;
}
