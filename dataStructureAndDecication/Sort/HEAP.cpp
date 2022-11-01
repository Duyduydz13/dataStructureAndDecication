#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
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
void Heapfity(int *a,int n,int i){
    while (i<=n/2-1){
        int left = i*2+1;
        int right =i*2 +2;
       int max = left;
       if (right < n && a[max]< a[right]){
        max=right;
       }
       if (a[i]<a[max]){
        swap(a[i],a[max]);
       }
       i=max;
    }
}
void taoHeap(int *a,int n){
    for (int i=n/2-1;i>=0;i--){
        Heapfity(a,n,i);
    }
}
void heapSort(int *a,int n){
    taoHeap(a,n);
    for (int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        Heapfity(a,i,0);
    }
}
int main(){
int a[100];
int n;
cout<<"Nhap so luong phan tu : \n";
cin>>n;
cout<<"nhap mang \n";
nhapMang(a,n);
cout<<"mang vua nhap la : \n";
xuatMang(a,n);
cout<<"\nmang sau khi heap : \n";
heapSort(a,n);
xuatMang(a,n);
    return 0;
}