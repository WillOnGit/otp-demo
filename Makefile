.PHONY: clean test

otp: src/otp.c src/cipher.c
	cc -O2 -Wall -Werror -Werror=implicit -std=gnu11 -o otp src/otp.c src/cipher.c src/loadcfg.c

clean:
	rm -f otp \
		test-data/out-truncated-key \
		test-data/out-plaintext \
		test-data/out-unchanged \
		test-data/out-uppercased

test: otp
	./otp test-data/ref-ciphertext test-data/ref-key test-data/out-truncated-key > test-data/out-plaintext
	./otp test-data/ref-plaintext test-data/rules-blank > test-data/out-unchanged
	./otp test-data/ref-plaintext test-data/rules-uppercase > test-data/out-uppercased
	diff -q test-data/ref-plaintext test-data/out-plaintext && \
		diff -q test-data/ref-plaintext test-data/out-unchanged && \
		diff -q test-data/ref-uppercased test-data/out-uppercased && \
		echo "Tests succeeded" || echo "Tests failed"
