.PHONY: clean

otp: src/otp.c src/cipher.c
	clang -O2 -Wall -Werror -Werror=implicit -std=gnu11 -o otp src/otp.c src/cipher.c

clean:
	rm -f otp
