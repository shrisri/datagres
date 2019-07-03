
# Objective: Verifies that right strings are at the right offsets of newfile.txt using shell script.
# 
# Method: Program iterates over 1-50 lines of newfile2.txt (metadata), extracts character, size, offset and  
# then goes to specific offset in file argument for verification.
#
# Author: Shriya S
#

file=$3
sed -n "$1,$2p" $file | 
while read line
do
        name=$line
        c=`echo $name | awk '{print $1}'`
        size=`echo $name | awk '{print $2}'`
        off=`echo $name | awk '{print $3}'`
        echo $c,$size,$off >> results.txt
        rstr=$(dd if=$4 skip=$off ibs=1 count=$size)
        firstc=${c:0:1}
        flag=0
        for ((i=0;i<$size;i++))
        do
              if [ "${rstr:i:1}" != "$firstc" ]
              then
                        flag=1
                        break
              fi
        done
        if [ $flag == 0 ]  
        then
              echo "Success" >> results.txt
        else
              echo "Failure" >> results.txt
              echo $4,"Failure" >> totalres.txt
        fi

done
