#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int>ar,int target){

int s=0;int e=ar.size()-1;
int mid=(s+e)/2;
while(s<e){
    if(target==ar[mid]){
        return true;
    }
    else{
        if(target<ar[mid])
            e=mid-1;
        else
            s=mid+1;
    }
    mid=(s+e)/2;
}
return false;
}

bool recBS(vector<int>ar,int s,int e,int target){

    // base case
    if(s>e)
        return false;

    int mid=(s+e)/2;
    if(ar[mid]==target)
        return true;


    // recursice call
    if(target<ar[mid]){
        return recBS(ar,s,mid-1,target);
    }
    else{
        return recBS(ar,mid+1,e,target);
    }

}
int main(){
    vector<int>ar;
    ar.push_back(1);
    ar.push_back(3);
    ar.push_back(5);
    ar.push_back(7);
    ar.push_back(8);

    cout<<binarySearch(ar,9)<<endl;
    cout<<recBS(ar,0,ar.size()-1,8)<<endl;
    return 0;
}