#!/bin/bash

rm -r bin
make && ./bin/test > output.txt
make valgrind > output_valgrind.txt
make sanitize && ./bin/test > output_sanitizer.txt
