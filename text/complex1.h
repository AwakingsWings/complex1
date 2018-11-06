#include <bits/stdc++.h>
using namespace std;

//by:Akw,2018/11/6
//VS2017 c++ only
//io:scanf/printf

//legal standard example:1+2i;1-2i;0+2i;0-2i;0+0i;1+i;1-i;

//illegal:2i;0;1+-2i;1+(-2)i;1+1i;1-1i;

#pragma warning(disable:4996)

class cpx {
public:
	double addleft;
	double addright;
	cpx() {
		addleft = addright = 0;
	}
	cpx(double l, double r) {
		addleft = l;
		addright = r;
	}
	cpx(char *cpx) {
		char *p;
		if (p=strchr(cpx,'+'))
		{
			if (p[1] == 'i')
			{
				sscanf(cpx, "%lf+i", &addleft);
				addright = 1;
			}
			else
			{
				sscanf(cpx, "%lf+%lfi", &addleft, &addright);
			}
		}
		else
		{
			p = strchr(&cpx[1], '-');
			if (p[1] == 'i')
			{
				sscanf(cpx, "%lf+i", &addleft);
				addright = -1;
			}
			else
			{
				sscanf(cpx, "%lf%lfi", &addleft, &addright);
			}
		}
	}
	void scanfcpx() {
		scanf("%lf+%lfi", &addleft, &addright);
	}
	double mod2() {
		return addleft * addleft + addright * addright;
	}
	double mod() {
		return sqrt(mod2());
	}
	void printcpx() {
		if (abs(addright) != 1)
		{
			printf("%lf+%lfi", addleft, addright);
		}
		else
		{
			printf("%lf", addleft);
			addright < 0 ? printf("-") : printf("+");
			printf("i");
		}
	}
	void printcpxN() {
		if (abs(addright) != 1)
		{
			printf("%lf+%lfi\n", addleft, addright);
		}
		else
		{
			printf("%lf", addleft);
			addright < 0 ? printf("-") : printf("+");
			printf("i\n");
		}
	}
	cpx oneofcpx() {
		double m = mod2();
		addleft /= m;
		addright /= m;
		return *this;
	}
	cpx operator=(char *c) {
		cpx a(c);
		*this = a;
		return *this;
	}

	bool operator==(cpx x) {
		return addleft == x.addleft&&addright == x.addright;
	}
	cpx operator+=(cpx x) {
		addleft += x.addleft;
		addright += x.addright;
		return *this;
	}
	cpx operator-(){
		addleft *= -1;
		addright *= -1;
		return *this;
	}
	cpx operator*=(cpx x) {
		double l= addleft * x.addleft - addright * x.addright;
		addright=addleft * x.addright + addright * x.addleft;
		addleft = l;
		return *this;
	}

	bool operator!=(cpx x) { return !(*this == x); }
	cpx operator-=(cpx x) { return *this += -x; }
	cpx operator/=(cpx x) { return *this *= x.oneofcpx(); }
	cpx operator+(cpx x) { return x += *this; }
	cpx operator-(cpx x) { return x -= *this; }
	cpx operator*(cpx x) { return x *= *this; }
	cpx operator/(cpx x) { return x /= *this; }

};

cpx operator+=(cpx a, double b) {
	a.addleft += b;
	return a;
}
cpx operator*=(cpx a, double b) {
	a.addleft *= b;
	a.addright *= b;
	return a;
}

cpx operator-=(cpx a, double b) { return a += (-b); }
cpx operator/=(cpx a, double b) { return a *= 1 / b; }
cpx operator+(cpx a, double b) { return a += b; }
cpx operator-(cpx a, double b) { return a -= b; }
cpx operator*(cpx a, double b) { return a *= b; }
cpx operator/(cpx a, double b) { return a /= b; }
cpx operator+=(double a, cpx b) { return b += a; }
cpx operator-=(double a, cpx b) { return -b += a; }
cpx operator*=(double a, cpx b) { return b *= a; }
cpx operator/=(double a, cpx b) { return a *= b.oneofcpx(); }
cpx operator+(double a, cpx b) { cpx c(a, 0.0); return c += b; }
cpx operator-(double a, cpx b) { cpx c(a, 0.0); return c -= b; }
cpx operator*(double a, cpx b) { cpx c(a, 0.0); return c *= b; }
cpx operator/(double a, cpx b) { cpx c(a, 0.0); return c /= b; }



