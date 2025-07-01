#include<bits/stdc++.h>
using namespace std;

int main()
{
 int z=1;

while(z--)
{
	char arr[7]={'A','B','C','D','E','F','G'};
	int k=8;
	int len=6;
	for(int i=0;i<13;i++)
	{
		if(i>6)
		  cout<<arr[12-i]<<" ";
		else
		   cout<<arr[i]<<" ";  
	}
	cout<<"\n";
	while(k--)
	{
		for(int i=0;i<len;i++)
		 cout<<arr[i]<<" ";
		 cout<<" "<<" ";
		for(int i=0;i<(6-len)*2;i++) 
		 cout <<" ";
		for(int i=0;i<(6-len)*2;i++) 
		 cout <<" ";
		for(int i=len-1;i>=0;i--)
		 cout<<arr[i]<<" "; 
		 len--;
		 cout<<"\n";
	}
	
}

}