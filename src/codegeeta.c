#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<codegeeta.h>

//All function definitions here.. :D

//error callback function pointer.
void (*cg_error_callback) (unsigned int, char*);

//Register callback function.
void cg_register_error_callback (void (*function) (unsigned int, char*))
{
	cg_error_callback = function;
}

//Error reporting.
void cg_error (unsigned int errno, char* message)
{
	// Check if the error reporting function is registered.
	if (cg_error_callback)
		(*cg_error_callback) (errno, message);
	else
		fprintf (stderr, "ERROR %x : %s\n", errno, message);
}

//Gcd functions
long long int cg_gcd (long long int x, long long int y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	if (x > y)
		return cg_gcd (y, x % y);
	return cg_gcd (x, y % x);
}

long long int cg_gcd_2l (long long int x, long long int y)
{
	//computes gcd of two numbers x,y
	//using euclid's algorithm.
	if (x == 0 || y == 0)
	{
		cg_error (CG_ERROR_ARGUMENT_IS_ZERO, "Value should be positive whole number");
		return 0;
	}
	if (x < 0 || y < 0)
	{
		cg_error (CG_ERROR_ARGUMENT_IS_NEGATIVE, "Value should be positive whole number");
		return 0;
	}
	return cg_gcd (x, y);
}

long long int cg_gcd_nl (long long int *arr, int count)
{
	//computes gcd of n numbers stored in array
	//using euclid's algorithm.
	long long int result;
	if (count < 1)
	{
		cg_error(CG_ERROR_ARGUMENT_IS_NEGATIVE, "Array count should be positive whole number");
		return 0;
	}
	result = arr [0];
	while (count--)
		result = cg_gcd_2l (result, arr [count]);
	return result;
}

//Prime functions
//Calculates prime number using sieve theory
unsigned int* cg_prime_i (int limit)
{
	uint8_t *arr;
	unsigned int cnt = 1, i, j, *array;
	if (limit < 2)
	{
		cg_error (CG_ERROR_ARGUMENT_OUT_OF_BOUND, "Value should be positive whole number greater than 1");
		return NULL;
	}
	if(limit < 3)
	{
		array = (unsigned int*) calloc (1, sizeof (unsigned int));
		return array;
	}
	arr = (uint8_t*) calloc (limit, sizeof (uint8_t));
	if (arr == NULL)
	{
		cg_error (CG_ERROR_MEMORY_OUT_OF_BOUND, "Unable to allocate memory");
		return NULL;
	}
	arr [0] = arr [1] = 1;
	for (i = 4; i < limit; i += 2)
		arr [i] = 1;
	for (i = 3; i * i < limit; i += 2)
		if (!arr [i])
			for (j = i * i; j < limit; j += (2 * i))
				arr [j] = 1;
	j = 0;
	for (i = 2; i < limit; i++)
		if (!arr [i])
			cnt++;
	array = (unsigned int*) malloc (sizeof (unsigned int) * cnt);
	if (array == NULL)
	{
		cg_error (CG_ERROR_MEMORY_OUT_OF_BOUND, "Unable to allocate memory");
		return NULL;
	}
	array [j++] = cnt;
	for (i = 2; i < limit; i++)
		if (!arr [i])
			array [j++]=i;
	return array;
}
