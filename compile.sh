#!/bin/bash

bin_path="bin"


if [ -e "$bin_path" ]; then
    rm -r bin
else
    echo "There is no binary files."
fi

make 
#make valgrind > logs/outputs/output_valgrind.txt 2> logs/errors/error_valgrind.txt
make sanitize 

#rm -r bin
#make && ./bin/test
#make valgrind 
#make sanitize && ./bin/test 
