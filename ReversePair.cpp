//Leetcode 493
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int>& arr1, vector<int>& arr2, vector<int> &ans) 
{
    int i=0,j=0,k=0;
    while(i<arr1.size()&&j<arr2.size())
    {
        if(arr1[i]<=arr2[j]) //This equals sign will make merge sort stable!
            ans[k++]=arr1[i++];
        else
           ans[k++]=arr2[j++];
        
    }
    if(i>=arr1.size())
    {
        for(;j<arr2.size();j++){
            ans[k++]=arr2[j];
        }

    }
    else{
        for(;i<arr1.size();i++){
           ans[k++]=arr1[i];
        }
    }
    return ;

}
int reversepair(vector<int> arr1, vector<int> arr2)
{
    int i=0,j=0;
    int c=0;
    while(i<arr1.size()&&j<arr2.size())
    {
        if(arr1[i]>(2*arr2[j])){
            c += arr1.size()-i;
            j++;
        }
        else i++;
    }
    return c;
}
void mergeSort(vector<int>& arr,int &count)
{
    int n=arr.size();
    if(n==1) return;
    //Divide array into two parts:
    vector<int> arr1, arr2;
    int n1 = n/2, n2=n-n/2;
    for(int i=0;i<n1;i++)
          arr1.push_back(arr[i]);

    for(int i=0;i<n2;i++)
        arr2.push_back(arr[i+n/2]);
    
    mergeSort(arr1,count);
    mergeSort(arr2,count);

    count += reversepair(arr1,arr2);

    merge(arr1,arr2,arr);
    
    return;

}
int main()
{
    vector<int> v={5,8,1,2,4};
    int count=0;
    mergeSort(v,count);
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
    cout<<endl;
    cout<<count<<endl;
    
}