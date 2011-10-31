g++ -g ./key.cpp  -o ./key
g++ -g ./test.cpp -o ./test
g++ -g ./test2.cpp -o ./test2
./key > test.in
echo "data finish "
./test < test.in > test1.out
./test2 < test.in > test2.out

echo "finish"

diff test1.out test2.out

while ["`diff test1.out test.out`" == ""]
do
    ./key > test.in
    ./test < test.in > test1.out
    ./test2 < test.in > test2.out
done