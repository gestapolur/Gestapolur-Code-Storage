./test
echo "gen okay"
./dijkstra <./stp.in > ./out1.out #ou
./floyd <./stp.in > ./out2.out #out2
diff out1.out out2.out

while ["`diff out1.out out2.out `" == ""]
do
    ./bellmanford <./stp.in > ./out3.out #out3
    ./spfa <./stp.in > ./out4.out # out4 
    diff out3.out out4.out
    diff out1.out out3.out
    ./test
    echo "gen okay"
    ./dijkstra
    ./floyd
done
