g++ -g gen001.cpp -o gen001
./gen001
./cmp001
./test
diff ./testdata/upa.out ./testdata/upac.out
while ["`diff ./testdata/upa.out ./testdata/upac.out `" == ""]
do
    ./gen001
    ./cmp001
    ./test
done