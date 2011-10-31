{Gprob #002 steins;gate}
program steins_gate;

const MAXN =  1005;

var
   n	 : integer;
   v,w	 : array[ 1..1000] of real;
   f	 : array[ 1..10000] of real;
   m,tmp : real;
   i,j,t : integer;
   
begin
   readln(t);
   while t > 0 do
   begin
      readln( n , tmp );
      m := tmp * 100.00000000 + 0.5;
      for  i := 1 to n do
      begin
	 readln(w[ i ] , v[ i ]);
	 v[ i ] := v[ i ] * 100 + 0.5;
      end;
      
      for i := 1 to n do
	 for j := int( m ) downto v[ i ] do
	    if f[ j ] < f[ j - int(v[ i ]) ] + w[ i ] then
	       f[ j ] := f[ j - int(v[ i ]) ] + w[ i ];	
      writeln(f[ int(m) ]);  
      for i := m downto 0 do f[ i ] := 0 ;
      --t;
    end;
end.
