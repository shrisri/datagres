# Objective: Verifies that right strings are at the right offsets of file newfile.txt using shell script.
# 
# Method: Program iterates through newfile2.txt (metadata), extracts character, size, offset and then goes to
# specific offset in newfile.txt for verification.
#
# Author: Shriya S
#

# Empties file results3.txt before writing data into it.
if [ -f "results3.txt" ]
then
        rm results3.txt
        touch results3.txt
else
        touch results3.txt
fi

file="newfile2.txt"

# Looping through lines of newfile2.txt ( metadata file )
while read line
do
        name=$line

        # Extracting the character, size, offset from newfile2.txt
        c=`echo $name | awk '{print $1}'`
        size=`echo $name | awk '{print $2}'`
        off=`echo $name | awk '{print $3}'`
        echo $c,$size,$off >> results3.txt

        # Seeking the extracted offset in newfile.txt using dd command
        rstr=$(dd if=newfile.txt skip=$off ibs=1 count=$size)
        firstc=${c:0:1}
        flag=0

        # Comparing characters with string extracted
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
                echo "Success" >> results3.txt
        else
                echo "Failure" >> results3.txt
        fi
done < $file
echo "Verified. Verification results in results3.txt"
