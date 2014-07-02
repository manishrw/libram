""" Math Lib generates

"""

def hash_coll_p(n, r):
	res = 1.0
	r = r * 1.0	
	for i in range(n - 2):
		res = res * ((r - (i + 1)) / r)
	return ( 1 - res) * 100

def birt_a_p(n):
	r = 365.0
	return hash_coll_p(n, r)
	
def gcd(a, b):
	if(b == 0):
		return a
	if a < b:
		return gcd(b, a)
	return gcd(b, a % b)

def isprime(n):
	for x in (x for x in xrange(2, n) if x * x <= n):
		if n % x == 0:
			return False
	return True

def primes(n):
	arr_c = [True for x in range(n + 1)]
	arr_c[0] = arr_c[1] = False
	res = []
	for x in (x for x in xrange(4, n + 1) if x % 2 == 0):
		arr_c[x] = False
	for x in (x for x in xrange(2, n / 2) if x * x < n and x % 2 == 1 and arr_c[x] == True):
		for y in (y for y in xrange(x * x, n + 1) if y % x == 0):
			arr_c[y] = False
	for x in range(n + 1):
		if arr_c[x]:
			res.append(x)
	return res