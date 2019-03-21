#include <vector>
#include <iostream>

using namespace std;

void combination(vector<vector<int>>& v, int c, int s)
{
	if (c == s)
	{
		vector<int> r;
		for (int i = 1; i <= s; i++)
		{
			r.push_back(i);
		}
		v.push_back(r);
		return;
	}
	if (s == 1)
	{
		for (int i = 1; i <= c; i++)
		{
			vector<int> r(1, i);
			v.push_back(r);
		}
		return;
	}
	vector<vector<int>> t1;
	combination(t1, c - 1, s - 1);
	for (auto vt : t1)
	{
		vt.push_back(c);
		v.push_back(vt);
	}
	vector<vector<int>> t2;
	combination(t2, c - 1, s);
    	for (auto vt : t2)
	{
		v.push_back(vt);
	}
}

int main()
{
	int n;
	int s;
  cin >> n >> s;
	vector<vector<int>> v;
	combination(v, n, s);
	for (auto vt : v)
    	{
        	for(auto k : vt)
            		cout << k << " ";
        	cout << endl; 
    	}
    	cout << v.size() << " in total\n";
}
