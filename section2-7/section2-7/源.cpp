#include <iostream>
using namespace std;
int main()
{
	int a=1,count=0,en;
	for(int i=1;i<=10;i++)
	{
		count=count+i;
		
	}
	cout<<"1-10�ĺ�Ϊ��"<<count<<endl;
	for(int i=1;i<=10;i++)
	{
		en=i%2;
		if(en==0)
			cout<<"------"<<i<<"��ż��"<<endl;
		
	}
	return 0;

}