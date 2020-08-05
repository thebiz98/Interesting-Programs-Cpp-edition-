#include <bits/stdc++.h>

using namespace std;

bool canPartition(int start, vector<int> arr, vector<bool> used, int k, int currSum, int trgtSum) {
	if(k==1)
		return true;
	if(currSum==trgtSum)
		return canPartition(0, arr, used, k-1, 0, trgtSum);
	for(int i=start; i<arr.size(); i++) {
		if(!used[i]) {
			used[i]=true;
			if(canPartition(i+1, arr, used, k, currSum + arr[i], trgtSum))
				return true;
			used[i]=false;
		}
	}
	return false;
}

int partition3(vector<int> &A) {
	int sum=0;
	for(int i=0;i<A.size();i++)
	{
		sum+=A[i];
	}
	if(sum%3!=0)
		return 0;
	sum=sum/3;
	int n=A.size();
	vector<bool> used(n,false);
	if(canPartition(0,A,used,3,0,sum))
		return 1;
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (size_t i = 0; i < A.size(); ++i) {
		cin >> A[i];
	}
	cout << partition3(A) << '\n';
	return 0;
}
