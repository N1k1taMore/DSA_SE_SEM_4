#include<iostream>
using namespace std;
#define MAX 20

class Node{
    string vertice;
    Node* next;
public:
    Node(){
		vertice="";
		next=NULL;
    }
    Node(string v){
		vertice=v;
		next=NULL;
    }
	friend class Graph;
};
template<class T>
class Queue{
    T q[MAX];
    public:
    int front;
    int rear;

    Queue(){
    front=-1;
    rear=-1;
    }
    void enqueue(T node){
		 if(rear==MAX-1){
        cout<<"Overflow"<<endl;
		}
		else if(front==-1 && rear==-1){
			front=0;
			rear=0;
		//q[rear]=new Node(x);
			q[rear]=node;
		}
		else{

			rear+=1;
			q[rear]=node;
    	}
	}
    void dequeue(){
		if(front==-1 && rear==-1){
        	cout<<"Underflow"<<endl;
		}
		else if(front==rear){
			front=-1;
			rear=-1;
		//cout<<"Top most element is:"<<q[front]->data<<endl;

		}
		else{
			front+=1;
		//cout<<"Top most element is:"<<q[front]->data<<endl;
		}
	}
    bool is_Empty(){
		if(front==-1 && rear==-1){
        	return true;
		}
		else{
			return false;
		}
	}
    bool is_Full(){
		if(rear==MAX-1){
        	return true;
		}
		else{
			return false;
		}
	}
    T peek(){
		return q[front];
	}
};
template<class T>
class Stack{
T s[MAX];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(T x){
		if(top==MAX-1){
            cout<<"Overflow"<<endl;
        }
        else{

            top+=1;
            s[top]=x;
        }
	}
    void pop(){
		if(top==-1){
            cout<<"Underflow"<<endl;
        }
        else{
            //cout<<"Top most element is:"<<s[top]->data<<endl;;
            top-=1;
        }
	}
    bool is_Empty(){
		if(top==-1){
        	return true;
		}
		else{
			return false;
		}
	}
    bool is_Full(){
		if(top==MAX-1){
			return true;
		}
		else{
			return false;
		}	
	}
    T peek(){
		return s[top];
	}
};

class Graph{
    int nv,nedges;
    Node** adjlist;
    string* vname;
    public:

    Graph(){
        cout<<"Enter number of vertices:";
        cin>>nv;
        cout<<"Enter number of edges:";
        cin>>nedges;
        adjlist=new Node*[nv];
        vname=new string[nv];
        cout<<"Enter Names of vertices:"<<endl;
        for(int i=0;i<nv;i++){
			string x;
			cin>>x;
			vname[i]=x;
			adjlist[i]=NULL;
        }

    }
    int findind(string s){
        int ind=0;
        for(int i=0;i<nv;i++){
            if(vname[i]==s){
                ind=i;
                break;
            }
        }
        return ind;
    }

    void insert(string s,string d){
		int s1;
		s1=findind(s);
		//cout<<s1<<endl;
        Node* temp=adjlist[s1];
        if(temp==NULL){
            adjlist[s1]=new Node(d);
        }
        else{
            while(temp->next!=0){
                temp=temp->next;
            }
            Node* newnode=new Node(d);
            temp->next=newnode;
        }
    }
    void initialize(){
        for(int i=0;i<nedges;i++){
            string s;
            string d; 
            cout<<"Enter Source:";
            cin>>s;
            cout<<"Enter Destination:";
            cin>>d;
            insert(s,d);
            insert(d,s);
        }
    }
    void bfs(string start){
        int visited[nv];
        //cout<<"hi"<<endl;
        for (int i = 0; i < nv; i++)
        {
            visited[i]=0;
        }
        int x;
        x=findind(start);
        //cout<<x<<endl;
        visited[x]=1;
        Queue<string> q;
        q.enqueue(start);
        cout<<"BFS Traversal of Graph is:";
        while(!q.is_Empty()){
            string temp=q.peek();
            q.dequeue();
            cout<<temp<<" ";
            int x1=findind(temp);
            Node* temp1=adjlist[x1];
            while(temp1!=0){
                string x2=temp1->vertice;

                if(visited[findind(x2)]==0){

                    visited[findind(x2)]=1;
                    q.enqueue(x2);
                }
                temp1=temp1->next;
            }

        }
        cout<<endl;
    }
    void recu(string start,int vis[]){
        vis[findind(start)]=1;
        cout<<start<<" ";
        Node* temp1=adjlist[findind(start)];
        while(temp1!=0){
            string x=temp1->vertice;
            if(vis[findind(x)]==0){
                recu(x,vis);
            }
            temp1=temp1->next;
        }
    }
    void dfs(string start){
        int visited[nv];

        for (int i = 0; i <nv ; i++)
        {
            visited[i]=0;
        }
        cout<<"DFS Traversal of Graph is:";
        recu(start,visited);
        cout<<endl;
    }
    void dfs_iterative(string start){
        Stack<string> s;
        int visited[nv];
        cout<<"DFS Traversal of Graph is:";
        for (int i = 0; i < nv; i++)
        {
            visited[i]=0;
        }
        visited[findind(start)]=1;
        cout<<start<<" ";
        s.push(start);
        while(!s.is_Empty()){
            string x=s.peek();
            Node* temp=adjlist[findind(x)];
            int flag=0;
            while(temp!=NULL){

                if(visited[findind(temp->vertice)]==0){
                    visited[findind(temp->vertice)]=1;
                    cout<<temp->vertice<<" ";
                    s.push(temp->vertice);
                    flag=1;
                    break;
                }

                temp=temp->next;
            }
            if(flag==0){
                s.pop();
            }
        }
        cout<<endl;
    }
    void display(){
    cout<<"Adjacency List is as follow:"<<endl;;
        for(int i=0;i<nv;i++){
            Node* temp=adjlist[i];
            cout<<(vname[i])<<"=>";
            while(temp!=0){
                cout<<temp->vertice<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.initialize();
    g.display();
    cout<<"Enter the vertice from which the traversal is required: "<<endl;
    string s;
    cin>>s;
    g.bfs(s);
    g.dfs_iterative(s);
    return 0;
}