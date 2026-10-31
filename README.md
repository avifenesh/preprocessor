# preprocessor
hi there!
this project created for academic work, while studying intermediate programing with C language on Linux environment,
any comments, claims, responses and reviews are welcome!

this project is a semi preprocessor that cleans the file from comments and includes the local "include" files.

## Usage

```sh
make
./preprocessor
```

It asks for a C file name (`.c`, up to 19 characters). It writes `<file>.c1` with the `/* */` comments removed, then `<file>.c2` with each `#include "file"` replaced by that file's contents.
