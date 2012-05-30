./gen > test.in
./timus1158_cmp < test.in > t1.out
./test < test.in > t2.out
diff t1.out t2.out

while ["`diff t1.out t2.out`" == ""]
do
    ./gen > test.in
    ./timus1158_cmp < test.in > t1.out
    ./test < test.in > t2.out
    #diff t1.out t2.out
    echo 'same'
done