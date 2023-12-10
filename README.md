# Plausible OTP
For now this is just a basic one-time pad (OTP) implementation in C, described below.
This will be disguised in a larger program where it can be plausibly denied to be a deliberate one-time pad.
The README in `docs` describes the planned "cover" functionality.

## One-time pad
Once built (`make`), simply run `./otp messagefile keyfile`.
Output is to stdout.

An optional third argument can be supplied to write the unused portion of the key to.
So if `messagefile` is 100 bytes long and `keyfile` is 500 bytes then `./otp messagefile keyfile newkeyfile` will write the last 400 bytes of `keyfile` to `newkeyfile`.
