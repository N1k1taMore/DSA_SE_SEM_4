#include<iostream>
#include<string.h>
using namespace std;

class Hash{
    char name[20];
    int number;
public:
    friend class Table;
};

class Table{
    Hash H1[10];
    Hash H2[10];

public:
    void CreateTable(){
        for(int i=0;i<10;i++){
            strcpy(H1[i].name,"---");
            H1[i].number=0;
            strcpy(H2[i].name,"---");
            H2[i].number=0;
        }
    }

    int func(char s[]){
        int ascii=0;
        for(int i=0;s[i]!='\0';i++){
            ascii=ascii+s[i];
        }
        return ascii%10;
    }
    void display(){
        int i, tablesize = 10;
        cout << "\n\n--------HT1----------         ---------HT2------------";
        cout << "\n\n Index Name-Number                Index Name-Number  ";
        for (int i = 0; i < 10; i++)
        {
            cout << "\n"
                 << i << "\t" << H1[i].name << "\t" << H1[i].number << "\t" << i << "\t" << H2[i].name << "\t" << H2[i].number;
        }
    }

    void insertWR(){
        char nm[20];
        int num;
        int n;
        cout<<"How many entries are to be inserted"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Enter the name"<<endl;
            cin>>nm;
            cout<<"Enter the number"<<endl;
            cin>>num;
            int loc=func(nm);
            if(H1[loc].number==0){
                strcpy(H1[loc].name,nm);
                H1[loc].number=num;
            }
            else{
                while(H1[loc].number!=0){
                    loc=(loc+1)%10;
                }
                strcpy(H1[loc].name,nm);
                H1[loc].number=num;
            }
            cout<<"Number inserted"<<endl;
        }
    }

    void insertR(){
        char nm[20];
        int num;
        int n;
        cout<<"How many entries are to be inserted"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Enter the name"<<endl;
            cin>>nm;
            cout<<"Enter the number"<<endl;
            cin>>num;
            int loc=func(nm);
            int actual=func(H2[loc].name);
            if(H1[loc].number==0){
                strcpy(H2[loc].name,nm);
                H2[loc].number=num;
            }
            else if(actual==loc){
                while(H2[loc].number!=0){
                    loc=(loc+1)%10;
                }
                strcpy(H2[loc].name,nm);
                H2[loc].number=num;
            }
            else{
                char actualkey[20];
                strcpy(actualkey,H2[loc].name);
                int actualnum=H2[loc].number;
                strcpy(H2[loc].name,nm);
                H2[loc].number=num;
                while(H2[actual].number!=0){
                    actual=(actual+1)%10;
                }
                strcpy(H2[actual].name,actualkey);
                H2[actual].number=actualnum;
            }
            cout<<"Number inserted"<<endl;
        }
    }
    void searchH1(){
        char nm[20];
        int num,n,comparisons=0,comp;
        cout<<"How many entries are to be searched"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            comp=0;
            cout<<"Enter the name"<<endl;
            cin>>nm;
            int loc=func(nm);
            if(strcmp(H1[loc].name,nm)==0){
                comp++;
                cout<<"Number of comparisons :"<<comp<<endl;
            }
            else{
                while(strcmp(H1[loc].name,nm)!=0){
                    comp++;
                    loc=(loc+1)%10;
                }
                cout<<"Number of comparisons :"<<comp<<endl;
                
            }
            comparisons=comparisons+comp;
        }
        cout<<"Total number of comparisons :"<<comparisons<<endl;

    }
    void searchH2(){
        char nm[20];
        int num,n,comparisons=0,comp;
        cout<<"How many entries are to be inserted"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            comp=0;
            cout<<"Enter the name"<<endl;
            cin>>nm;
            int loc=func(nm);
            if(strcmp(H2[loc].name,nm)==0){
                comp++;
                cout<<"Number of comparisons :"<<comp<<endl;
            }
            else{
                while(strcmp(H2[loc].name,nm)!=0){
                    comp++;
                    loc=(loc+1)%10;
                }
                cout<<"Number of comparisons :"<<comp<<endl;
                
            }
            comparisons=comparisons+comp;
        }
        cout<<"Total number of comparisons :"<<comparisons<<endl;

    }
};

int main(){

    Table H;
    int choice;
    do{
        cout << "----------MENU----------" << endl;
        cout << "1.Insert without Replacement" << endl;
        cout << "2.Insert with Replacement" << endl;
        cout << "3.Display " << endl;
        cout << "4.Search without Replacement" << endl;
        cout << "5.Search with Replacement" << endl;
        cout << "6.Exit"<<endl;

        cout << "ENTER YOUR CHOICE " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            H.insertWR();
            break;
        case 2:
            H.insertR();
            break;    
        case 3:
            H.display();
            break;
        case 4:
            H.searchH1();
            break;
        case 5:
            H.searchH2();
            break;
        
        default:
            cout<<"Exit"<<endl;
        }

    }while(choice<6);

    return 0;
}