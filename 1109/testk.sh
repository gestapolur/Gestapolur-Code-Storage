./gen > k.in
./k < k.in > k1.out
./ck < k.in > k2.out
diff k1.out k2.out

while ["`diff k1.out k2.out `" == ""]
do
    ./gen > k.in
    ./k < k.in > k1.out
    ./ck < k.in > k2.out
    diff k1.out k2.out
done
