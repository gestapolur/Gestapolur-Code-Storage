./gene > e.in
./e < e.in > e1.out
./cmpe < e.in > e2.out
diff e1.out e2.out
while [ "`diff e1.out e2.out`" == "" ]
do
    ./gene > e.in
    ./e < e.in > e1.out
    ./cmpe < e.in > e2.out
done