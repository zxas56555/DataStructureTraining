int FindRoot(int parent[], int v) {
	int t = v;
	while(parent[t] > -1)
		t = parent[t];
	return t;
}
