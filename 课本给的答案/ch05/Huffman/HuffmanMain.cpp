#include <iostream>
#include <iomanip>
using namespace std;
/*定义元素类型*/
struct element{
	int weight; /*权值*/
	int parent, lchild, rchild; /*双亲，左孩子，右孩子*/
};

/*给定权值数组w[]及数组长度n，求Huffman树*/
void HuffmanTree(element huffTree[], int w[], int n) {
	int i, j, k;
	int m1, m2;
	/*结点初始化*/
	for(i = 0; i < 2 * n - 1; i++) {
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	/*构造初始的n棵二叉树*/
	for(i = 0; i < n; i++) {
		huffTree[i].weight = w[i];
	}
	for(k = n; k < 2 * n - 1; k++) {
		/*取两棵根结点权值最小的哈夫曼树*/
		/*m1确定初值*/
		for(j = 0; j < k; j++) {
			if(huffTree[j].parent == -1) {
				m1 = j;
				break;
			}
		}
		/*m2确定初值*/
		for(j = 0; j < k; j++) {
			if(huffTree[j].parent == -1 && j != m1) {
				m2 = j;
			    break;
			}
		}
		if(huffTree[m2].weight < huffTree[m1].weight) {
			int temp = m1;
			m1 = m2;
			m2 = temp;
		}
		/*确定根结点权值最小的两棵二叉树的下标*/
		for(j = 0; j < k; j++) {
			if(huffTree[j].parent == -1 && j != m1 && j != m2) {
				if(huffTree[j].weight < huffTree[m1].weight) {
					m2 = m1;
				    m1 = j;
				}
			    else if(huffTree[j].weight < huffTree[m2].weight) {
					m1 = j;
				}
			}
		}
		/*将选中的两棵二树合并，并将根结点信息存于下标k处*/
		huffTree[m1].parent = k;
		huffTree[m2].parent = k;
		huffTree[k].lchild = m1;
		huffTree[k].rchild = m2;
		huffTree[k].weight = huffTree[m1].weight + huffTree[m2].weight;
	}
}

void PrintHuffman(element huffTree[],int n) {
	cout<<"哈夫曼树各结点的信息："<<endl;
	int i;
	cout<<setw(8)<<"下标"<<setw(8)<<"weight"<<setw(8)<<"parent"<<setw(8)<<"lchild"<<setw(8)<<"rchild"<<endl;
	for(i = 0; i < 2 * n - 1; i++) {
		cout<<setw(8)<<i;
		cout<<setw(8)<<huffTree[i].weight;
		cout<<setw(8)<<huffTree[i].parent;
		cout<<setw(8)<<huffTree[i].lchild;
		cout<<setw(8)<<huffTree[i].rchild;
		cout<<endl;
	}
}

int main() {
	element huffTree[100];
	int n;
	int i;
	int w[100];
	cout<<"请输入权值的个数(<=10)："<<endl;
	cin>>n;
	if(n>10)
		throw "权值个数值不合法!";
	cout<<"请依次输入各个权值，用空格隔开："<<endl;
	for(i = 0; i < n; i++) {
		cin>>w[i];
	}
    HuffmanTree(huffTree, w, n);
	PrintHuffman(huffTree, n);
	return 0;
}
