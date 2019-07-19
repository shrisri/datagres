case $1 in
        "1")
                
                if [ "$#" -ne 1 ]
                then
                        echo "Wrong number of arguments. Please try again."
                        exit 1
                fi
                ./Program1
                ;;
        "2")
                
                if [ "$#" -ne 1 ]
                then
                        echo "Wrong number of arguments. Please try again."
                        exit 1
                fi
                ./Program2
                ;;
        "3")
                if [ "$#" -ne 1 ]
                then
                        echo "Wrong number of arguments. Please try again."
                        exit 1
                fi
                ./shellscrpt/program3.sh
                ;;
        "4")
                if [ "$#" -ne 1 ]
                then
                        echo "Wrong number of Arguments. Please try again."
                        exit 1
                fi
                ./shellscrpt/program4.sh
                ;;
        "5")
                if [ "$#" -ne 3 ]
                then
                        echo "Wrong number of Arguments. Please try again "
                        exit 1
                fi
                ./shellscrpt/program5.sh $2 $3
                ;;
         *)
                echo "Wrong Argument given. Try again."
                exit 1
esac
