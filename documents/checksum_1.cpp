#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int checksum(const char *s)
{
	signed char sum = -1;
	while (*s != 0)
	{
		sum += *s;
		s++;
	}
	return sum;
}
 
int main()
{
	int haha = checksum("RBHRB,101218,161230,21.31198,N,157.88972,W,AUVSI,2");
	cout<<haha<<endl;
	return 0;
}
