#include<stdio.h>
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
