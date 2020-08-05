#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define lint long long int

lint lcs3(vector<lint> &a, vector<lint> &b, vector<lint> c) {
	lint insa, insb, insc, dela, delb, delc, ins, del, mis, match;
	lint l1=a.size();
	lint l2=b.size();
	lint l3=c.size();
	lint len[l1+1][l2+1][l3+1];
	for(lint i=0;i<=l1;i++)
	{
		for(lint j=0;j<=l2;j++)
		{
			for(lint k=0;k<=l3;k++)
			{
				len[i][j][k]=0;
			}
		}
	}
	for(lint i=1;i<=l1;i++)
	{
		for(lint j=1;j<=l2;j++)
		{
			for(lint k=1;k<=l3;k++)
			{
				insa=len[i][j-1][k-1];
				insb=len[i-1][j][k-1];
				insc=len[i-1][j-1][k];;
				dela=len[i-1][j][k];
				delb=len[i][j-1][k];
				delc=len[i][j][k-1];
				match=len[i-1][j-1][k-1]+1;
				mis=len[i-1][j-1][k-1];
				ins=max(insa, max(insb, insc));
				del=max(dela, max(delb, delc));
				if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
					len[i][j][k]=max(ins, max(del, match));
				else
					len[i][j][k]=max(ins, max(del, mis));
			}
		}
	}
	return len[l1][l2][l3];
}

int main() {
	lint n,tmp;
	vector<lint> a,b,c;
	cin>>n;
	for(lint i=0;i<n;i++)
	{
		cin>>tmp;
		a.pb(tmp);
	}
	cin>>n;
	for(lint i=0;i<n;i++)
	{
		cin>>tmp;
		b.pb(tmp);
	}
	cin>>n;
	for(lint i=0;i<n;i++)
	{
		cin>>tmp;
		c.pb(tmp);
	}
	cout<< lcs3(a, b, c) <<endl;
	return 0;
}
