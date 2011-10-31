declare -i a
a=1
g++ -o gen gen.cpp 
while [ a<11 ]
do
./gen > input"$a".in
./stp1 < input"$a".in > output"$a".out
a=a+1
done
#./stp4 #< data.in > out2.out
#diff out1.out out2.out
#diff out1.out out2.out
#while [ "`diff out1.out out3.out`" == "" ]
#do
#./gen > data.in
#./stp1 #< data.in > out1.out
#./stp4 #< data.in > out2.out
#echo "$a"
#a=a+1
#done
