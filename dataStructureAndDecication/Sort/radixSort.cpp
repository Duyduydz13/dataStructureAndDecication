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
int Max(int *a,int n){
    int max =a[0];
    for (int i=0;i<n;i++){
        if (a[i]>max){
            max=a[i];
        }
    }
    return max;
}
void coutingSort(int *a,int n){
    //tao số lượng phần tử mảng b=gia trị lớn nhất mảng a
  int maxa=Max(a,n)+1;
 int b[100];
 for (int i=0;i<maxa;i++){
    b[i]=0;
 }
 //nếu giá trị a[j]= i thì tăng b[i] lên 1 
 for (int i=0;i<maxa;i++){
    for (int j=0;j<n;j++){
        if (a[j]==i){
            b[i]=b[i]+1;
        }
    }
 }
 // nếu b[i]>0 thì gán a[k]=i
 //i-- k++
  int k=0;
  for (int i=0;i<maxa;i++){
   while(b[i]>0 && k<n){
        a[k]=i;
        b[i]--;
        k++;
    }
 }
}
void radixSort(int *a,int n){
    
}