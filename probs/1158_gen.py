import random;

p = open( 'test.in' , 'w' );

p.write( "50 50 10\n" );
s = [] ;

for i in range( 1 , 50 ):
    a = random.randint( 0 , 255 )
    s += chr(a);
    p.write( str( chr(a) ) );
p.write("\n");

p.write( str(s) + "\n" );

#for i in range( 1 , 10 ):
#    for j in range( 1 , 10 ):
#        p.write( s[ random.randint( 1 , 45 ) ] );
#    p.write("\n");

p.close();
