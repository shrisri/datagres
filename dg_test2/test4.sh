# Objective: Verifies that right strings are at the right offsets of newfile.txt using shell script.
# 
# Method: Program calls 4 subprograms that iterate over a different range of lines of newfile2.txt (metadata), 
# extracts character, size, offset and then goes to specific offset in file argument for verification.
#
# Author: Shriya S
# 

# Empties results.txt before writing to it.
if [ -f "results.txt" ]
then
        rm results.txt
        touch results.txt
else
        touch results.txt
fi

# Calling 4 sub programs to verify in parts
./test4sub1.sh 1 50 $1 $2
./test4sub2.sh 51 101 $1 $2
./test4sub3.sh 102 152 $1 $2
./test4sub4.sh 153 201 $1 $2
