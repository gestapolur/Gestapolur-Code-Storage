program segtree; 
type treenode = record 
		   sum,l,r : longint; 
		end;	   
var			   
   node	    : array[0..2000000] of treenode; 
   n,m	    : longint; 
   a,b	    : longint; 
   i	    : integer; 
   cin,cout : text; 
procedure create(l,r,s: longint ); 
var 
   mid : longint; 
begin 
   node[ s ].l := l; 
   node[ s ].r := r; 
   node[ s ].sum := 0; 
   
   if l <> r then 
   begin 
      mid := (l + r) shr 1 ; 
      create(l,mid,s shl 1 ); 
      create(mid + 1 , r , s shl 1 + 1 ); 
   end; 
end; { create } 

procedure insert(l,r,s : longint ); 
var 
   mid : longint; 
begin 
   
   if (node[ s ].l = l) and ( node[ s ].r = r ) and (node[ s ].sum <> 2) then 
   begin 
      node[ s ].sum := 1 ; 
      node[ s shl 1 ].sum := 1 ; 
      node[ s shl 1 or 1 ].sum := 1 ; 
   end 
   else 
      node[ s ].sum := 2; 

   if node[ s ].l = node[ s ].r then 
      exit; 
   
   mid := (node[ s ].l + node[ s ].r) shr 1; 
  
   if mid >= r then 
      insert( l , r , s shl 1 ) 
   else if mid < l then 
      insert( l , r , s shl 1 or 1 ) 
   else 
   begin 
      insert( l , mid , s shl 1 ); 
      insert( mid + 1 , r , s shl 1 or 1 ); 
   end; 

   if node[ s shl 1 ].sum = node[ s shl 1 or 1 ].sum then 
      node[ s ].sum := node[ s shl 1 ].sum; 
   
end; { insert } 

function find(l,r,s : longint ):longint; 
var 
   mid : longint; 
begin 
   {writeln(l,' ',r,' ',s);} 
   if ( node[ s ].l = l ) and ( node[ s ].r = r ) and ( node[ s ].sum <> 2 )then 
   begin 
      if node[ s ].sum = 1 then 
	 exit( r - l + 1 ) 
      else 
	 exit( 0 ); 
   end; 
   if node[ s ].l = node[ s ].r then 
      exit( 0 ) 
   else 
   begin 
      mid := (node[ s ].l + node[ s ].r) shr 1 ; 
      if mid >= r then 
	 exit(find( l , r , s shl 1 )) 
      else if mid < l then 
	 exit(find( l , r , s shl 1 + 1 )) 
      else 
	 exit(find( l , mid , s shl 1 ) + find( mid + 1 , r , s shl 1 + 1 )) 
   end; 
end; 

begin 
   //assign(cin,'test.in'); 
   //assign(cout,'out2.ans'); 
   //reset(cin); 
   //rewrite(cout); 
   while not eof do 
   begin 
      readln(n,m); 
      create( 1 , n , 1 ); 
      for i := 1 to m do 
      begin 
	 readln(cin,a,b); 
	 writeln(cout,find(a,b,1)); 
	 insert(a,b,1); 
      end; 
      writeln(cout); 
   end; 
end.