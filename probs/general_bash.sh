# A general data test bash
# 2012-04-05
# write by gestapolur
# <prog1_name> <prog2_name> <generator>
# plz use bash to run this script e.g: bash ./<this_script>
# $1 = prog1 $2 = prog2 $3 = generator

./$3 > test.in
./$1 < test.in > $1.out
./$2 < test.in > $2.out
diff $1.out $2.out

while ["`diff $1.out $2.out`" == ""]
do
    ./$3 > test.in
    ./$1 < test.in > $1.out
    ./$2 < test.in > $2.out
    diff $1.out $2.out
    echo "test okay"
done
