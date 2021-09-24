#include<iostream>
using namespace std;
class time
{
	public:
	int hours;
	int minutes;
	int seconds;
	 
	void input()
	{
		cout<<"enter hrs...mins...secs\n";
        cin>>hours>>minutes>>seconds;	
	}
}o1,o2;
void display(time &o1,time &o2)
{
int h,m,s;
s=(o1.seconds+o2.seconds)%60;
m=(o1.minutes+o2.minutes+(o1.seconds+o2.seconds)/60)%60;
h=o1.hours+o2.hours+(o1.minutes+o2.minutes+(o1.seconds+o2.seconds)/60)/60;
cout<<h<<":"<<m<<":"<<s;
}

int main()
{

	o1.input();
	o2.input();
	display(o1,o2);
	return  0;
}
