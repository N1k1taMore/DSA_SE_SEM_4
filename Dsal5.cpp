#include<iostream>
using namespace std;

class Node{
    string key;
    string value;
    Node *next;
public:

    Node(){
        key=" ";
        value=" ";
        next=NULL;
    }
    Node(string s1,string s2){
        key=s1;
        value=s2;
        next=NULL;
    }
    friend class Hashtable;
};
class Hashtable{
    Node **Table;
    int size;

    public:
    Hashtable(int x){
        size=x;
        Table=new Node*[x];
        for(int i=0;i<size;i++){
            Table[i]=NULL;
        }
    }
    int function(string s){
        int i = 0,ascii = 0;
        while(s[i] != '\0')
        {
            ascii += s[i];
            i++;
        }
        return (ascii%size);
    }
    void insert(){
        int n;
        cout<<"How many pairs you want to insert"<<endl;
        cin>>n;
        while(n--){
            string s1,s2;
            cout<<"Enter the key"<<endl;
            cin>>s1;
            cout<<"Enter the value"<<endl;
            cin>>s2;
            Node *nn=new Node(s1,s2);
            int loc=function(s1);
            if(Table[loc]==NULL){
                Table[loc]=nn;
            }
            else{
                Node *temp=Table[loc];
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=nn;
            }
            cout << "Key Inserted" << endl;
        }
    }

    void display(){
       cout << "Index"
             << "\t"
             << "Word"
             << "\t"
             << "Meaning" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << "\t";
            if (Table[i] == NULL)
            {
                cout << "--" << endl;
            }
            else
            {
                Node *temp = Table[i];
                while (temp != NULL)
                {
                    cout << "->" << temp->key << ":"
                         << "\t" << temp->value;
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
    void deletion(){
        string s1;
        cout<<"Enter the key to be deleted"<<endl;
        cin>>s1;  
        int loc=function(s1);
         Node *temp=Table[loc];
        if (Table[loc] == NULL)
        {
            cout << "Key not present" << endl;
        }
        else if(temp->key==s1){
            temp = temp->next;
            delete (Table[loc]);
            cout << "Key deleted" << endl;
            Table[loc] = temp;
            temp = NULL;
        }
        else{
            Node *prev=NULL;
            while(temp->key!=s1 && temp!=NULL){
                prev=temp;
                temp=temp->next;
            }
            if(temp->key==s1){
                prev->next=temp->next;
                delete(temp);
                cout<<"Key Deleted"<<endl;
            }
            else{
                cout<<"Key not found"<<endl;
            }
        }
            
    }

    void find(){
        string s1;
        cout<<"Enter the key to be Searched"<<endl;
        cin>>s1;  
        int loc=function(s1);
        Node *temp=Table[loc];
        Node *prev=NULL;
        if (Table[loc] == NULL){
            cout << "Key not present" << endl;
        }
        else if (temp->key == s1){
            cout << "KEY FOUND" << endl;
            cout << temp->key << ":" << temp->value << endl;
        }
        else{
            while(temp->key!=s1 && temp!=NULL){
                prev=temp;
                temp=temp->next;
            }
            if(temp!=NULL){
                cout << "KEY FOUND" << endl;
                cout << temp->key << ":" << temp->value << endl;
            }
            else{
                cout<<"Key not found"<<endl;
            }  
        }
        
    }         
};
int main(){
    Hashtable H(10);
    int choice;
    do{
        cout << "----------MENU----------" << endl;
        cout << "1.Insert key" << endl;
        cout << "2.Display " << endl;
        cout << "3.Delete key" << endl;
        cout << "4.Search key" << endl;
        cout << "5.Exit"<<endl;

        cout << "ENTER YOUR CHOICE " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            H.insert();
            break;
        case 2:
            H.display();
            break;
        case 3:
            H.deletion();
            break;
        case 4:
            H.find();
            break;
        }

    }while(choice<5);
    return 0;
}