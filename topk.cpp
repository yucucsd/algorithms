#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

int a[8] = { 1,3,5,7,2,4,6,0 };
int get_ksum(int k)
{
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < k; i++)
    {
        q.push(a[i]);
    }
    for (int i = k; i < 8; i++)
    {
        q.push(a[i]);
        if (q.size() > k)
            q.pop();
    }
    int sum = 0;
    while (q.size() > 0)
    {
        sum += q.top();
        q.pop();
    }
    return sum;

}

int main()
{
    int k;
    while (cin >> k && k > 0)
    {
        cout << get_ksum(k) << endl;
    }
}
