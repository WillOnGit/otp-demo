#include <stdio.h>

char *message = "hello!";
// 68 65 6c 6c 6f 21
char *key = "fj31l2";
// 66 6a 33 31 6c 32

void cipher(){
	char new[7];

	for(int i = 0; i<6; i++){
		new[i] = message[i] ^ key[i];
	}
	new[6] = '\0';
	// 0e 0f 5f 5d 03 13

	printf("%s",new);
}

int main(){
	printf("message is: %s\n", message);
	printf("key is: %s\n", key);

	cipher();

	return 0;
}
