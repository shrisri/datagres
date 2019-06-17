if [ -f "results.txt" ]
then
        echo "hi"
        rm results.txt
        touch results.txt
else
        echo "hellooo"
        touch results.txt
fi


./test4sub1.sh 1 50 $1 $2
./test4sub2.sh 51 101 $1 $2
./test4sub3.sh 102 152 $1 $2
./test4sub4.sh 153 201 $1 $2
