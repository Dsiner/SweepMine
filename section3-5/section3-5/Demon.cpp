#include "Demon.h"
#include <iostream>
using namespace std;
void Demon::Volume()
{
	cout<<"�����Ϊ��"<<x<<","<<y<<","<<z<<"���Ϊ��"<<x*y*z<<endl;
}
Demon::Demon(int a,int b,int c)
{
	x=a,y=b,z=c;
}