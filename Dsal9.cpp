#include<iostream>
using namespace std;

class Node{
    string key;
    string value;
    int height;
    Node *left;
    Node *right;
    public:
    Node(){
        key=" ";
        value=" ";
        height=1;
        left=NULL;
        right=NULL;
    }
    Node(string k,string v){
        key=k;
        value=v;
        height=1;
        left=NULL;
        right=NULL;
    }
    friend class Avl;
};
class Avl{
    public:

    int getHeight(Node *n){
        if(n==NULL){
            return 0;
        }
        return n->height;
    }

    int balanceFactor(Node *n){
        if(n==NULL){
            return 0;
        }
        return getHeight(n->left)-getHeight(n->right);
    }

    void updateHeight(Node *n){
        n->height=1+max(getHeight(n->left),getHeight(n->right));
    }

    Node *rotateLeft(Node *a){
        cout<<"----RR ROTATION----"<<endl;
        Node *b=a->right;
        a->right=b->left;
        b->left=a;
        updateHeight(a);
        updateHeight(b);
        return b;
    }
    Node *rotateRight(Node *a){
        cout<<"---LL ROTATION---"<<endl;
        Node *b=a->left;
        a->left=b->right;
        b->right=a;
        updateHeight(a);
        updateHeight(b);
        return b;
    }
    Node *rotateRightLeft(Node *a){
        cout<<"---RL ROTATION---"<<endl;
        a->right=rotateRight(a->right);
        return rotateLeft(a);
    }
    Node *rotateLeftRight(Node *a){
        cout<<"---LR ROTATION---"<<endl;
        a->left=rotateLeft(a->left);
        return rotateRight(a);
    }
    Node *balance(Node *a){
        if(balanceFactor(a)==2){
            if(balanceFactor(a->left)<0){
                a=rotateLeftRight(a);
            }
            else{
                a=rotateRight(a);
            }
        }
        else if(balanceFactor(a)==-2){
            if(balanceFactor(a->right)>0){
                a=rotateRightLeft(a);
            }
            else{
                a=rotateLeft(a);
            }
        }
        updateHeight(a);
        return a;
    }

    Node *insert(Node *n,string k,string v){
        if(n==NULL){
            return n=new Node(k,v);
        }
        else if(k<n->key){
            n->left=insert(n->left,k,v);
        }
        else if(k>n->key){
            n->right=insert(n->right,k,v);
        }
        else{
            n->value=v;  //key already exists,update value
            return n;
        }
        return balance(n);
    }

    bool search(Node *n,string k){
        if (n==NULL){
            return false;
        }
        if (k < n->key){
            return search(n->left, k);
        }
        else if (k> n->key){
            return search(n->right, k);
        }
        else{
            return true;
        }
    }
    void Ascending(Node *n){
        if(n!=NULL){
            Ascending(n->left);
            cout << n->key << ": " << n->value << " " << endl;
            Ascending(n->right);
        }
    }
    void Descending(Node *n){
        if(n!=NULL){
            Descending(n->right);
            cout << n->key << ": " << n->value << " " << endl;
            Descending(n->left);
        }
    }
    Node *getSuccessor(Node *n){
        Node *current=n;
        while(current->left!=NULL){
            current=current->left;
        }
        return current;
    }
    Node *Deletion(Node *root,string k){
        if(root==NULL){
            return NULL;
        }
        else if(k<root->key){
            root->left=Deletion(root->left,k);
        }
        else if(k >root->key){
            root->right=Deletion(root->right,k);
        }
        else{
            if(root->left==NULL && root->right==NULL){
                delete root;
                root=NULL;
            }
            else if(root->left==NULL){
                Node *temp=root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                Node *successor=getSuccessor(root->right);
                root->key = successor->key;
                root->value = successor->value;
                root->right = Deletion(root->right, successor->key);
            }
        }
        if(root==NULL){
            return NULL;
        }
        updateHeight(root);
        int bal=balanceFactor(root);
        if(bal>1){
            if (balanceFactor(root->left) >= 0){
                return rotateRight(root);
            }
            else{
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        if (bal < -1){
            if (balanceFactor(root->right) <= 0){
                return rotateLeft(root);
            }
            else{
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }
        return root;
    }  
};
int main()
{
    string key;
    string value;
    Avl obj;
    Node* root = NULL;
    int choice = 0;

    do
    {
        cout << "Menu" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. SEARCH" << endl;
        cout << "3. ASCENDING ORDER" << endl;
        cout << "4. DESCENDING ORDER"<< endl;
        cout << "5. DELETE" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Entry:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                root = obj.insert(root, key, value);
                cout << "Inserted key-value pair: " << key << ": " << value << endl;
                char x;
                cout<<"Do you want to insert more items :(y/n)"<<endl;
                cin>>x;
                if(x=='y'){
                    goto Entry;
                }
                
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (obj.search(root, key))
            {
                cout << "Key found!" << endl;
            }
            else
            {
                cout << "Key not found." << endl;
            }
            break;

        case 3:
            cout << "Ascending order :";
            obj.Ascending(root);
            cout << endl;
            break;
        
        case 4:
            cout << "Descending order : ";
            obj.Descending(root);
            cout << endl;
            break;

        case 5:
            cout << "Enter key to delete: ";
            cin >> key;
            root = obj.Deletion(root, key);
            cout << "Key deleted: " << key << endl;
            break;

        case 6:
            cout << "EXIT" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}