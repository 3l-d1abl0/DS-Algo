#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007
using namespace std;

//https://www.codechef.com/problems/SP04

int main()
{   std:ios_base::sync_with_stdio(false);
    string s;
    char c;
    int i,cnt,j;
    while(cin>>s)
    {
    	for(i=0;i<s.length();)
    	{
    	   c=s[i]; cnt=1; i++;
    	   while(1)
    	   {
    	   	if(i<s.length())
    	   	{
    	   	   if(s[i]==c)
    	   	   {
    	   	   	cnt++;
    	   	   	i++;
    	   	   }
    	   	   else
    	   	   {
    	   	   	 if(cnt>3)
    	   	   	 printf("%d!%c",cnt,c);
    	   	   	 else
    	   	   	 {
    	   	   	 	for(j=0;j<cnt;j++)
    	   	   	 	printf("%c",c);
    	   	   	 }
    	   	   	 break;
    	   	   }
    	   	}
    	   	else
    	   	{
    	   		if(cnt>3)
    	   	   	 printf("%d!%c",cnt,c);
    	   	   	 else
    	   	   	 {
    	   	   	 	for(j=0;j<cnt;j++)
    	   	   	 	printf("%c",c);
    	   	   	 }
    	   	   	 break;
    	   	}
    	   }
    	}
    	printf("\n");
    }
	return 0;
}

