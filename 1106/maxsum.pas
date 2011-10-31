program maxsum;
var
   a,f,s    : array[ 1..50000 ] of longint;
   n,m,ans  : longint;
   i,j,t,tt : longint;
   s1,s2    : longint;

function max(a,b : longint ):longint;
begin
   if a > b then exit( a );
   exit( b );
end;

begin
   readln( t );
   tt := 1 ;
   while tt <= t do
   begin
      readln( n );
      for i := 1 to n do
      begin
	 read( a[ i ] );
	 f[ i ] := i;
      end;
      
      for i := 2 to n do
	 if (a[ i ] > 0) and (a[ i - 1 ] > 0) then
	    f[ i ] := f[ i - 1 ];
      m := f[ n ];
      
      for i := n + 1 downto 1 do
	 s[ i ] := 0 ;

      for i := 1 to n do
	 inc(s[ f[ i ] ] , a[ i ] );
      {
      for i := 1 to n do
	 write( f[ i ] ,' ');
      writeln;
      }
      ans := 0 ;
      for i := 1 to m - 1 do
      begin
	 s1 := 0;
	 for j := 1 to i do
	 begin
	    if (s[ j ] > 0) and ( j - 1 > 0 ) then
	       s1 := max( s1 + s[ j ] + s[ j - 1 ] , s[ j ])
	    else if j = 1 then
	       s1 := s[ j ];
	 end;
	 s2 := 0;
	 for j := i + 1 to m do
	 begin
	    if (s[ j ] > 0) and ( j - 1 > 0 ) then
	       s2 := max( s2 + s[ j ] + s[ j - 1 ] , s[ j ])
	    else if j = 1 then
	       s2 := s[ j ];	    
	 end;
	 if ans < s1 + s2 then
	    ans := s1 + s2;
      end;
      
      writeln('Case #',tt,': ',ans );
      inc( tt );
   end;
end.