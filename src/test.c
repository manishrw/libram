#include<stdio.h>
#include<stdlib.h>
#include<codegeeta.h>

int main (int argc, char **argv)
{
	//All calls to test libcodegeeta.a here.
	long long *arr;
	unsigned int i, *array;
	arr = (long long*) malloc ((argc - 1) * sizeof(long long));
	for (i = 1; i < argc; i++)
		arr [i - 1] = atoll (argv [i]);
	printf("Ans: %Ld \n", cg_gcd_nl (arr, argc - 1));
	scanf("%d",&i);
	array = cg_prime_i(i);
	if (array == NULL)
		printf("exit\n");
	else
	{
		for(i=1;i<array[0];i++)
			printf("%d\n",array[i]);
	}
	return 0;
}
