#include <iostream>
using namespace std;
int main()
{
	int array[]={12,1,3,34,121,565},ch,i;
	int all=sizeof(array)/sizeof(int);
	for(int j=all-1;j>=0;j--)
	{
		for(i=0;i<j;i++)
	{
		if(array[i]>array[i+1])
		{
			ch=array[i];
			array[i]=array[i+1];
			array[i+1]=ch;

		}
	}

	}
	cout<<"从小到大排序如下"<<endl;
	for(int c=0;c<all;c++)
	{
		
		cout<<array[c]<<endl;
	}
	return 0;
	
}