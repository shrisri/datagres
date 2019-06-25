# Opens the file in which results and entered. Empties the file before entering data.

if [ -f "results.txt" ]
then
        rm results.txt
        touch results.txt
else
        touch results.txt
fi
# Calling sub programs with arguments as offset ranges
./test4sub1.sh 1 50
./test4sub2.sh 51 101
./test4sub3.sh 102 152
./test4sub4.sh 153 201
echo "Verified. Verification results in results.txt"
