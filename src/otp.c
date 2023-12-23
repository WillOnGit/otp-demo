#include <stdio.h>
#include <ctype.h>

#include "cipher.h"
#include "loadcfg.h"

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
		FILE *newkeyfile = fopen(newkeyfilename, "wb");
		if (!newkeyfile) {
			fprintf(stderr, "could not open new key file %s\n", newkeyfilename);
			return 2;
		}

		return cipher(messagefile, keyfile, newkeyfile);
	} else {
		int c, makeupper;
		makeupper = loadcfg(keyfile);
		while ((c = getc(messagefile)) != EOF) {
			if (makeupper) {
				putchar(toupper(c));
			} else {
				putchar(c);
			}
		}
	}

	return 0;
}
