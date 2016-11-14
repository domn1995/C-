#! /bin/bash

rm -f TestResults/hw4/testall.out

for file in ./TestFiles/hw4/*.c-; do
	eval ./test.sh ./c- -0 "$file"
done