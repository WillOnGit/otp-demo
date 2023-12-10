#include <stdio.h>

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

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "not enough args\n");
		return 1;
	}

	char *messagefilename = *(argv + 1);
	char *keyfilename = *(argv + 2);

	FILE *messagefile = fopen(messagefilename, "r");
	FILE *keyfile = fopen(keyfilename, "r");
	FILE *newkeyfile;

	if (!messagefile) {
		fprintf(stderr, "could not open message file %s\n", messagefilename);
		return 2;
	}

	if (!keyfile) {
		fprintf(stderr, "could not open key file %s\n", keyfilename);
		return 2;
	}

	if (argc > 3) {
		char *newkeyfilename = *(argv + 3);
		newkeyfile = fopen(newkeyfilename, "wb");
		if (!newkeyfile) {
			fprintf(stderr, "could not open new key file %s\n", newkeyfilename);
			return 2;
		}
	} else {
		newkeyfile = 0;
	}

	return cipher(messagefile, keyfile, newkeyfile);
}
