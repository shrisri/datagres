# Objective: Take file arguments, write to all the files and then perform all kinds of verification on the 
# files and finally print all the files that have a failure in verification.
#
# Author: Shriya S
#


# Empties the files before writing to the file again.
if [ -f "newfile2.txt" ]
then
        rm newfile2.txt
        touch newfile2.txt
else
        touch newfile2.txt
fi
if [ -f "totalres.txt" ]
then
        rm totalres.txt
        touch totalres.txt
else
        touch totalres.txt
fi

if [ -f $1 ]
then
        rm $1
        touch $1
else
        touch $1
fi
if [ -f $2 ]
then
        rm $2
        touch $2
else
        touch $2
fi

# Compling and running ttest.cc
g++ ttest.cc
./a.out $1 $2

# Displaying files that have failures in verification.
file=totalres.txt
flag=0
echo "The files that have failures are: "
s="hi"
while read line
do
     if [ "$line" != "$s" ]
     then
                s=$line
                flag=1
                echo $s
    
     fi
done < $file
# If none of files have failures, prints NONE
if [ $flag == 0 ]
then
        echo "NONE"
fi

echo "Verified successfully."
