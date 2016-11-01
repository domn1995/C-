#! /bin/bash

#Usage: ./test.sh ./c- -Pp TestFiles/hw4/testFile.c-

testFilesDir="TestFiles/hw4"
testResultsDir="TestResults/hw4"
bin="$1"
flags="$2"
inFilePath="$3"
inFileName="$(basename $3)"
inFileNameNoExt="${inFileName%.*}"

outFileName="$(basename $3)"
outExt=".out"
outFilePath="$testResultsDir/$outFileName$outExt"

compCommand="$bin $flags $inFilePath > $outFilePath"
diffCommand="diff $outFilePath $testFilesDir/$inFileNameNoExt.out"

echo $compCommand 
echo $diffCommand

eval $compCommand

eval $diffCommand
