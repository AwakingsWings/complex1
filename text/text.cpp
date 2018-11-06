// text.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include "complex1.h"
using namespace std;

#pragma warning(disable:4996)

void show(cpx a, cpx b, cpx ab, char c) {
	a.printcpx();
	printf(" %c ", c);
	b.printcpx();
	printf("= ");
	ab.printcpxN();
}

void show(cpx a, double b, cpx ab, char c) {
	a.printcpx();
	printf(" %c %lf= ", c, b);
	ab.printcpxN();
}

void show(double a, cpx b, cpx ab, char c) {
	printf("%lf %c ", a, c);
	b.printcpx();
	printf("= ");
	ab.printcpxN();
}


int main() {
	cpx a, b;
	double c;
	a.scanfcpx();
	b.scanfcpx();
	scanf("%lf", &c);
	show(a, b, a + b, '+');
	show(a, b, a - b, '-');
	show(a, b, a*b, '*');
	show(a, b, a / b, '/');
	show(a, c, a + c, '+');
	show(c, a, c*a, '*');
	show(b, c, b - c, '-');
	show(c, b, c / b, '/');

	a.printcpx();
	printf(" += ");//-=,*=,/=ready
	b.printcpx();
	printf(":\n");
	a += b;
	a.printcpxN();

	a = "2+i";
	b = "-2-i";
	if (a == -b)
	{
		return 0;
	}
	else
	{
		while (1) {}
	}
}




