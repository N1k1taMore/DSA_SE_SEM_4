#include<iostream>
using namespace std;

class node{
    int data;
    node *left;
    node *right;
    bool lbit;
    bool rbit;
    public:
    node(){
        data=0;
        left=NULL;
        right=NULL;
        lbit=0;
        rbit=0;
    }
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
        lbit=0;
        rbit=0;
    }
    friend class TBST;
};
class TBST{
    node *root;
    node *header;
    public:
    TBST(){
        root=NULL;
        header=NULL;
    }
    node *getroot(){
        return root;
    }

    void create(){
        cout<<"Enter value"<<endl;
        int x;
        cin>>x;
        node *nn=new node(x);
        if(root==NULL){
            root=nn;
            header=new node(-999);
            header->right=header;
            header->left=root;
            root->left=header;
            root->right=header;
            header->lbit=1;
        }
        else{
            node *temp=root;
            while(true){
                if(temp->data > x){
                    if(temp->lbit==1){
                        temp=temp->left;
                    }
                    else{
                        nn->left=temp->left;
                        nn->right=temp;
                        temp->left=nn;
                        temp->lbit=1;
                        break;
                    }
                }
                else{
                    if(temp->rbit==1){
                        temp=temp->right;
                    }
                    else{
                        nn->right=temp->right;
                        nn->left=temp;
                        temp->right=nn;
                        temp->rbit=1;
                        break;
                    }
                }
            }
        }
        cout<<"Data entered"<<endl;
    }
    void inorder(node *root){
        cout<<"INORDER TRAVERSAL ;"<<endl;
        node *temp=root;
        while(temp->lbit==1){
            temp=temp->left;
        }
        while(temp!=header){
            cout<<temp->data<<" ";
            if(temp->rbit==1){
                temp=temp->right;
                while(temp->lbit==1){
                    temp=temp->left;
                }
            }
            else{
                temp=temp->right;
            }
        }
        cout<<endl;
    }
    void preorder(node *root){
        if(root==NULL){
            cout<<"TREE EMPTY"<<endl;
        }
        node *temp=root;
        cout<<"PREORDER TRAVERSAL :"<<endl;
        while(temp!=header){
            while(temp->lbit==1){
                cout<<temp->data<<" ";
                temp=temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rbit==0){
                temp=temp->right;
                if(temp==header){
                    return ;
                }
            }
            temp=temp->right;
        }
        cout<<endl;
    }
    void search(int x,node *&curr,node *&par){
        while(curr!=header){
            if(curr->data==x){
                cout<<"Found"<<endl;
                break;
            }
            else if(curr->data >x){
                par=curr;
                curr=curr->left;
            }
            else{
                par=curr;
                curr=curr->right;
            }
        }
    }
    void Deletion(int key){
        node *par=NULL;
        node *temp=root;
        search(key,temp,par);
        if(temp->lbit==1 && temp->rbit==1){
            node *cur_right=temp->right;
            node *succ=temp;
            while(cur_right->lbit==1){
                succ=cur_right;
                cur_right=cur_right->left;
            }
            temp->data=cur_right->data;
            par=succ;
            temp=cur_right;
        }
        if(temp->lbit==0 && temp->rbit==0){
            if(par->left==temp){
                par->left=temp->left;
                par->lbit=0;
                delete(temp);
            }
            else{
                par->right=temp->right;
                par->rbit=0;
                delete(temp);
            }
            cout<<"DELETED"<<endl;
        }
        if(temp->lbit==1 && temp->rbit==0){
            node *temp1=temp->left;
            if(par->left=temp){
                temp1->right=temp->right;
                par->left=temp1;
                delete(temp);
            }
            else{
                temp1->right=temp->right;
                par->right=temp1;
                delete(temp);
            }
            cout<<"DELETED"<<endl;
        }
        if(temp->lbit==0 && temp->rbit==1){
            node *temp1=temp->right;
            if(par->left==temp){
                temp1->left=temp->left;
                par->left=temp1;
                delete(temp);
            }
            else{
                temp1->left=temp->left;
                par->right=temp1;
                delete(temp);
            }
            cout<<"DELETED"<<endl;
        }
    }
};
int main(){
    TBST obj;
     int choice;
    int data;
    int flag;
    flag = 1;

    while(flag){
        cout<<"----------------MENU---------------";
        cout<<"\n1.Insert in tree."<<endl;
        cout<<"2.Inorder Traversal"<<endl;
        cout<<"3.Preorder Traversal"<<endl;
        cout<<"4.Delete."<<endl;
        cout<<"------------------------------------"<<endl;

        cout<<"\nEnter your choice: "<<endl;
        cin>>choice;

        if(choice == 1)
        {
            //Insertion of data in TBST
            cout<<"Enter data:"<<endl;
            cin>>data;
            obj.create();
        }

        else if(choice == 2)
        {
            //Inorder traversal of TBST
            obj.inorder(obj.getroot());
        }
        else if(choice == 3)
        {
            //Preorder Traversal of TBST
            obj.preorder(obj.getroot());
        }
        else if(choice == 4)
        {
            //Deletion of a data from TBST
            int key;
            cout<<"Enter the number which you want to delete:"<<endl;
            cin>>key;
            obj.Deletion(key);
            obj.inorder(obj.getroot());
        }
        cout<<"Do you want to continue(1 for yes and 0 for no)"<<endl;
        cin>>flag;
    }
    return 0;

}