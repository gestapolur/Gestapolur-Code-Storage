program gcj2010_r1a_b;
var
   ins,di,m,n,t,tt,ans	: integer;
   i,t1,t2,t3,tmp1,tmp2	: integer;
   a			: array [1..100] of integer;
   fin,fout		: text;
   
function ones(k : integer ): integer ;
begin
   if k = 0 then ones := 0
   else ones := 1;
end;

function abs(a : integer ): integer ;
begin
   if a > 0 then abs := a
   else abs := -a;
end;

begin
   
   assign(fin,'B-small-practice.in');
   assign(fout,'ans.out');
   reset(fin);rewrite(fout);
   
   readln(fin , tt );
   t := 1 ;
   while t <= tt do
   begin
      { init }
      readln(fin , di , ins , m , n );
      for i := 1 to n do
	 read( fin , a[ i ] );
      readln( fin );
      ans := 0 ;
      { work }
      if m <> 0 then
	 begin
	    if n = 2 then
	    begin
	       ans := abs( a[ 2 ] - a[ 1 ] ) div m - 1 + ones( abs( a[ 2 ] - a[ 1 ] ) mod m );
	 ans := ans * ins;
	    end
	    else if n > 2 then
	       for i := 2 to n - 1 do
	       begin
		  { value of delete }
		  t1 := abs( a[i+1] - a[i-1]) div m -1 +ones(abs( a[ i + 1 ] - a[ i - 1 ] ) mod m );
		  t1 := t1 * ins  + di ;
		  { value of direct cal }
		  t2 := abs(a[ i ] - a[ i - 1 ]) div m - 1 + ones(abs( a[ i ] - a[ i - 1 ]) mod m);
		  t2 := t2 + abs( a[ i + 1 ] - a[ i ] ) div m -1 + ones(abs(a[ i + 1] - a[ i ]) mod m );
		  t2 := t2 * ins;
		  { value of change }
		  tmp1 := ( a[ i - 1 ] + a[ i + 1 ] ) div 2 ;{ new middle value }
		  tmp2 := abs( a[ i ] - tmp1 );{ cost }
		  t3 := abs( a[ i + 1 ] - tmp1 ) div m - 1 + ones(abs(a[ i + 1 ] - tmp1 ) mod m ) ;
		  t3 := t3 + abs(a[ i - 1 ] - tmp1 ) div m - 1 + ones(abs(a[ i - 1 ] - tmp1 ) mod m );
		  t3 := t3 + tmp2;
		  {writeln(t1,' ',t2,' ',t3);}
		  tmp1 := 0 ;
		  if t1 < t2 then
		     tmp1 := t1 
		  else
		     tmp1 := t2;
		  if tmp1 > t3 then
		     tmp1 := t3;
		  ans := ans + tmp1;
	       end;
	 end
	 else
	 begin
	    ans := 0 ;
	    {for i := 1 to n do write(fout , a[ i ],' ');writeln(fout);}
	    for i := 2 to n do
	    begin
	       {writeln(fout ,a[ i + 1 ] ,' ', a[ i ] ,' ',i);}
	       ans := ans + abs(a[ i ] - a[ i - 1 ]) - 1;
	    end;
	    ans := ans * ins;
	    {writeln(fout , ans );}
	 end;
	    writeln( fout , 'Case #',t,': ',ans);
	    t := t + 1 ;
	 
   end;
   
   close( fin );
   close( fout );
   
end.