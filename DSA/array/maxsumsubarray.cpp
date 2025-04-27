#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int sum=0,maxsum=0,l=0,r=0;
    while(r<=n){
        if(sum+a[r]<0){
            maxsum=max(maxsum,sum);
            sum=0;
            l=r+1;
            r=r+1;
        }
        else{
            sum=sum+a[r];
            maxsum=max(maxsum,sum);
            r++;
        }
    }
    cout<<maxsum<<endl;
    
}