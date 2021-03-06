/*

* Author : Nikhil Garg

* Date   : 2010-12-29

* Team Proof's C++ template

*/

 

#include<iostream>

#include<algorithm>

#include<cstring>

#include<cassert>

#include<cstdio>

#include<cmath>

using namespace std;

 

#define s(n)								scanf("%d",&n)

#define fill(a,v) 							memset(a, v, sizeof a)

 

 

typedef long long LL;

 

int testCases, testNum;

 

const int maxn = (int)1e7 + 10;

 

int isComposite[maxn >> 6];

int factor[maxn];

int primes[665000];

int P;

int A,B;

 

inline bool check(int i)

{

	return ( isComposite[i >> 5] & ( 1 << ( i & 31) ) );

}

 

inline void fix(int i)

{

	isComposite[ i >> 5] |= ( 1 << ( i & 31) );

}

 

void seive()

{

	int i,j, k;

	
	for(i = 6; i <= 3160; i += 6)

	{

		for(k = i -1; k <= i + 1; k += 2)

			if(!check(k >> 1) )

				for(j = k * k; j < maxn; j += k << 1)

					fix( j >> 1);

	}

 

	P = 1;

	primes[P++] = 2;

	primes[P++] = 3;

	for(i = 6; i < maxn ;  i += 6)

	{

		for(j = i -1; j <= i + 1; j +=2)

			if(!check(j >> 1 ) )

				primes[P++] = j;

	}

	primes[0] = primes[P++] = 1 << 30;

}

 

void fillMu(int soFar, int lastPrime, int one, bool two)

{

	
	factor[soFar] = two ? ( (one & 1) ? -1 : 1) : ( (one & 1) ?  one : - one);

	int limit = maxn / soFar;

	int p = primes[lastPrime];

	
	if( !two &&  p <=limit)

		fillMu( soFar * p, lastPrime, one, true);

 

	for(lastPrime++ , one++; ( p = primes[lastPrime]) <= limit; lastPrime++)

		fillMu( soFar * p, lastPrime, one, two);

}

 

void precompute()

{

	int i;

	fillMu(1,0,0,0);

	for(i = 1; i < maxn; i++)

		factor[i] += factor[i-1];

	for(i = maxn - 1; i >= 1; i--)

		factor[i] = factor[i-1];

}

 

 

int main()

{

	seive();

	precompute();

	s(testCases);

	for(testNum = 1; testNum <= testCases; testNum ++)

	{

		s(A); s(B);

		if( A > B)		swap(A,B);

		LL ans = 0LL;

		int nextD,a,b, d = 1;

		
		for(int d = 1; d <= A; d = nextD)

		{

			a = A / d; b = B / d;

			nextD =  min( A/a , B/b ) + 1;

			ans += 1LL * (factor[nextD] - factor[d]) * a * b ;

		}

		printf("%lld\n", ans);

	}

} 


