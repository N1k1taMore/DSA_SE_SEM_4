#include<iostream>
using namespace std;

class graph{
    int n,e;
    int **adj;
    public:
    graph(){
        n=0;
        e=0;
        adj=NULL;
    }
    graph(int ni,int ei){
        n=ni;
        e=ei;
        adj=new int*[n];
        for(int i=0;i<n;i++){
            adj[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=0;
            }
        }
    }
    void add_edge(int src,int dest,int w){
        adj[src][dest]=w;
        adj[dest][src]=w;
    }
    void display(){
        cout << "  ";
		for (int i = 0; i < n; i++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << i << " ";
			for (int j = 0; j < n; j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
    }
    void prim(int z){
        int no_edges=0;
		int selected[n]={0};
		selected[z]=true;
		int x;  //  row number
		int y;  //  col number

	  // print for edge and weight
		cout << "Edge"
		 << " : "
		 << "Weight";
		cout << endl;
        int sum=0;
		while(no_edges < n-1){
			int min = 9999;
			x = 0;
			y = 0;
			for (int i = 0; i < n; i++) {
			  if (selected[i]) {
				for (int j = 0; j <n; j++) {
				  if (!selected[j] && adj[i][j]) {  // not in selected and there is an edge
					if (min > adj[i][j]) {
					  min = adj[i][j];
					  x = i;
					  y = j;
					}
				  }
				}
			  }
			}
			cout << x << " - " << y << " :  " << adj[x][y];
			cout << endl;
            sum=sum+adj[x][y];
			selected[y] = true;
			no_edges++;
		}
        cout<<"Total cost of minimum spanning tree is :"<<sum<<endl;
    }
    void kruskals(){
		int count = 0,  father[20];
		long int min = 99999;
		for (int i = 0; i < n; i++){
			father[i] = -1;
		}
		int wt = 0;
		int t1, t2, root_temp1, root_temp2,temp1,temp2;
		int res[n][n];
      
		for (int i = 0; i < n; i++){
			for (int j = 0; i < n; i++)
			{
				res[i][j] = 0;
			}
		}
        
		while (count < n- 1)
		{
			min = 9999;
			for (int v1 = 0; v1 < n; v1++)
			{
				for (int v2 = 0; v2 < n; v2++)
				{
					if (adj[v1][v2] != 0 && adj[v1][v2] < min)
					{
						min = adj[v1][v2];
						t1 = v1;
						t2 = v2;
					}
				}
			}
			temp1 = t1;
			temp2 = t2;
			adj[t1][t2] = adj[t2][t1] = 0;
			while (t1 >= 0)
			{
				root_temp1 = t1;
				t1 = father[t1];
			}
			while (t2 >= 0)
			{
				root_temp2 = t2;
				t2 = father[t2];
			}
			if (root_temp1 != root_temp2)
			{
				res[temp1][temp2] = res[temp2][temp1] = min;
				wt = wt + res[temp1][temp2];
				father[root_temp2] = root_temp1;
				count++;
			}
		}
		cout << "Minimum cost by Kruskals Algorithm: " << wt << endl;
	}


};
int main(){
    int N;
	cout << "Enter no. vertices : ";
	cin >> N;
	int M;
	cout << "Enter no. edges : ";
	cin >> M;
	graph G(N, M);
	for (int i = 0; i < M; i++) {
		int src, dest, wt;
		cout << "Enter a source : ";
		cin >> src;
		cout << "Enter a destination : ";
		cin >> dest;
		cout << "Enter a weight : ";
		cin >> wt;
		G.add_edge(src, dest, wt);
	}
	G.display();
    G.prim(2);
   G.prim(0);
   G.prim(1);
    G.kruskals();

    return 0;
}