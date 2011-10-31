./chae < chae.in > chae0.out
if [ "`diff chae.out chae0.out `" != "" ] ; then
    echo "WRONG ANSWER"
else
    echo "ACCEPTED"
fi