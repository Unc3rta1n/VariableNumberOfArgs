#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int n, ...)
{
	int result = 0;
	int* ptr = &n;
	++ptr;
	while (n > 0)
	{
		result += *ptr;
		++ptr;
		--n;
	}
	return result;
}
int sum_via_stdargMACROSES(int n, ...)
{
	va_list arglist;
	va_start(arglist, n);
	int result = 0, i = 0;
	while (n > 0)
	{
		i = va_arg(arglist, int);
		result += i;
		--n;
	}
	va_end(arglist);
	return result;
}

double sumDouble(double n, ...)
{
	double result = 0;
	double* ptr = &n;
	++ptr;
	while (n > 0)
	{
		result += *ptr;
		++ptr;
		--n;
	}
	return result;
}
double sum_double_via_stdargMACROSES(int n, ...)
{
	double sum = 0.0, tmp;
	va_list argptr;

	
	va_start(argptr, n);
	for (; n; n--) {
		tmp = va_arg(argptr, double);
		sum += tmp;
	}

	
	va_end(argptr);

	return sum;
}
char* concat(int n, ...)
{
	va_list arglist;
	va_start(arglist, n);
}
int main()
{
	printf("%d\n", sum(4, 1, 2, 3, 4));
	printf("%d\n", sum_via_stdargMACROSES(4, 1, 2, 3, 4));

	
	printf("%lf\n", sumDouble(4, 1.1, 2.2, 3.0, 0.1));
	printf("%lf\n", sum_double_via_stdargMACROSES(4, 1.1, 2.2, 3.0, 0.1));

	system("pause");
	return 0;
}