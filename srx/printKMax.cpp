#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> printKMax(int arr[], int n, int k){//
	vector<int> res;
  deque<int> q;
  if(k<1||k>n)return res;
  for(int i=0;i<n;i++){
    while(!q.empty()&&arr[q.back()]<=arr[i])q.pop_back();
    q.push_back(i);
    if(q.pop()==i-k)q.pop_front();
    if(i>=k-1)res.push(arr[q.front()]);
  }
  for(auto i:result)cout<<i<<" ";//输出结果
  return res;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
        cout<<endl;
    	t--;
  	}
  	return 0;
}
