#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fib.h"

#define COUNT	100000
#define DIF	1000
#define VERBOSE	0

int cmp(void *, void *);

int cmp(void * x, void * y)
{
	int *a, *b;
	a = (int *)x;
	b = (int *)y;

	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

void main(void)
{
	int z[COUNT];
	struct fibheap *a;
	int i, x;
	void *w;

	a = fh_makeheap();
	fh_setcmp(a, cmp);

	srandom(time(NULL));
#if 1
#if VERBOSE
	printf("inserting: ");
#endif
	for (i = 0; i < COUNT; i++) {
#if VERBOSE
		if (i)
			printf(", ");
#endif
		fh_insert(a, (void *)(x = random()/10));
#if VERBOSE
		printf("%d", x);
		if (i > DIF)
			printf("throwing: %d\n", fh_extractmin(a));
#endif
	}

#if VERBOSE
	printf("\nextracting: ");
#endif
	for (i = 0; i < COUNT - DIF; i++) {
#if VERBOSE
		if (i)
			printf(", ");
		printf("%d", fh_extractmin(a));
#else
		fh_extractmin(a);
#endif
	}
#if VERBOSE
	printf("\n");
#endif
#else
	w = fh_insert(a, 6);
	printf("adding: %d\n", 6);
	fh_insert(a, 9);
	printf("adding: %d\n", 9);
	fh_insert(a, 1);
	printf("adding: %d\n", 1);
	for(i = 0; i < 5; i++) {
		x = random()/10000;
		printf("adding: %d\n", x);
		fh_insert(a, x);
	}
	fh_insert(a, 4);
	printf("adding: %d\n", 4);
	fh_insert(a, 8);
	printf("adding: %d\n", 8);
	printf("first: %d\n", fh_extractmin(a));
	printf("deleting: %d\n", fh_delete(a, w));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	for(i = 0; i < 5; i++) {
		x = random()/10000;
		printf("adding: %d\n", x);
		fh_insert(a, x);
	}
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
	printf("first: %d\n", fh_extractmin(a));
#endif

	fh_deleteheap(a);
}
