#include "Demon.h"
#include <iostream>
using namespace std;
void Demon::Volume()
{
	cout<<"长宽高为："<<x<<","<<y<<","<<z<<"体积为："<<x*y*z<<endl;
}
Demon::Demon(int a,int b,int c)
{
	x=a,y=b,z=c;
}