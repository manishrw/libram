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
