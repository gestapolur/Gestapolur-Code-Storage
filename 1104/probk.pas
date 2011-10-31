program csu11_k;

type
   int	= integer;
   tree	= record
	     val , rank , lc , rc , pa : int;
	  end;			       
const 
   MAXN	= 20005;
var
   n,m,root,ans    : int;
   a,b,ob,od,rec   : array [ 0..MAXN ] of int;{od is ordinary order of string b}
   node	       : array [ 0..MAXN ] of tree;
   sign	       : boolean ;
   nowp , puted , pre , i ,blank : int;

procedure sort(i , j : int );
var m , n , t , k :  int;
begin
   if i < j then
   begin
      m := i ; n := j ; k := b[ (i + j) shr 1 ];
      while m <= n do
      begin
	 while b[ m ] < k do m := m + 1;
	 while b[ n ] > k do n := n - 1;
	 if m <= n then
	 begin
	    t := b[ m ] ; b[ m ] := b[ n ] ; b[ n ] := t;
	    t := od[ m ] ; od[ m ] := od[ n ] ; od[ n ] := t;
	    m := m + 1;
	    n := n - 1;
	 end;
      end;
      sort( i , n );
      sort( m , j );
   end;
end;

procedure obcreate();
var
   i,cur :  int;
begin
   cur := 0;
   for i := 1 to m do
      od[ i ] := i;
   sort( 1 , n );
   b[ 0 ] := 0 ;
   {cal the transformed pattern of b }
   for i := 1 to m do
   begin
      if b[ i ] <> b[ i - 1 ] then cur := cur + 1;
      ob[ od[ i ] ] := cur;
   end;
   {test}
   for i := 1 to m do
      write(ob[ i ],' ');
   writeln;
end; { obcreate }

procedure init();
begin
   root := 0 ;
   with node[ 0 ] do
   begin
      lc := 0 ; rc := 0 ; pa := 0 ; rank := MAXN + 1 ; val := 0 ;
   end;
end; { init }

procedure lr(x : int );
var
   y :  int;
begin
   y := node[ x ].pa;
   if y = root then root := x;
   node[ x ].pa := node[ y ].pa ;
   
   node[ y ].rc := node[ x ].lc;
   node[ node[ x ].lc ].pa := y;
   node[ x ].lc := y;
   
   if node[ node[ y ].pa ].lc = y then
      node[ node[ y ].pa ].lc := x
   else
      node[ node[ y ].pa ].rc := x;
   node[ y ].pa := x;
end; { lr }

procedure rr(x : int );
var
   y : int;
begin
   y := node[ x ].pa;
   if y = root then
      root := x;
   node[ x ].pa := node[ y ].pa;
   
   node[ y ].lc := node[ x ].rc;
   node[ node[ x ].rc ].pa := y;
   node[ x ].rc := y;

   if node[ node[ y ].pa ].lc = y then
      node[ node[ y ].pa ].lc := x
   else
      node[ node[ y ].pa ].rc := x;
   
   node[ y ].pa := x ;
end; { rr }

procedure del(pos : int );
begin
   while (node[ pos ].lc <> 0 ) or (node[ pos ].rc <> 0 ) do
      if node[ node[ pos ].lc ].rank < node[ node[ pos ].rc ].rank then
	 rr(node[ pos ].lc)
      else
	 lr(node[ pos ].rc);

   if node[ node[ pos ].pa ].lc = pos then
      node[ node[ pos ].pa ].lc := 0
   else
      node[ node[ pos ].pa ].rc := 0;
   
   node[ pos ].rank := 0 ;
   node[ pos ].lc := 0 ;
   node[ pos ].rc := 0 ;
   node[ pos ].pa := 0 ;
   blank := pos;
end; { del }

procedure add(v,ran : int );
var
   x,y : int;
begin
   with node[ blank ] do
   begin
      val := v;
      rank := ran;
      lc := 0 ; rc := 0 ; pa := 0 ;
   end;
   
   y := 0 ; x := root ;
   
   while x <> 0 do
   begin
      y := x;
      if v < node[ x ].val then
	 x := node[ x ].lc
      else
	 x := node[ x ].rc;
   end;

   if y <> 0 then
   begin
      node[ blank ].pa := y;
      if node[ y ].val < v then
	 node[ y ].rc := blank
      else
	 node[ y ].lc := blank;
   end
   else
      root := blank;

   while (node[ blank ].pa <> 0 ) and ( node[ node[ blank ].pa ].rank > node[ blank ].rank ) do
      if node[ node[ blank ].pa ].lc = blank then
	 rr( blank )
      else
	 lr( blank );
   
end; { add }

function dispat(pos : int ) : boolean;
begin
   if sign then
   begin
      if node[ pos ].lc <> 0 then dispat( node[ pos ].lc );

      if pre <> node[ pos ].val then
	 nowp := nowp + 1;
      pre := node[ pos ].val;
      puted := puted + 1 ;
      
      if nowp <> ob[ puted ] then
      begin
	 sign := false;
	 dispat := false;
      end;
      
      if node[ pos ].rc <> 0 then dispat( node[ pos ].rc );
      dispat := true;
   end;
   dispat := false;
end;

var
   t : int;
begin
   readln(t);
   repeat
      { input }
      readln(n,m);
      ans := 0 ;
      for i := 1 to n do
	 read(a[ i ]);
      for i := 1 to m do
	 read(b[ i ]);
      
      { init , create tree , create the compare order }
      init();
      obcreate();
      
      { pattern , first add them all to the treap , then check once}
      blank := 0 ;
      for i := 1 to m do
      begin
	 blank := blank + 1 ;
	 add( a[ i ] , i );
      end;
      
      pre := 0 ; puted := 0; nowp := 0;
      if dispat( root ) then
      begin
	 ans := 1 ; rec[ 1 ] := 1;
      end;
      
      for i := m + 1 to n do
      begin
	 del( root );
	 add( a[ i ] , i );
	 pre := 0 ; puted := 0 ; nowp := 0;
	 if dispat( root ) then
	 begin
	    ans := ans + 1;
	    rec[ ans ] := i;
	 end;
      end;
      writeln( ans );
      for i := 1 to ans do
	 write( rec[ i ],' ');
      writeln;
      t := t - 1;
   until t = 0;
end.