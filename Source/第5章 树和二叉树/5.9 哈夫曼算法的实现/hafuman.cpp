#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class huffumanNode
{
public:
    int weight;
    huffumanNode *left;
    huffumanNode *right;
    //��������Ҷ�ӽڵ�
    huffumanNode(int setWeight)
    {

        this->weight = setWeight;
        this->left = NULL;
        this->right = NULL;
    }
    //���������м�Ľڵ�
    huffumanNode(int setWeight, huffumanNode *setLeft, huffumanNode *setRight)
    {
        this->weight = setWeight;
        this->left = setLeft;
        this->right = setRight;
    }
    //�ж��Ƿ���Ҷ�ӽڵ�
    bool isLeaf()
    {
        return this->left == NULL && this->right == NULL;
    }

};

//��������ȽϺ�������wieght�Ĵ�С��������
bool myHuffumanComepare(huffumanNode *node1, huffumanNode *node2)
{
    return node1->weight > node2->weight;
}

/*�õ���Ȩ·�����ȡ���ν���Ĵ�Ȩ·�����ȣ������������е�Ҷ���

��Ȩֵ�����䵽������ ·�����ȣ��������Ϊ0�㣬Ҷ��㵽������·������

ΪҶ���Ĳ�����*/
void getHuffmanSum(huffumanNode *root,int length,int &sum)
{
    if (!root)
    {
        return;
    }
    if (root->isLeaf())
    {
        sum += root->weight*length;
    }
    length++;
    getHuffmanSum(root->left, length, sum);
    getHuffmanSum(root->right, length, sum);
}
//ǰ�������ӡ���ύʱ��Ҫ�������������Ϊ����
void prePrint(huffumanNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->weight << " ";
    prePrint(root->left);
    prePrint(root->right);
}

int main()
{ 
cout<<"������Ҷ�ӽڵ�ĸ�����"<<endl;
    int n;
    
    while (cin >> n)
    {
        vector<huffumanNode*> weightArray; 
		cout<<"����������Ҷ�ӽڵ��Ӧ��Ȩֵ��"<<endl; 
        while (n--)
        {
            int tempWeight;
           
            cin >> tempWeight;
            huffumanNode *newNode = new huffumanNode(tempWeight);
            weightArray.push_back(newNode);
        }
        sort(weightArray.begin(), weightArray.end(), myHuffumanComepare);
        while ((int)weightArray.size() > 1)
        {
            huffumanNode *minNode1 = weightArray[weightArray.size() - 1];
            huffumanNode *minNode2 = weightArray[weightArray.size() - 2];
            int fatherWeight = minNode1->weight + minNode2->weight;
            /*������С������Ȩ�ؽڵ㣬�����½ڵ�*/
            huffumanNode *fatherNode = new huffumanNode(fatherWeight, minNode1, minNode2);

            weightArray.pop_back();
            weightArray.pop_back();
            weightArray.push_back(fatherNode);

            sort(weightArray.begin(), weightArray.end(), myHuffumanComepare);
        }
		cout<<"��������˹���������Ȩֵ��"<<endl; 
        prePrint(weightArray[0]);
        cout << endl;
        int length = 0;
        int sum = 0;
        getHuffmanSum(weightArray[0], length, sum);
        cout << "��������Ҷ���Ĵ�Ȩ·������֮��(WPL): " << sum << endl;
        cout << "������������" << endl;
    }
    return 0;
}


