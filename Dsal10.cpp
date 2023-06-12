#include<iostream>
using namespace std;

class heap{
    public:
    int *arr;
    int size;
    heap(){
        size=0;
    }
    heap(int n){
        size=n;
        arr=new int[n];
    }
    int getparent(int child){
        int par;
        if(child %2 !=0){
            par=(child-1)/2;
        }
        else{
            par=(child-2)/2;
        }
        return par;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(int *arr,int size){
        for(int i=size-1;i>=0 ;i--){
            int currIndex=i;
            int child=currIndex;
            int max=child;
            while(true){
                int parent=getparent(child);
                if(parent<0){
                    break;
                }
                if(arr[parent]<arr[max]){
                    max=parent;
                }
                child=parent;
            }
            swap(arr[max],arr[currIndex]);
        }
    }
    void heapSort(){
        int sorted[size];
        int arrsize=size;
        while(true){
            heapify(arr,arrsize);
            int maxele=arr[0];
            arr[0]=arr[arrsize-1];
            sorted[size-arrsize]=maxele;
            arrsize--;
            if(arrsize==0){
                break;
            }
            
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = sorted[i];
        }
    }

};
int main()
{
    int n;
    cout << "Enter No of array elements : " << endl;
    cin >> n;
    heap h(n);
    cout << "Enter Array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> h.arr[i];
    }
    h.heapSort();
    cout << "Sorted Array is: " << endl;
    h.display();


    return 0;
}