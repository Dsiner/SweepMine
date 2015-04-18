#include <iostream>
using namespace std;
void index(int *a,int count);
int main()
{
	int array[]={34,645,23,66,8,6,8913,7,9,56};
	int all=sizeof(array)/sizeof(int);
	index(array,all);
	
	return 0;

}
void index(int *a,int count)
{
    int ind=*a,r=0;
	for(int i=1;i<count;i++)
	{
		if(*(a+i)>ind)
		{
			ind=*(a+i);
			r=i;
		}
	}
	cout<<"数组中最大元素所在的索引是："<<r<<endl;
}