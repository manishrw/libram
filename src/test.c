#include<stdio.h>
#include<stdlib.h>
#include<codegeeta.h>

int main (int argc, char **argv)
{
	//All calls to test libcodegeeta.a here.
	long long *arr;
	int i;
	arr = (long long*) malloc ((argc - 1) * sizeof(long long));
	for (i = 1; i < argc; i++)
		arr [i - 1] = atoll (argv [i]);
	printf(" Ans: %Ld \n", cg_gcd_nl (arr, argc - 1));
	return 0;
}
