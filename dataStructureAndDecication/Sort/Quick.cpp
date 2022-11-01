2#include <iostream>

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
void quickSort (int *a,int left,int right){
    int i,j,x;
    i=left;
    j=right;
    x=a[(left+right)/2];
    do {
      if (a[i]<x){
        i++;
      }
      if (a[j]>x){
        j--;
      }   
      if (i<=j){
        swap (a[i],a[j]);
        i++;
        j--;
      }
    }while (i<=j);
    if (left <j){
        quickSort(a,left,j);
    }
    if (right >i){
        quickSort(a,i,right);
    }
}

int main(){
    int a[100];
    int n;
    cin>>n;
    nhapMang(a,n);
    xuatMang(a,n);
    cout<<"\n==========="<<endl;
    quickSort(a,0,n-1);
    xuatMang(a,n);
}