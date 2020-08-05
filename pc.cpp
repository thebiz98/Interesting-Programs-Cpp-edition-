#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int optimal_sequence(int n, vector<int> &seq)
{
	int minMoves[n+1];
	minMoves[1]=0;
	minMoves[0]=0;
	int numMoves=0;
	for(int i=2;i<=n;i++)
	{
		minMoves[i]=INT_MAX;
		if(i%3==0)
		{
			numMoves=minMoves[i/3]+1;
			if(numMoves<minMoves[i])
				minMoves[i]=numMoves;
		}
		if(i%2==0)
		{
			numMoves=minMoves[i/2]+1;
			if(numMoves<minMoves[i])
				minMoves[i]=numMoves;
		}
		numMoves=minMoves[i-1]+1;
		if(numMoves<minMoves[i])
			minMoves[i]=numMoves;
	}
	int t=n;
	int target=minMoves[n]-1;
	seq.pb(n);
	while(t>1)
	{
		if(t%3==0&&minMoves[t/3]==target)
		{
			t=t/3;
			seq.pb(t);
			target=minMoves[t]-1;
		}
		else if(t%2==0&&minMoves[t/2]==target)
		{
			t=t/2;
			seq.pb(t);
			target=minMoves[t]-1;
		}
		else
		{
			t=t-1;
			seq.pb(t);
			target=minMoves[t]-1;
		}
	}
	return minMoves[n];
}

int main()
{
	int n;
	cin>>n;
	vector<int> seq;
	cout<<optimal_sequence(n,seq)<<endl;
	for(int i=seq.size()-1;i>=0;i--)
		cout<<seq[i]<<" ";
	cout<<endl;
	return 0;
}
