declare -i cnt;
cnt=1;
while [ "$cnt" != "7" ]
do
    time ./$1 < $2in$cnt > $1.out 
    diff $1.out $2out$cnt
    echo 'test' $cnt 'ok'
    cnt=$[$cnt+1]
done