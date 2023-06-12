#include<iostream>
using namespace std;
#define n 100


class Node
{
    int data;
    Node *right;
    Node *left;

public:
    Node(){
    right = NULL;
    left = NULL;
        data = 0;
    }

    Node(int x){
    right = NULL;
    left = NULL;
        data = x;
    }

    friend class Tree;
};

class stack{
     int top;
public:
    Node *arr[n];
    stack()
    {
        top = -1;
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if (top == n - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(Node *x)
    {
        if (!isfull())
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "stack is full" << endl;
        }
    }
    Node *pop()
    {
        Node *ele;
        if (top == -1)
        {
            return NULL;
        }
        else
        {
            ele = arr[top];
            top--;
            return ele;
        }
    }
    friend class Tree;
};

class Tree{
    Node *root;
    public:

    Tree(){
        root=NULL;
    }

    Node *getRoot(){
        return root;
    }
    Node *createR()
    {
        int y;
        cout << "ENTER THE DATA :" << endl;
        cin >> y;
        if (y == -1)
        {
            return NULL;
        }
        Node *p = new Node(y);
        cout << "left child of" << p->data << endl;
        p->left = createR();
        cout << "right child of" << p->data << endl;
        p->right = createR();
        return p;
    }

    void inorderNr(Node *temp)
    {
        stack s;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        while (!s.isempty())
        {
            temp = s.pop();
            cout << temp->data <<" ";
            temp = temp->right;
            while (temp != NULL)
            {
                s.push(temp);
                temp = temp->left;
            }
        }
    }

    void inorderR(Node *temp){
        if(temp!=NULL){
            inorderR(temp->left);
            cout<<temp->data<<"-";
            inorderR(temp->right);
        }
    }

    void preorderNr(Node *temp)
    {
        stack s;
        while (temp != NULL)
        {
            cout << temp->data <<" ";
            s.push(temp);
            temp = temp->left;
        }
        while (!s.isempty())
        {
            temp = s.pop();
            temp = temp->right;
            while (temp != NULL)
            {
                cout <<temp->data<<" ";
                s.push(temp);
                temp = temp->left;
            }
        }
    }

    void preorderR(Node *temp){
        if(temp!=NULL){
            cout<<temp->data<<"-";
            inorderR(temp->left);
            inorderR(temp->right);
        }
    }

    void postorderNr(Node *temp){
        stack s1,s2;
        s1.push(temp);
        while(!s1.isempty()){
            temp=s1.pop();
            s2.push(temp);
            if(temp->left!=NULL){
                s1.push(temp->left);
            }
            if(temp->right!=NULL){
                s1.push(temp->right);
            }
        }
        while(!s2.isempty()){
            temp=s2.pop();
            cout<<temp->data<<" ";
        }
    }
    void postorderR(Node *temp){
        if(temp!=NULL){
            inorderR(temp->left);
            inorderR(temp->right);
             cout<<temp->data<<"-";
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
    int leaf_count(Node *temp){
        if(temp==NULL){
            return 0;
        }
        else if(temp->left==NULL && temp->right==NULL){
            cout<<temp->data<<" ";
            return 1;
        }
        return leaf_count(temp->left)+leaf_count(temp->right);
    }
    
    int non_leaf(Node *temp){
        if(temp==NULL || (temp->left==NULL && temp->right==NULL)){
            return 0;
        }
        cout<<temp->data<<" ";
        return 1+non_leaf(temp->left)+non_leaf(temp->right);

    }
    Node *mirror_image(Node *temp){
        if(temp==NULL){
            return NULL;
        }
        else{
            mirror_image(temp->left);
            mirror_image(temp->right);
            Node *temp1=temp->left;
            temp->left=temp->right;
            temp->right=temp1;
        }
    }
    Node *copy_tree(Node *temp){
        if(temp==NULL){
            return NULL;
        }
        else{
            Node *temp1=new Node(temp->data);
            temp1->left=copy_tree(temp->left);
            temp1->right=copy_tree(temp->right);
        }
    }
    void operator=(Tree T){
        root=Copy_tree(T.root);
    }
    void delete_tree(Node *&temp){
        if(temp==NULL){
            return NULL;
        }
        else{
            delete_tree(temp->left);
            delete_tree(temp->right);
            delete(temp);
            temp=NULL;
        }
    }
};
int main(){
    Tree T;
    Node *head;
    int choice;
    do
    {
        cout << "1.CREATE" << endl;
        cout << "2.INODER TRAVERSAL" << endl;
        cout << "3.PREODER TRAVERSAL" << endl;
        cout << "4.POSTODER TRAVERSAL" << endl;
        cout << "5.HEIGHT OF TREE" << endl;
        cout << "6.MIRROR IMAGE OF TREE" << endl;
        cout << "7.NO. OF LEAF NODES" << endl;
        cout << "8.NO. OF NON LEAF NODES" << endl;
        cout << "9.DELETE TREE" << endl;
        cout << "10.COPY TREE" << endl;
        cout << "11.EXIT" << endl;
        cout << "ENTER YOUR CHOICE" << endl;
        cin >> choice;
        if(choice==1){
            head = T.createR();
            cout << "TREE CREATED!" << endl;
        }
        else if(choice==2){
            int x;
            cout<<"1.RECURSIVE"<<endl;
            cout<<"2.NON-RECURSIVE"<<endl;
            cout<<"ENTER YOUR CHOICE :"<<endl;
            cin>>x;
            if(x==1){
                cout << "RECURSIVE INORDER TRAVERSAL" << endl;
                T.inorderR(head);
            }
            else{
                cout << "NON RECURSIVE INORDER TRAVERSAL: " << endl;
                T.inorderNr(head);
            }
        }
        else if(choice==3){
            int x;
            cout<<"1.RECURSIVE"<<endl;
            cout<<"2.NON-RECURSIVE"<<endl;
            cout<<"ENTER YOUR CHOICE :"<<endl;
            cin>>x;
            if(x==1){
                cout << "RECURSIVE PREORDER TRAVERSAL" << endl;
                T.preorderR(head);
            }
            else{
                cout << "NON RECURSIVE PREORDER TRAVERSAL: " << endl;
                T.preorderNr(head);
            }
        }
        else if(choice==4){
            int x;
            cout<<"1.RECURSIVE"<<endl;
            cout<<"2.NON-RECURSIVE"<<endl;
            cout<<"ENTER YOUR CHOICE :"<<endl;
            cin>>x;
            if(x==1){
                cout << "RECURSIVE POSTORDER TRAVERSAL" << endl;
                T.postorderR(head);
            }
            else{
                cout << "NON RECURSIVE POSTORDER TRAVERSAL: " << endl;
                T.postorderNr(head);
            }
        }
        else if(choice==5){
            cout << "HEIGHT OF TREE :" << endl;
            int h = T.height(head);
            cout << h<<endl;
        }
        else if(choice==6){
            cout << "MIRROR IMAGE OF THE TREE IS :";
            T.mirror_image(head);
            T.inorderR(head);
            cout << endl;
        }
        else if(choice==7){
            cout << "NO.OF LEAF NODES : " << endl;
            int l=T.leaf_count(head);
            cout<< l <<endl;
        }
        else if(choice==8){
            cout << "NO. OF NON LEAF NODES : " << endl;
            int nl=T.non_leaf(head);
            cout<< nl <<endl;
        }
        else if(choice==9){
            T.deleteTree(head);
            cout << "TREE DELETED!!" << endl;
        }
        else if(choice==10){
            cout << "DISPLAYING COPY TREE :" << endl;
            Tree TC=T;
            Node *headTc=TC.getRoot();
            TC.inorderR(headTc);
        }
        else{
            cout<<"EXIT"<<endl;
        }
    }
    while(choice<11);

   return 0;
}