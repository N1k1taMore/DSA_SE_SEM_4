#include<iostream>
using namespace std;

class Node{
    string word,meaning;
    Node *left;
    Node *right;
    public:
    Node(){
        word=meaning=" ";
        left=right=NULL;
    }
    Node (string k,string v){
        word=k;
        meaning=v;
        left=right=NULL;
    }
    friend class Bst;
};
class Bst{
    Node *root;
    public:
    Bst(){
        root=NULL;
    }

    Node* getRoot(){
        return root;
    }

    Node *createTree(){
        string k,v;
        cout<<"Enter the Root word :"<<endl;
        cin>>k;
        cout<<"Enter it's Meaning :"<<endl;
        cin>>v;
        Node *nn=new Node(k,v);
        root=nn;
        return root;
    }

    void insertNode(){
        int t;
        cout<<"Enter number of words to be inserted :"<<endl;
        cin>>t;
        for(int i=0;i<t;i++){
            string k,v;
            cout<<"Enter the word :"<<endl;
            cin>>k;
            cout<<"Enter it's Meaning :"<<endl;
            cin>>v;
            Node *nn=new Node(k,v);
            Node *prev=NULL;
            Node *temp=root;
            if(root==NULL){
                cout<<"Tree not created yet"<<endl;
            }
            else{
                while(temp!=NULL){
                    if(k>temp->word){
                        prev=temp;
                        temp=temp->right;
                    }
                    else if(k<temp->word){
                        prev=temp;
                        temp=temp->left;
                    }
                    else{
                       break;
                    }
                }
                if(temp!=NULL){
                    cout<<"Duplicate Entry"<<endl;
                }
                else{
                    if(k < prev->word){
                        prev->left=nn;
                    }
                    else{
                        prev->right=nn;
                    }
                    cout<<"Word inserted"<<endl;
                }
                
            } 
        }
    }

    void deletion(string s){
        Node *curr=root;
        Node *prev=NULL;
        search(s,curr,prev);
        if(curr==NULL){
            cout<<"Word not present"<<endl;
        }
        else{
            if(curr->left==NULL && curr->right==NULL){
                if(prev->left==curr){
                    prev->left=NULL;
                }
                else{
                    prev->right=NULL;
                }
                delete(curr);
                cout<<"Word Deleted"<<endl;
            }
            else if(curr->left==NULL && curr->right!=NULL){
                if(prev->left=curr){
                    prev->left=curr->right;
                }
                else{
                    prev->right=curr->right;
                }
                delete(curr);
                cout<<"Word Deleted"<<endl;
            }
            else if(curr->left!=NULL && curr->right==NULL){
                if(prev->left=curr){
                    prev->left=curr->left;
                }
                else{
                    prev->right=curr->left;
                }
                delete(curr);
                cout<<"Word Deleted"<<endl;
            }
            else{
                Node *succ=findSuccesor(curr->right);
                string succ_word=succ->word;
                string succ_meaning=succ->meaninng;
                deletion(succ_word);
                curr->word=succ_word;
                curr->meaninng=succ_meaning;
            }
        }
    }
    int  search(string s,Node *&curr,Node *&prev){
        int count=0;
        while(curr->word != s && curr !=NULL){
            if(s < curr->word){
                prev=curr;
                curr=curr->left;
                count++;
            }
            else{
                prev=curr;
                curr=curr->right;
                count++;
            }
        }
        if(curr==NULL){
            return -1;
        }
        else{
            return count;
        }
    }

    Node *findSuccesor(Node *temp){
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    void update(){
        string s,v;
        cout<<"Enter the word to be updated :"<<endl;
        cin>>s;
        cout<<"Enter new Meaning :"<<endl;
        cin>>v;
        Node *curr=root;
        Node *prev=NULL;
        search(s,curr,prev);
        if(curr==NULL){
            cout<<"Word Not Found"<<endl;
        }
        else{
            curr->meaninng=v;
            cout<<"Meaning Updated"<<endl;
            cout<<curr->word<<"="<<curr->meaninng<<endl;
        }
    }
    void inorder(Node *temp){
        if(temp !=NULL){
            inorder(temp->left);
            cout<<temp->word<<"="<<temp->meaninng<<endl;
            inorder(temp->right);
        }
    }
    void preorder(Node *temp){
        if(temp !=NULL){
            cout<<temp->word<<"="<<temp->meaninng<<endl;
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void Descending(Node *temp){
        if(temp !=NULL){
            Descending(temp->right);
            cout<<temp->word<<"="<<temp->meaninng<<endl;
            Descending(temp->left);
        }
    }
    void postorder(Node *temp){
        if(temp !=NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->word<<"="<<temp->meaninng<<endl;
        }
    }
    int max(int x,int y){
        if(x>y){
            return x;
        }
        else{
            return y;
        }
    }
    int height(Node *temp){
        if(temp==NULL){
            return 0;
        }
        else{
            int l=height(temp->left);
            int r=height(temp->right);
            return max(l,r)+1;
        }
    }
};
int main(){
    int x;
    Bst b;
    Node *head;
    do{
        cout<<"\n1.CREATE\n2.INSERT\n3.DELETE\n4.UPDATE\n5.ASCENDING ORDER\n6.DESCENDING ORDER\n7.PREORDER\n8.POSTORDER\n9.HEIGHT\n10.EXIT"<<endl;
        cout<<"\nEnter choice"<<endl;
        cin>>x;
        if(x==1){
            head=b.createTree();
        }
        else if(x==2){
            b.insertNode();
        }
        else if(x==3){
            string s;
            cout<<"Enter word to be deleted"<<endl;
            cin>>s;
            b.deletion(s);
        }
        else if(x==4){
            b.update();
        }
        else if(x==5){
            cout<<"ASCENDING ORDER :"<<endl;
            b.inorder(head);
        }
        else if(x==6){
            cout<<"DESCENDING ORDER :"<<endl;
            b.Descending(head);
        }
        else if(x==7){
            cout<<"PREORDER TRAVERSAL :"<<endl;
            b.preorder(head);
        }
        else if(x==8){
            cout<<"POSTORDER TRAVERSAL :"<<endl;
            b.postorder(head);
        }
        else if(x==9){
            cout<<"HEIGHT :"<<endl;
            int x=b.height(head);
        }
        else{
            cout<<"EXIT"<<endl;
        }
    
    }while(x<10);

return 0;   
}