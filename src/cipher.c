#include <stdio.h>

#include "cipher.h"

int cipher(FILE *message, FILE *key, FILE *newkey)
{
	int m, k;

	// main output
	while ((m = getc(message)) != EOF) {
		k = getc(key);
		if (k == EOF) {
			fprintf(stderr, "ERROR: key shorter than message.\nOutput has been truncated!\n");
			return 1;
		}
		putchar(m ^ k);
	}

	// write rest of key to new keyfile if supplied
	if (newkey){
		while ((k = getc(key)) != EOF) {
			putc(k, newkey);
		}
	}

	return 0;
}
