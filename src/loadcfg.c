#include <stdio.h>

#include "loadcfg.h"

/*
 * Read config file f and return whether or not to uppercase input.
 */
int loadcfg(FILE *f)
{
	int c;

	// for now, uppercase if U in input
	while ((c = getc(f)) != EOF) {
		if (c == 'U')
			return 1;
	}

	return 0;
}
