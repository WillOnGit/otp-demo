# OTP: Open Text Processor
The program applies a user-supplied set of transformations (e.g. trim whitespace, apply sentence case, ...) to its input text.

## Usage
Simply run `otp inputfile rulesfile` (see below for description of rules files).
Output is to stdout.

## Rules files
Rules files describe what should happen to the input text, which can be several linewise transformations.
For now there is only one rule implemented, so the rules file is freeform.
All that matters is that if the rules file contains a `U`, the input will be uppercased.
Otherwise input will be returned unchanged.
