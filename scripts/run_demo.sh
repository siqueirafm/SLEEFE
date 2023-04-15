#!/bin/bash

echo ====================================================
echo = Execute sleefe-demo on all files inside data/input
echo ====================================================

for file in ../data/input/*.bez
do
    prefix=`echo $file | sed -e 's/input/output/'`

    count=1
    while [ $count -lt 10 ]
    do
	prefix=`echo $prefix | sed -e 's/\.bez//'`
	output="${prefix}_${count}_segs.slf"
	echo executing ../bin/sleefe-demo $file $output ${count}
	echo `../bin/sleefe-demo $file $output ${count}`
	count=`expr $count + 1`
    done
done
