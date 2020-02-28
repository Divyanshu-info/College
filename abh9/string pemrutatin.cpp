#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
int next_permutation(int n, string *s){
    // Find  non-increasing  suffix
    int i = n-1;
    while(i>0 && strcmp(s[i-1],s[i])>=0) 
        i--;    // find key
    if (i<=0) return 0;
    
    // Swap key with its successor in suffix
    int j = n-1;
    while(strcmp(s[i-1],s[j])>=0) 
        j--;    // find rightmost successor to key
    char *tmp = s[i-1];
    s[i-1] = s[j];
    s[j] = tmp;
    j = n-1;
    while(i<j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    return 1;
}
int main()
{

	int n;
    cin>>n;
	string s[n];
	
	for (int i = 0; i < n; i++)
	{
	
	get(cin,s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			cout<<a[i];
			cout<<"\n";
	} while (next_permutation(n, s));

	return 0;
}
