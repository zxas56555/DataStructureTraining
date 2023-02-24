#include<iostream>
#define MAX 10005
using namespace std;

class Triple
{
public:
	int x, y;
	int value;
};

class tripleTable
{
private:
	Triple data[MAX];
	int maxx, maxy, num;
public:
	void inputTripleTable();
	void printTripleTable();
	tripleTable transposeTripleTable();
	tripleTable fastTransposeTripleTable();
};

void tripleTable::inputTripleTable()
{
	cin >> maxx >> maxy >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> this->data[i].x >> this->data[i].y >> this->data[i].value;
	}
}

void tripleTable::printTripleTable()
{
	cout << "The triplet table you entered is " << endl;
	for (int i = 1; i <= this->num; i++)
	{
		cout << this->data[i].x << " " << this->data[i].y << " " << this->data[i].value << endl;
	}
}

tripleTable tripleTable::transposeTripleTable()
{
	tripleTable after;
	after.maxx = this->maxy;
	after.maxy = this->maxx;
	after.num = this->num;
	if(after.num)
	{
		int q = 1;
		for (int i = 1; i <= this->maxy; i++)
			for (int j = 1; j <= this->maxx; j++)
				if (this->data[j].y == i)
				{
					after.data[q].x = this->data[j].y;
					after.data[q].y = this->data[j].x;
					after.data[q].value = this->data[i].value;
					q++;
				}
	}
	return after;
}

tripleTable tripleTable::fastTransposeTripleTable()
{
	tripleTable after;
	after.maxx = this->maxy;
	after.maxy = this->maxx;
	after.num = this->num;
	int cnum[MAX];
	int cpot[MAX];
	if (after.num)
	{
		for (int i = 1; i <= this->maxy; i++)
			cnum[i] = 0;
		for (int i = 1; i <= this->num; i++)
			cnum[this->data[i].y]++;
		cpot[1] = 1;
		for (int i = 2; i <= this->maxx; i++)
			cpot[i] = cpot[i - 1] + cnum[i - 1];
		for (int i = 1; i <= this->num; i++)
		{
			int col = this->data[i].y;
			int q = cpot[col];
			after.data[q].x = this->data[i].y;
			after.data[q].y = this->data[i].x;
			after.data[q].value = this->data[i].value;
			cpot[col]++;
		}
	}
	return after;
}

int main()
{
	tripleTable a;
	a.inputTripleTable();
	a.printTripleTable();
	tripleTable transposedTripleTable;
//	transposedTripleTable = a.fastTransposeTripleTable();
	transposedTripleTable = a.transposeTripleTable();
	transposedTripleTable.printTripleTable();
	cout << "By 李冠润" << endl;
}