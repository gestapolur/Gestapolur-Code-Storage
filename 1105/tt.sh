./run
./b
./test
diff output1.out output2.out
while ["`diff output1.out output2.out`" == ""]
do
    ./run
    ./b
    ./test
done