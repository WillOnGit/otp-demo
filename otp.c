#include <stdio.h>
#include <string.h>

int cipher(char* message, char* key){
	if (strlen(message) > strlen(key)){
		printf("key must be as long as message\n");
		return 1;
	}

	for(int i = 0; i<strlen(message); i++){
		putchar(message[i] ^ key[i]);
	}

	return 0;
}

int main(int argc, char **argv){
	char *message;
	char *key;

	if (argc < 3) {
		printf("not enough args\n");
		return 1;
	}

	message = *(argv + 1);
	key = *(argv + 2);

	return cipher(message, key);
}
