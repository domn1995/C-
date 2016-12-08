#! /bin/bash

rm -f TestResults/hw4/testall.out

for file in ./TestFiles/hw7/*.c-; do
	eval ./test.sh ./c- -P "$file"
done