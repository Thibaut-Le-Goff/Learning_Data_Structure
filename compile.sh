#!/bin/bash

rm -r bin
make 
#make valgrind > logs/outputs/output_valgrind.txt 2> logs/errors/error_valgrind.txt
make sanitize 

#rm -r bin
#make && ./bin/test
#make valgrind 
#make sanitize && ./bin/test 