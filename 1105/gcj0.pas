program gcj2010_r1a_1;
var
   n,k	    : integer;
   c	    : array [ 0..50 , 0..50 ] of char;
   t,tt	    : integer;
   i,j,v    : integer;
   r,b	    : boolean;
   fin,fout : text;
procedure check( i , j: integer );
var
   v,w : integer;
begin
   if i + k - 1 <= n then
   begin
      v := i ;
      repeat
	 v := v + 1;
      until (v > i + k - 1) or (c[ i , j ] <> c[ v , j ]);
      if v = i + k then
      begin
	 if c[ i , j ] = 'R' then
	    r := true
	 else
	    b := true;
      end;
   end;
   if j + k - 1 <= n then
   begin
      v := j ;
      repeat
	 v := v + 1;
      until (v > j + k - 1) or (c[ i , j ] <> c[ i , v ]);
      if v = j + k then
      begin
	 if c[ i , j ] = 'R' then
	    r := true
	 else
	    b := true;
      end;
   end;
   
   if (i + k - 1 <= n) and (j + k - 1 <= n) then
   begin
      v := i ; w := j;
      
      repeat
	 v := v + 1 ; w := w + 1 ;	 
      until (v > i + k - 1) or (c[ i , j ] <> c[ v , w ]);
      if v = i + k then
      begin
	 if c[ i , j ] = 'R' then
	    r := true
	 else
	    b := true; 
      end;
   end;
   {writeln('out ', i - k + 1 , j + k - 1 )}
   if (i - k + 1 > 0 ) and (j + k - 1 <= n) then
   begin
      v := i  ; w := j ;
      {if ( i - k + 1 = 1 ) and ( j = 1 ) then writeln( i , j ,c[ i ,j ]);}
      repeat
	 {if ( i - k + 1 = 1 ) and ( j = 1 ) then writeln('!!!!');}
	 v := v - 1 ; w := w + 1;
	 {if ( i - k + 1 = 1 ) and ( j = 1 ) then writeln( v , w , c[ v , w ]);}
      until (w > j + k - 1) or (c[ i , j ] <> c[ v , w ]);
      
      if w = j + k then
      begin
	 if c[ i , j ] = 'R' then
	    r := true
	 else
	    b := true;
      end;
   end;
   
end;

begin
   assign(fin,'A-large-practice.in');
   assign(fout,'ans1.out');
   reset(fin);rewrite(fout);
   readln(fin , t);
   tt := t;
   t := 1 ;
   repeat
      { init }
      readln(fin , n , k );
      for i := 1 to n do
      begin
	 for j := 1 to n do
	    read(fin ,  c[ j , n - i + 1 ]);
	 readln( fin );
      end;

      { garvity }
      for i := 1 to n do
      begin
	 j := n ; v := n ;
	 while ( v > 1 ) and ( c[ v , i ] <> '.' ) do
	    v := v - 1;
	 while j > 0 do
	 begin
	    if (c[ j , i ] <> '.') and ( j < v ) then
	    begin
	       c[ v , i ] := c[ j , i ];
	       c[ j , i ] := '.';
	       while ( v > 1 ) and ( c[ v , i ] <> '.' ) do
		  v := v - 1;
	    end;
	    j := j - 1;
	 end
      end;

      {
      for i := 1 to n do
      begin
	 for j := 1 to n do
	    write(fout , c[ i , j ]);
	 writeln( fout );
      end;
      }
      {writeln('!!!!');}

      
      { check }
      r := false ; b := false;
      for i := 1 to n do
	 begin
	    for j := 1 to n do
	    begin
	       if c[ i , j ] <> '.' then
		  check( i , j );
	    end;
	 end;
      write(fout ,  'Case #',t,': ');
      if r and b then writeln(fout , 'Both')
      else if r then writeln(fout , 'Red')
      else if b then writeln(fout , 'Blue')
      else writeln(fout , 'Neither');
      
      t := t + 1;
   until t > tt;
   
   close(fin);
   close(fout);
   
end.