#include <iostream>
using namespace std;
void PrintArray(int n, char a[]) {
	for(int i = 0; i < n; i++)
  		cout<<a[i];
	cout<<endl;
}

void HollandFlags(int n, char a[]) {
	int b, r, p;
	r = 0;
	p = 0;
	b = n - 1;
	while(p <= b) {
		if(a[p] == 'R') {
			a[p] = a[r];
			a[r] = 'R';
			r++;
			p++;
		}
		else {
			if(a[p] == 'B') {
				a[p] = a[b];
				a[b] = 'B';
				b--;
			}
			else
				p++;
		}
	}
}

int main() {
	char a[20] = {'R', 'B', 'B', 'W', 'W', 'B', 'R', 'W', 'B', 'R', 'W', 'B', 'B', 'R', 'W'};
	int n = 15;
	cout<<"排序之前："<<endl;
	PrintArray(n, a);
	HollandFlags(n, a);
	cout<<"排序之后："<<endl;
	PrintArray(n, a);
	return 0;	
}

