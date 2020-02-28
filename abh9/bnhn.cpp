#include<iostream>
using namespace std;
class country
{
	private:int population;
    public:
	void setpop(int pop)
	{
		this->population=pop;
	}
	int getpop()
	{
		return this->population;
	}};
	class USA:private country{
	};


int main()
{
USA obj;
obj.setpop(100);
cout<<obj.getpop();
return 0;
}
