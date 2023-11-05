#include <stdio.h>

int cipher(FILE *message, FILE *key){
	int m, k;
	while ((m = getc(message)) != EOF){
		k = getc(key);
		if (k == EOF){
			fprintf(stderr, "ERROR: key shorter than message.\nOutput has been truncated!\n");
			return 1;
		}
		putchar(m ^ k);
	}

	return 0;
}

int main(int argc, char **argv){
	if (argc < 3) {
		fprintf(stderr, "not enough args\n");
		return 1;
	}

	char *messagefilename = *(argv + 1);
	char *keyfilename = *(argv + 2);

	FILE *messagefile = fopen(messagefilename, "r");
	FILE *keyfile = fopen(keyfilename, "r");

	if (messagefile == 0){
		fprintf(stderr, "could not open message file %s\n", messagefilename);
		return 2;
	}

	if (keyfile == 0){
		fprintf(stderr, "could not open key file %s\n", keyfilename);
		return 2;
	}

	return cipher(messagefile, keyfile);
}
