# Objective: Verifies that right strings are at the right offsets of newfile.txt using shell script.
# 
# Method: Program calls 4 subprograms that iterate over a different range of lines of newfile2.txt (metadata), 
# extracts character, size, offset and then goes to specific offset in newfile.txt for verification.
#
# Author: Shriya S
#

# Opens the file in which results and entered. Empties the file before entering data.
if [ -f "results.txt" ]
then
        rm results.txt
        touch results.txt
else
        touch results.txt
fi

# Calling sub programs with arguments as offset ranges
./shellscrpt/Program4sub1.sh 1 50
./shellscrpt/Program4sub2.sh 51 101
./shellscrpt/Program4sub3.sh 102 152
./shellscrpt/Program4sub4.sh 153 201

echo "Verified. Verification results in results.txt"
