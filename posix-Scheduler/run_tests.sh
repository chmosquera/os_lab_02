#!/bin/bash

run_test () {
	make clean &>/dev/null
	make $1 &>/dev/null
	OUT=./test_output/out_fcfs_$2
	if (test -f $OUT) 
		then 
			DIFF=$(diff <(./$1 $2) $OUT)
			if [ !"$DIFF" ]
				then
					printf "pass"
				else
					printf "FAILED"
			fi
		else
			printf "No matching output file. Fail."
		fi
}

printf "Running Test Cases..................\n"
for file in *.txt
do
	printf "Test Cases for $file------------------\n"
	printf "\nfcfs..."
	run_test "fcfs" "$file"
	
	printf "\nsjf..."
	printf "\nrr..."
	printf "\npriority..."
	printf "\npriority_rr...\n"
done
