#!/bin/bash

run_test () {
	make clean &>/dev/null
	make $1 &>/dev/null
	OUT=./test_output/out_$1_$2
	if (test -f $OUT) 
		then 
			printf "$1... "
			diff <(./$1 $2) $OUT
			if [ $? -eq 0 ]; then
					printf "pass\n"
				else
					printf "FAILED\n"
			fi
		fi
}

printf "Running Test Cases..................\n"
for file in *.txt
do
	printf "Test Cases for $file------------------\n"
	run_test "fcfs" "$file"
	run_test "sjf" "$file"
	run_test "rr" "$file"
	run_test "priority" "$file"
	run_test "priority_rr" "$file"
done
