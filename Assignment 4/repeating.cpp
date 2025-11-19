#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"enter the repeating string:"<<endl;
    getline(cin,s);
    queue<char>q;
    int freq[256]={0};
    for(char ch:s){
        freq[ch]++;
        q.push(ch);
        while(!q.empty() && freq[ch]>1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1 ";
        }
        else{
            cout<<ch<<" ";
        }
    }
  return 0;

}
