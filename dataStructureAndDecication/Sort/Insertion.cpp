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

void insertionSort(int *a,int n){
    int tam,j,i;
    for (int i=1;i<n;i++){
        tam=a[i];
        j=i-1;
        while (j>=0 && a[j]>tam){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tam;
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
    insertionSort(a,n);
    cout<<"\n====mang sau khi sap xep :===\n";
    xuatMang(a,n);
    return 0;
}