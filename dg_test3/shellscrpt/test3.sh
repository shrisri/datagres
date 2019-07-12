# Objective: Verifies that right strings are at the right offsets of file newfile.txt using shell script.
# 
# Method: Program iterates through newfile2.txt (metadata), extracts character, size, offset and then goes to
# specific offset in file argument for verification.
#
# Author: Shriya S
#

# Empties results2.txt before writing to it
if [ -f "results2.txt" ]
then
        rm results2.txt
        touch results2.txt
else
        touch results2.txt
fi

# Reading newfile2.txt.
file=$1
while read line
do
        name=$line
        # Reading char, size, offset
        c=`echo $name | awk '{print $1}'`
        size=`echo $name | awk '{print $2}'`
        off=`echo $name | awk '{print $3}'`
        
        # Writing to results2.txt
        echo $c,$size,$off >> results2.txt

        # Seeking offset in $2
        rstr=$(dd if=$2 skip=$off ibs=1 count=$size)

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
                 echo "Success" >> results2.txt
        else
                 echo "Failure" >> results2.txt
                 echo $2,"Failure" >> totalres.txt
        fi
        echo "--------------------------" >> results2.txt
        
done < $file

