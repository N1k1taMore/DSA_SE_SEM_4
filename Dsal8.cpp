# include <iostream>
# include <climits>
using namespace std;

class node {
	string data;
	node *left;
	node *right;

public:
	node(){
		left = right = NULL;
	}

	node(string data){
		this->data = data;
		left = right = NULL;
	}

	 friend class obst;
};

class obst{
    node *root;
    public:
    obst(){
        root=NULL;
    }

    node *getroot(){
        return root;
    }

    void calculate_Wt(double *p,double *q,int n, string *input){
        double **w;
        double **c;
        double **r;

        w=new double*[n+1];
		c=new double*[n+1];
		r=new double*[n+1];
        for(int i=0;i<=n;i++){
			w[i]=new double[n+1];
			c[i]=new double[n+1];
			r[i]=new double[n+1];
		}
        for(int i=0;i<n;i++){
            w[i][i]=q[i];
            r[i][i]=0;
            c[i][i]=0;
            w[i][i+1]=q[i]+q[i+1]+p[i+1];
            r[i][i+1]=i+1;
            c[i][i+1]=w[i][i+1];
        }
        w[n][n]=q[n];
        r[n][n]=0;
        c[n][n]=0;

        for(int m=2;m<=n;m++){
            int k;
            for(int i=0;i<=n-m;i++){
                double min=9999;
                int j=i+m;
                w[i][j] = w[i][j-1] + p[j] + q[j];
                for(int i1=i+1;i1<=j;i1++){
                    double sum=c[i][i1-1]+c[i1][j];
                    if(sum<min){
                        min=sum;
                        k=i1;
                    }
                }
                c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
                r[i][j]=k;
            }
        }
	int x=0;
	int y=0;
	cout<<"Weight cost r: "<<endl;
		while(x!=5 && y!=5)
		{
			cout << w[x][y] << "\t";
			cout << c[x][y] << "\t";
			cout << r[x][y] << "|\t";
			x++;
			y++;
		}
		cout<<endl;
		x=0;
		y=1;
		while(x!=4 && y!=5)
		{
			cout << w[x][y] << "\t";
			cout << c[x][y] << "\t";
			cout << r[x][y] << "|\t";
			x++;
			y++;
		}
		cout<<endl;
		x=0;
		y=2;
		while(x!=3 && y!=5)
		{
			cout << w[x][y] << "\t";
			cout << c[x][y] << "\t";
			cout << r[x][y] << "|\t";
			x++;
			y++;
		}
		cout<<endl;
		x=0;
		y=3;
		while(x!=2 && y!=5)
		{
			cout << w[x][y] << "\t";
			cout << c[x][y] << "\t";
			cout << r[x][y] << "|\t";
			x++;
			y++;
		}
		cout<<endl;
		x=0;
		y=4;
		while(x!=1 && y!=5)
		{
			cout << w[x][y] << "\t";
			cout << c[x][y] << "\t";
			cout << r[x][y] << "|\t\n";
			x++;
			y++;

		}
		cout<<endl;
		cout<<"Minimum cost is: "<<c[0][n]<<endl;
        
        root=create(0,n,r,input);
    }
    node *create(int x,int y,double **z,string *input){
        if(x!=y){
            int k=z[x][y];
            node *temp = new node(input[k]);

            temp->left = this->create(x, k-1, z, input);
            temp->right =this->create(k, y, z, input);

            return temp;
        }
        else{
            return NULL;
        }
    }
    void inorder(node *temp){
		if(temp!=NULL){
			inorder(temp->left);
			cout<<temp->data<<":";
			inorder(temp->right);
		}
	}

};
int main(){
    string input[] = {" ", "A1", "A2", "A3","A4"};
	double p[] = {0,3,3,1,1};
	double q[] = {2,3,1,1,1};
	obst tree;
	tree.calculate_Wt(p, q, 4, input);
	cout<<"Minimum spanning tree is: ";
	tree.inorder(tree.getroot());
	return 0;
}

