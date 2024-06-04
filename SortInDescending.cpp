#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr,vector<int> &arr1,vector<int> &arr2 )//Merge in decreasing order
{
    int i=0,j=0,k=0;
    while(i<arr1.size()&&j<arr2.size())
    {
        if(arr1[i]>arr2[j])
            arr[k++]=arr1[i++];
        else 
            arr[k++]=arr2[j++];   
    }
    if(i>=arr1.size()){
        while(j<arr2.size())
          arr[k++]=arr2[j++];
    }
    else
        while(i<arr1.size())
           arr[k++]=arr1[i++];

    return;
}
void MergeSort(vector<int> &arr)
{
    if(arr.size()==1) return;
    int n= arr.size(),n1=n/2,n2=n-n/2;
    vector<int> arr1(n1), arr2(n2);

    for(int i=0;i<n1;i++)
      arr1[i]=arr[i];
    
    for(int i=0;i<n2;i++)
      arr2[i] = arr[i+n1];

    MergeSort(arr1);
    MergeSort(arr2);

    merge(arr,arr1,arr2);

}
int main()
{
    vector<int> arr={1,4,2,5,1};
    MergeSort(arr);
     vector<int> arr1={4,2},arr2={5,3,1};
    
    for(int i=0;i<arr.size();i++)
      cout<<arr[i]<<" ";
    cout<<endl;
}