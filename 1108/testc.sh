./genc > c.in
./c < c.in > c1.out
./c2 < c.in > c2.out
diff c1.out c2.out
while [ "`diff c1.out c2.out `" == "" ]
do
    ./genc > c.in
    ./c < c.in > c1.out
    ./c2 < c.in > c2.out
    diff c1.out c2.out
done