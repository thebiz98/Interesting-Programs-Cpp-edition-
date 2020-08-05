#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define points vector<pair<double, double>>

bool order1(pair<double, double> a, pair <double, double> b)
{
	return a.first<b.first;
}

bool order2(pair<double, double> a, pair<double, double> b)
{
	return a.second<b.second;
}

double distance(pair<double, double> a, pair<double, double> b)
{
	double d=sqrt(((b.second-a.second)*(b.second-a.second))+((b.first-a.first)*(b.first-a.first)));
	return d;
}

double combine(points &y, int line, double d)
{
	for(int i=0;i<y.size();i++)
	{
		for(int j=i+1;j<=i+7&&j<y.size();j++)
		{
			d=min(d,distance(y[i], y[j]));
		}
	}
	return d;
}

double closestPoints(points &x, points &y, int l, int r, int n)
{
	double d = INT_MAX;
	if(n<=3)
	{
		for(int i=l;i<=r;i++)
		{
			for(int j=i+1;j<=r;j++)
			{
				d = min(d,distance(x[i],x[j]));
			}
		}
		return d;
	}
	points y1;
	int mid = (l+r)/2;
	int line = (int)(x[mid].first+x[mid+1].first)/2;
	d = min(closestPoints(x,y,l,mid,(mid-l+1)), closestPoints(x,y,mid+1,r,(r-mid)));
	for(int i=0;i<y.size();i++)
	{
		if(y[i].first>=line-d&&y[i].first<=line+d)
			y1.pb(y[i]);
	}
	d = min(d,combine(y1,line,d));
	y1.clear();
	return d;
}

int main()
{
	int n,a,b;
	cin >> n;
	points x,y;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		x.pb(mp(a,b));
		y.pb(mp(a,b));
	}
	sort(x.begin(),x.end(),order1);
	sort(y.begin(),y.end(),order2);
	double ans=closestPoints(x,y,0,x.size()-1,n);
	cout << setprecision(9) << ans <<endl;
}
