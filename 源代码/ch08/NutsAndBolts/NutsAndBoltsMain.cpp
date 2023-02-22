#include<iostream>
using namespace std;

/*交换指定的两个元素*/
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*输出*/
void PrintArray(int a[], int len) {
    for(int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*匹配nut和bolt两个数组，left为左索引，right为右索引，len为数组的长度*/
void Match(int *nut, int *bolt, int left, int right, int len) {
    if (left < right) {
    	/*在螺钉中匹配螺母*/ 
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
        /*把匹配的螺钉放在左端*/
        swap(bolt[left], bolt[i]);
        cout << "在螺钉中匹配螺母：" <<tmp<<endl; 
		PrintArray(nut, len); 
		PrintArray(bolt, len); 
        /*在螺母中匹配螺钉*/ 
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
        /*把匹配的螺母放在左端*/ 
        swap(nut[left + 1], nut[i]);
        cout << "在螺母中匹配螺钉：" <<tmp<<endl; 
		PrintArray(nut, len); 
		PrintArray(bolt, len); 
		/*递归处理*/
        Match(nut, bolt, left + 2, i, len);
        Match(nut, bolt, i + 1, right, len);
    }
    
}

int main() {
	int nut[9] = { 5, 2, 3, 7, 1, 8, 9, 4, 6 };
    int bolt[9] = { 6, 3, 1, 2, 5, 7, 9, 8, 4 };
    int len = 9;
    cout<<"初始状态："<<endl;
    PrintArray(nut, len);
    PrintArray(bolt, len);
    Match(nut, bolt, 0, 8,9);
    return 0;
}
