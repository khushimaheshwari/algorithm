#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	int count=1;
	for (int i = 0; s[i] != '\0' ; ++i)
	{
		if(s[i]==s[i+1]){
			count++;
		}
		else {
			cout<<s[i]<<count;
			count=1;
		}
	}
	
	return 0;
}