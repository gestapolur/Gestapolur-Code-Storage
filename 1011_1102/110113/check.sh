g++ -g ./gen.cpp -o gen
./gen
./choice0
./choice
diff choice1.out choice2.out
while ["`diff choice1.out choice2.out`" = ""]
do
    ./gen
    ./choice0
    ./choice
done
