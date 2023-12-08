#!/bin/bash

rm -r bin
make && make valgrind > output_valgrind.txt
make sanitize && ./bin/test > output_sanitizer.txt
