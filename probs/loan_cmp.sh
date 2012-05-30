declare -i i;
i=1;
while [ $i != 5 ]
do
    time ./loan < /media/SOFTWARE/Olympaid_Informatics_2009/Year_2008/OriginalWorks/暑假集训/day4/Data/loan/LOAN$i.IN > loan_tmp.out
    diff /media/SOFTWARE/Olympaid_Informatics_2009/Year_2008/OriginalWorks/暑假集训/day4/Data/loan/LOAN$i.OUT loan_tmp.out
    i=$[$i+1]
done