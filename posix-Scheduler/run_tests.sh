#!/bin/bash

printf "Running Test Cases..................\n"
for file in *.txt
do
	echo "----------	Test Cases for $file ------------------"
	printf "\nfcfs..."
	make clean &>/dev/null
	make fcfs &>/dev/null
	DIFF=$(diff <(./fcfs $file) ./test_output/out_fcfs_$file)
	if [ !"$DIFF" ]
	then
		printf "pass"
	fi
	printf "\nsjf..."
	printf "\nrr..."
	printf "\npriority..."
	printf "\npriority_rr...\n"
done
