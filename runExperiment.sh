#!/bin/bash

# make results directory if there isn't one
if [ ! -d "./results" ]; then
	mkdir "./results"
fi

# check if linux, mac, or other
if [ "$(uname)" == "Darwin" ]; then
    # Do something under Mac OS X platform
    echo "Running Mac Makefile"
    make -f makefile.osx
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    # Do something under GNU/Linux platform
    echo "Running Linux Makefile"
    make -f makefile.fedora
else
	echo "Running Windows Cygwin Makefile"
    make
fi

counter=1
until [[ $counter -eq 6 ]]; do
	echo "Program run $counter starting"
	#run experiment
	./a.out
	#move results to results folder
	#changing the file number
	filename='fps_record'
	extension='.csv'
	echo "Saving results in results directory"
	mv fps_record.csv "results/$filename$counter$extension"
	let "counter+=1"
done

echo "Finished with tests"