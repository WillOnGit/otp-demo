.PHONY: clean test

otp: src/otp.c src/cipher.c
	clang -O2 -Wall -Werror -Werror=implicit -std=gnu11 -o otp src/otp.c src/cipher.c

clean:
	rm -f otp test-data/out-truncated-key test-data/out-plaintext

test: otp
	./otp test-data/ref-ciphertext test-data/ref-key test-data/out-truncated-key > test-data/out-plaintext
	diff -s test-data/ref-plaintext test-data/out-plaintext
	diff -s test-data/ref-truncated-key test-data/out-truncated-key
