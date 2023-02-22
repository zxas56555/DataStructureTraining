#include <iostream>
#include <iomanip>
using namespace std;
/*����Ԫ������*/
struct element{
	int weight; /*Ȩֵ*/
	int parent, lchild, rchild; /*˫�ף����ӣ��Һ���*/
};

/*����Ȩֵ����w[]�����鳤��n����Huffman��*/
void HuffmanTree(element huffTree[], int w[], int n) {
	int i, j, k;
	int m1, m2;
	/*����ʼ��*/
	for(i = 0; i < 2 * n - 1; i++) {
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	/*�����ʼ��n�ö�����*/
	for(i = 0; i < n; i++) {
		huffTree[i].weight = w[i];
	}
	for(k = n; k < 2 * n - 1; k++) {
		/*ȡ���ø����Ȩֵ��С�Ĺ�������*/
		/*m1ȷ����ֵ*/
		for(j = 0; j < k; j++) {
			if(huffTree[j].parent == -1) {
				m1 = j;
				break;
			}
		}
		/*m2ȷ����ֵ*/
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
		/*ȷ�������Ȩֵ��С�����ö��������±�*/
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
		/*��ѡ�е����ö����ϲ��������������Ϣ�����±�k��*/
		huffTree[m1].parent = k;
		huffTree[m2].parent = k;
		huffTree[k].lchild = m1;
		huffTree[k].rchild = m2;
		huffTree[k].weight = huffTree[m1].weight + huffTree[m2].weight;
	}
}

void PrintHuffman(element huffTree[],int n) {
	cout<<"����������������Ϣ��"<<endl;
	int i;
	cout<<setw(8)<<"�±�"<<setw(8)<<"weight"<<setw(8)<<"parent"<<setw(8)<<"lchild"<<setw(8)<<"rchild"<<endl;
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
	cout<<"������Ȩֵ�ĸ���(<=10)��"<<endl;
	cin>>n;
	if(n>10)
		throw "Ȩֵ����ֵ���Ϸ�!";
	cout<<"�������������Ȩֵ���ÿո������"<<endl;
	for(i = 0; i < n; i++) {
		cin>>w[i];
	}
    HuffmanTree(huffTree, w, n);
	PrintHuffman(huffTree, n);
	return 0;
}
