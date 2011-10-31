while [ "" == "" ]
do
    ./gen > test.in
    ./1155 < test.in
done