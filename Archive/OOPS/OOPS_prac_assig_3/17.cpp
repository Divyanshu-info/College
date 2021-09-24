#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
	stack<int> s1, s2;

	void put(int x)
	{

		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	int get()
	{

		if (s1.empty())
		{
			cout << "Q is Empty";
			exit(0);
		}

		int x = s1.top();
		s1.pop();
		return x;
	}
};

int main()
{
	Queue q;
	q.put(1);
	q.put(2);
	q.put(3);

	cout << q.get() << '\n';
	cout << q.get() << '\n';
	cout << q.get() << '\n';

	return 0;
}
