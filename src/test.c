#include<stdio.h>
#include<stdlib.h>
#include<codegeeta.h>

int main (int argc, char **argv)
{
	//All calls to test libcodegeeta.a here.
	//long long *arr;
	//unsigned int i, *array;
	/*arr = (long long*) malloc ((argc - 1) * sizeof(long long));
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
	}*/
	//printf("%d:%d\n",atoi(argv[1]),cg_isPrime_i(atoi(argv[1])));
	//printf("%Ld:%d\n",atoll(argv[2]),cg_isPrime_l(atoll(argv[2])));
	int i,j,k;
	i=atoi(argv[1]);
	j=atoi(argv[2]);
	k=cg_gcd_2l(i,j);
	printf("%d %d: %d %d \n",i,j,k,(i*j)/k);
	return 0;
}
