#ifndef __CODE_GEETA
#define __CODE_GEETA

//All errors go here.
#define CG_ERROR_ARGUMENT_IS_NULL 1
#define CG_ERROR_ARGUMENT_IS_ZERO 2
#define CG_ERROR_ARGUMENT_IS_NEGATIVE 3
#define CG_ERROR_ARGUMENT_OUT_OF_BOUND 4

//All function declaration here.

//Register an on_error callback function.
void cg_register_error_callback (void (*function) (unsigned int, char*));

//To allow user to throw errors.
void cg_error (unsigned int, char*);

//gcd functions
//computes gcd of two numbers x,y using euclid's algorithm.
long long cg_gcd_2l (long long , long long);

//computes gcd of n numbers stored in array using euclid's algorithm.
long long cg_gcd_nl (long long*, int);

#endif
