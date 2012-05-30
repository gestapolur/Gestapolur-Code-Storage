eclare -i x
x=1
while [ "$x" != "100000" ]
do
    ./test > d.in
    ./d < d.in
    echo "$x ok"
    x=$[$x+1]
done