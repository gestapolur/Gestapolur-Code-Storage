g++ -g gprob002.cpp -o tst1
g++ -g cmp002.cpp -o tst2
./gen
./tst1
./tst2
diff ans1.out ans2.out  
cp g2.in ./testdata/sg.in
cp ans1.out ./testdata/sg.out
#while ["`diff ans1.out ans2.out`" == ""]
#do
#    ./gen
#    ./tst1
#    ./tst2
#done