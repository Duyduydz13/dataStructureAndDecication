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
void shellSort(int a[],int n,int step){
    int i,j,gap,x;
    for ( gap=n/step;gap>0;gap/=step){
        for (int i=gap;i<n;i++){
      x=a[i];
      j=i-gap;//phần từ đứng trước a[gap]
      while (j>=0&&a[j]>x){
        a[j+gap]= a[j];
        j=j-gap;
      }
      a[j+gap]=x;
    }
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
cout<<"\nmang sau khi shell: \n";
shellSort(a,n,5);
xuatMang(a,n);
    return 0;
    return 0;
}