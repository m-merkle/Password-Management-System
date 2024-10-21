# Using clang-format

This repo contains a modified version of the configuration file for the `clang-format` tool. The format is based on the Mozilla rules for C++ with a few local changes. To check your source code's format:

* Change into the repo folder with your source code
* Type `clang-format filename.cpp`
* The formatted source code will be displayed on stdout

If you only want to see the formatting issues, type `clang-format --dry-run filename.cpp`

Type `clang-format --help` for more information.

