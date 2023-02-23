#include <iostream>
#define MaxSize 20 /*顺序表的最大长度为20*/
using namespace std;

/*调整结点k，其左右子树都已是大根堆，重新调整成大根堆，结点总数为m个*/
void Adjust(int r[], int k, int m) {
	int i, j;
	int temp;
	i = k;
	j = 2 * i;
	while(j <= m) {
		/*j指向i的左右孩子中较大的*/
		if(j < m && r[j + 1] > r[j])
			j++;
		/*如果符合大根堆要求，则跳出*/
		if(r[i] >= r[j])
			break;
		else {
			/*交换r[i]和r[j]*/
			temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			/*继续向下一层判断，直到叶子结束*/
			i = j;
			j = 2 * i;
		}
	}
}

void HeapSort(int r[], int n) {		
	int i, temp;
	/*初始化建大根堆*/
	for(i = n / 2; i >= 1; i--)
		Adjust(r, i, n);
	for(i = 1; i < n; i++) {
		/*r[1]是待排序元素中最大的*/
		/*r[1]和r[n-i+1]互换*/
		temp = r[1];
		r[1] = r[n - i + 1];
		r[n - i + 1] = temp;
		/*调整结点1至n-i使之重新成为大根堆*/
		Adjust(r, 1, n - i);
	}
}

int main() {
	int i, n;
	int r[MaxSize + 1];
	cout<<"请输入顺序表的长度："<<endl;
	cin>>n;
	if(n < 0 || n > 20) {
		throw "参数不合法，请输入[0,20]之间的值！";
	}
	cout<<"请输入待排序的顺序表元素："<<endl;
	for(i = 1; i <= n; i++) {
		cin>>r[i];
	}
	HeapSort(r, n);
	cout<<"堆排序之后的顺序表为："<<endl;
	for(i = 1; i <= n; i++)
		cout<<r[i]<<" ";
	cout<<endl;
	return 0;
}
