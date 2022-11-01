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

void selectionSort(int *a,int n){
    int min;
    for (int i=0;i<n;i++){
        min=i;
        for (int j=i+1;j<n;j++){
            if (a[j]<a[min]){
                min=j;
            } 
        }
        swap(a[i],a[min]);
        cout<< i+1<<"- doi "<<a[i] <<" va " <<a[min]<<endl; 
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
    selectionSort(a,n);
    cout<<"\n====mang sau khi sap xep :===\n";
    xuatMang(a,n);
    return 0;
}