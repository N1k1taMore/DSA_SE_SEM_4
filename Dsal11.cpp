#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    int rollno;
    char name[30];
    int div;
    char address[100];
public:
    void getStudentInfo(){
        cout << "Enter The name of the student:";
        cin >> name;
        cout << "Enter the roll no of the student:";
        cin >> rollno;
        cout << "Enter the divison of the student:";
        cin >> div;
        cout << "Enter the address of the student:";
        cin >> address;
    }
    void display(){
        cout <<"-----------------------------------"<<endl;
        cout << "Name of the student is:" << name << endl;
        cout << "Roll Number of the student is:" << rollno << endl;
        cout << "Divison of the student is:" << div << endl;
        cout << "Address of the student is:" << address << endl;
        cout <<"-----------------------------------"<<endl;
    }
    string getadd(){
        return address;
    }
    int getrollno(){
        return rollno;
    }
};

class FileHandling{
    string filename;
    ofstream ofs;
    ifstream ifs;
    fstream f;
    public:
    FileHandling(){
        cout<<"********OPERATIONS ON FILE********"<<endl;
        cout<<endl;
        cout<<"Enter the filename:";
        cin>>filename;
        filename+=".dat";
    }
    void writerecord(){
        cout<<"********WRITING IN FILE********"<<endl;
        ofs.open("file.dat",ios::binary|ios::app);
        if(!ofs){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            st.getStudentInfo();
            ofs.write((char*)&st,sizeof(st));
        }
        ofs.close();
    }
    void readrecord(){
        cout<<"********READING IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        if(!ifs){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            while(ifs.read((char*)&st,sizeof(st))){
                st.display();
            }
        }
        ifs.close();
    }
    void search(){
        cout<<"********SEARCHING IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        if(!ifs){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            int rn;
            int flag=0;
            cout<<"Enter the Roll Number to search:";
            cin>>rn;
            while(ifs.read((char*)&st,sizeof(st))){
                if(st.getrollno()==rn){
                    cout<<"********Record is Found********"<<endl;
                    st.display();
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<"Record Dosenot Exist!!!!"<<endl;
            }
        }
        ifs.close();
    }
    void modify(){
        cout<<"********MODIFY THE FILE********"<<endl;
        f.open("file.dat",ios::binary|ios::in|ios::out);
        f.seekg(0);
        if(!f){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            int rn;
            int flag=0;
            cout<<"Enter the Roll Number to modify:";
            cin>>rn;
            while(f.read((char*)&st,sizeof(st))){
                if(st.getrollno()==rn){
                    cout<<"********Record is Found********"<<endl;
                    st.display();
                    flag=1;
                    cout<<"Enter the new updated record:"<<endl;
                    st.getStudentInfo();
//                    cout<<st.getadd()<<endl;
                    f.seekp(-sizeof(st),ios::cur);                    
                    f.write((char*)&st,sizeof(st));
                    break;
                }            
            }
            if(flag==0){
                cout<<"Record Dosenot Exist!!!!"<<endl;
            }            
        f.close();
        }
    }
    void deletion(){
        cout<<"********DELETION IN FILE********"<<endl;
        ifs.open("file.dat",ios::binary|ios::in);
        ofs.open("temp.dat",ios::binary|ios::out);
        if(!ifs || !ofs){
            cout<<"File could not be opened"<<endl;
        }
        else{
            Student st;
            int rn;
            cout<<"Enter the Roll Number to Delete:";
            cin>>rn;
            while(ifs.read((char*)&st,sizeof(st))){
                if(st.getrollno()!=rn){
                    ofs.write((char*)&st,sizeof(st));
                }
            }
            ifs.close();
            ofs.close();
            remove("file.dat");
            rename("temp.dat","file.dat");
            
        }
        f.close();
    }
};
int main(){
    FileHandling f1;    
    int choice=1;
    int choose;
    while(choice){
        cout<<"1-Write in a File"<<endl;
        cout<<"2-Read in a File"<<endl;
        cout<<"3-Search in a File"<<endl;
        cout<<"4-Modify in a File"<<endl;
        cout<<"5-Delete in a File"<<endl;
        cout<<"Enter your choice:";
        cin>>choose;
        if(choose==1){
            f1.writerecord();
        }       
        else if(choose==2){
            f1.readrecord();
        }
        else if(choose==3){
            f1.search();
        }
        else if(choose==4){
            f1.modify();
        }
        else if(choose==5){
            f1.deletion();
        }
        cout<<"Do you want to continue(0,1):";
        cin>>choice;
    }
       
    remove("file.dat");
    return 0;
}
