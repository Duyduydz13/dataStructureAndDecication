#include <iostream>

using namespace std;

void nhapMang(int *a,int n){
    for (int i=0;i<n;i++){
      cin>>a[i];
    }
}
void xuatMang(int *a ,int n){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void swap(int &a,int &b){
    int tam;
    tam=a;
    a=b;
    b=tam;
}

void bubbleSort(int *a,int n){
    int min;
    int luot=1;
    for (int i=0;i<n-i;i++){
     cout<<"luot "<<luot<<endl;
     int tam=1;
        for(int j=0;j<n-i;j++){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            cout<< tam<<"- doi "<<a[j] <<" va " <<a[j+1]<<endl; 
            tam++;
            }
        }
        luot++;
    }
}
int main(){
    int n;
    cout<<"Nhap so luong phan tu mang :\n";
    cin>>n;
    int *a =new int [n];
    nhapMang(a,n);
    cout<<"===mang vua nhap la :===\n";
    xuatMang(a,n);
    cout<<"\n cac buoc doi :\n";
    bubbleSort(a,n);
    cout<<"\n====mang sau khi sap xep :===\n";
    xuatMang(a,n);
    return 0;
}