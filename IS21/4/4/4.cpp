#include "stdafx.h"
#include "locale.h"
#include "stdlib.h"
#include "math.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0,"Russian");
	float sum=0;
	float c=0,F=0;
	float x,xn,xk,dx;
	float a,an,ak,da;
	float b,bn,bk,db;

	do
	{
		printf("¬ведите an,ak,da\n");
		scanf("%f %f %f", &an, &ak, &da);
	}
	while(!((an<ak && da>0) || (an>ak && da<0)));

	do
	{
		printf("¬ведите bn,bk,db\n");
		scanf("%f %f %f", &bn, &bk, &db);	
	}
	while(!((bn<bk && db>0) || (bn>bk && db<0)));

	printf("¬ведите с\n");
	scanf("%f", &c);

	do
	{
		printf("¬ведите xn,xk,dx\n");
		scanf("%f %f %f", &xn, &xk, &dx);
	}
	while (!((xn<xk && dx>0) || (xn>xk && dx<0)));
	x=xn;

	printf("|%-14s|%-14s|%-14s|%-14s| \n","x","a","b","F");

	if (xn > xk)
	{
		float temp = xn;
		xn = xk;
		xk = temp;	
		dx*=-1;
	}

	if (an > ak)
	{
		float temp = an;
		an = ak;
		ak = temp;	
		da*=-1;
	}

	if (bn > bk)
	{
		float temp = bn;
		bn = bk;
		bk = temp;	
		db*=-1;
	}

	while (x <= xk)
	{
		a=an;
		do
		{
			for (b = bn; b <= bk; b+=db)		
			{
				if (x<0 && b!=0)
					F = a*pow(x,3)+b*pow(x,2);
				else if(x>0 && b==0)
						if ((x-c)!=0)
							F = (x+a)/(x-c);
						else
						{
							printf("|%-14.8f|%14.8f|%14.8f|%s| \n", x, a, b, "--------------");
							continue;
						}
				else if (x!=10)
						F = (x+5)/(x-10);
					else
					{
						printf("|%-14.8f|%14.8f|%14.8f|%s| \n", x, a, b, "--------------");
						continue;
					}
			sum += (x-a*F);
			printf("|%-14.8f|%14.8f|%14.8f|%14.8f| \n", x, a, b, F);
			}
			a += da;
		}
		while(a <= ak);
		x+=dx;
	}

	printf("summa: %f\n",sum);
	system("pause");
	return 0;
}