#!/bin/bash

LEN=10;
K=50;
echo -n "`shuf -i1-$K -n10` " 

echo  " "

# LEN=20000;
# K=`shuf -i1-$LEN -n1`
# echo "$LEN $LEN $LEN" > test1.txt; 
# for i in `seq 1 $LEN`
# do
#  echo -n "`shuf -i0-1 -n1` " >> test1.txt
# done
# echo " " >> test1.txt
# for i in `seq 1 $LEN`
# do 
# 	echo -n "! ? " >> test1.txt
# done