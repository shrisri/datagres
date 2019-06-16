file=newfile2.txt
sed -n "$1,$2p" $file | 
while read line
do
        name=$line
        c=`echo $name | awk '{print $1}'`
        size=`echo $name | awk '{print $2}'`
        off=`echo $name | awk '{print $3}'`
        echo $c,$size,$off >> results.txt
        rstr=$(dd if=newfile.txt skip=$off ibs=1 count=$size)
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
        fi

done
