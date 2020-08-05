#include <iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

#define pb push_back
#define lint long long int

lint eval(lint a, lint b, char op)
{
	if(op=='+')
		return a+b;
	else if(op=='-')
		return a-b;
	else if(op=='*')
		return a*b;
}

void MinAndMax(vector<vector<lint>> &m, vector<vector<lint>> &M, lint i, lint k, string &op) {
	lint Min=INT_MAX;
	lint Max=INT_MIN;
	lint a=0,b=0,c=0,d=0;
	/*cout<<"max vector recieved is:\n";
	for(int i=0;i<op.length()+1;i++)
	{
		for(int j=0;j<op.length()+1;j++)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"min vector recieved is:\n";
	for(int i=0;i<op.length()+1;i++)
	{
		for(int j=0;j<op.length()+1;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//cout<<"i= "<<i<<" k= "<<k<<endl;
	for(lint j=i;j<k;j++)
	{
		a=eval(M[i][j], M[j+1][k], op[j]);
		b=eval(M[i][j], m[j+1][k], op[j]);
		c=eval(m[i][j], M[j+1][k], op[j]);
		d=eval(m[i][j], m[j+1][k], op[j]);
		Min=min(Min, min(a, min(b, min(c, d))));
		Max=max(Max, max(a, max(b, max(c, d))));
	}
	if(Min!=INT_MAX&&Max!=INT_MIN) {
		m[i][k]=Min;
		M[i][k]=Max;
	}
}

lint get_maximum_value(const string &exp) {
	lint tmp,k;
	vector<lint> oprnd;
	lint n=exp.length();
	for(lint i=0;i<n;i+=2)
	{
		tmp=exp[i]-'0';
		oprnd.pb(tmp);
	}
	string op="";
	for(lint i=1;i<n;i+=2)
		op+=exp[i];
	lint nd=oprnd.size();
	lint nop=op.length();
	vector<vector<lint>> m(nd, vector<lint> (nd, 0));
	vector<vector<lint>> M(nd, vector<lint> (nd, 0));
	for(int i=0;i<nd;i++)
	{
		m[i][i]=oprnd[i];
		M[i][i]=oprnd[i];
	}
	for(lint i=0;i<nd;i++)
	{
		for(lint j=0;j<nd-i;j++)
		{
			k=j+i;
			MinAndMax(m,M,j,k,op);
		}
	}
	return M[0][nd-1];
}

int main() {
	string s;
	cin >> s;
	cout << get_maximum_value(s) << '\n';
}
