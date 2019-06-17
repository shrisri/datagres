if [ -f "results2.txt" ]
then
        echo "hi"
        rm results2.txt
        touch results2.txt
else
        echo "hellooo"
        touch results2.txt
fi

file=$1
#echo $2
while read line
do
        name=$line
        #echo $name
        c=`echo $name | awk '{print $1}'`
        size=`echo $name | awk '{print $2}'`
        off=`echo $name | awk '{print $3}'`
        echo $c,$size,$off >> results2.txt
        rstr=$(dd if=$2 skip=$off ibs=1 count=$size)
        #echo "hi"
        #echo $rstr
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

