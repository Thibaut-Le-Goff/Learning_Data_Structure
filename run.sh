#!/bin/bash

make && make valgrind > output_valgrind.txt
make sanitize && ./bin/test > output_sanitizer.txt
rm -r bin