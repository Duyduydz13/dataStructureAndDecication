#include <iostream>

using namespace std;

void merge(int arr[],int left,int mid , int right){
    int n1=mid - left+1;
    int n2= right- mid;
    int a1[n1];
    int a2 [n2];
    for (int i=0;i<n1;i++){
        a1[i]=arr[left+i];
    }
    for (int j=0;j<n2;j++){
        a2[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=left;
    while((i<n1)&&(j<n2)){
        if (a1[i]<=a2[j]){
            arr[k]=a1[i]    ;
            i++;
        }
        else {
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        arr[k]=a1[i];
        k++;
        i++;
    }
    while (j<n2){
        arr[k]=a2[j];
        k++;
        j++;
    }
}

void mergeSort(int a[],int left,int right){
    
    if (left<right){
        
       int mid = (left +right) /2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);

        merge(a,left,mid,right);
    }
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
int main(){
    int n;
    int *a=new int [n];
    cin>>n;
    nhapMang(a,n);
    cout<<endl;
    xuatMang(a,n);
    cout<<endl;
    mergeSort(a,0,n-1);
    cout<<endl;
    xuatMang(a,n);
    return 0;
}