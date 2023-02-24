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
    //用来构造叶子节点
    huffumanNode(int setWeight)
    {

        this->weight = setWeight;
        this->left = NULL;
        this->right = NULL;
    }
    //用来构造中间的节点
    huffumanNode(int setWeight, huffumanNode *setLeft, huffumanNode *setRight)
    {
        this->weight = setWeight;
        this->left = setLeft;
        this->right = setRight;
    }
    //判断是否是叶子节点
    bool isLeaf()
    {
        return this->left == NULL && this->right == NULL;
    }

};

//降序排序比较函数，以wieght的大小降序排列
bool myHuffumanComepare(huffumanNode *node1, huffumanNode *node2)
{
    return node1->weight > node2->weight;
}

/*得到带权路径长度。所谓树的带权路径长度，就是树中所有的叶结点

的权值乘上其到根结点的 路径长度（若根结点为0层，叶结点到根结点的路径长度

为叶结点的层数）*/
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
//前序遍历打印，提交时不要调用这个哈，仅为调试
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
cout<<"请输入叶子节点的个数："<<endl;
    int n;
    
    while (cin >> n)
    {
        vector<huffumanNode*> weightArray; 
		cout<<"请输入所有叶子节点对应的权值："<<endl; 
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
            /*根据最小的两个权重节点，构造新节点*/
            huffumanNode *fatherNode = new huffumanNode(fatherWeight, minNode1, minNode2);

            weightArray.pop_back();
            weightArray.pop_back();
            weightArray.push_back(fatherNode);

            sort(weightArray.begin(), weightArray.end(), myHuffumanComepare);
        }
		cout<<"先序遍历此哈夫曼树的权值："<<endl; 
        prePrint(weightArray[0]);
        cout << endl;
        int length = 0;
        int sum = 0;
        getHuffmanSum(weightArray[0], length, sum);
        cout << "树的所有叶结点的带权路径长度之和(WPL): " << sum << endl;
        cout << "是李树臻做的" << endl;
    }
    return 0;
}


