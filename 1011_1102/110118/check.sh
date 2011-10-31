./gen
./lk2
./lk3
diff  lk1.out lk2.out
while ["`diff lk1.out lk2.out`" == ""]
do
    ./gen
    ./lk2
    ./lk3
done
