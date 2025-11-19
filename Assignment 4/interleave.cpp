#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int>q;
   int n;
   cout<<"enter n elements of a queue"<<endl;
   cin>>n;
   for(int i =0;i<n;i++){
    int x;
    cin>>x;
    q.push(x);
   }

   int halfn = n/2;
   queue<int>newq;
   for(int i=0;i<halfn;i++){
    newq.push(q.front());
    q.pop();
   }
   
   while(!newq.empty()){
    cout<<newq.front()<<" ";
    newq.pop();
    cout<<q.front()<<" ";
    q.pop();
   }
    return 0;
}

