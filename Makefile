.PHONY: clean

otp: src/otp.c
	clang -O2 -Wall -Werror -Werror=implicit -std=gnu11 -o otp src/otp.c

clean:
	rm -f otp
