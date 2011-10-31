program treap_exercise;

type
   int	= longint;
   node	= record 
	     lc,rc,par,ran,num : int;
	  end;
const			   
   MAXN	= 1000;
	
var
   top , root , ins , val : int;
   tree			  : array [0..MAXN] of node;
   stack		  : array [0..MAXN] of 1..MAXN;

procedure disp(x : int );
begin
   if tree[ x ].lc <> 0 then disp( tree[ x ].lc);
   with tree[ x ] do 
      writeln('pos:',x , ' val:' , num , ' rank:' , ran , ' lc:' , lc , ' rc:' , rc ,' pa:', par);
   if tree[ x ].rc <> 0 then disp( tree[ x ].rc);
end; { disp }


procedure rr(x : int );{right roate}
var
   y : int;
begin
   writeln('right roate');
   y := tree[ x ].par;
   
   if y = root then root := x;
   
   tree[ x ].par := tree[ y ].par;
   tree[ tree[ x ].rc ].par := y;
   tree[ y ].lc := tree[ x ].rc;
   tree[ x ].rc := y;
   if tree[ tree[ y ].par ].lc = y then
      tree[ tree[ y ].par ].lc := x
   else
      tree[ tree[ y ].par ].rc := x;
   tree[ y ].par := x;
end; { rr }

procedure lr(x : int );{left roate}
var
   y : int;
begin
   writeln('left roate');
   y := tree[ x ].par;
   writeln('now y : ',y , 'now x ', x );
   if y = root then
      root := x;
   
   tree[ x ].par := tree[ y ].par;
  
   tree[ tree[ x ].lc ].par := y;
   tree[ y ].rc := tree[ x ].lc;
   tree[ x ].lc := y;
   
   if tree[ tree[ y ].par ].lc = y then
      tree[ tree[ y ].par ].lc := x
   else
      tree[ tree[ y ].par ].rc := x;
   tree[ y ].par := x;
   write('node y : ');
   with tree[ y ] do writeln(num,' ',ran,' ',lc,' ',rc,' ',par);
   write('node x : ');
   with tree[ x ] do writeln(num,' ',ran,' ',lc,' ',rc,' ',par);

end; { lr }

procedure del(pos : int );
begin
   
   while (tree[ pos ].lc <> 0) or (tree[ pos ].rc <> 0) do
   begin
      if tree[ tree[ pos ].lc ].ran < tree[ tree[ pos ].rc ].ran then
	 rr(tree[ pos ].lc )
      else 
	 lr(tree[ pos ].rc );
      writeln('now tree root : ' , root );
      disp( root );
      {readln;}
   end;
   writeln('end now tree root : ' , root );
   disp( root );
   if tree[ tree[ pos ].par ].lc = pos then
      tree[ tree[ pos ].par ].lc := 0 
   else
      tree[ tree[ pos ].par ].rc := 0;
   tree[ pos ].ran := 0;
   tree[ pos ].num := 0;
end; { del }

procedure add(v : int );
var
   pos,x,y : int;
begin
   
   pos := stack[ top ];
   top := top + 1;
   
   Randomize;
   with tree[ pos ] do
   begin
      num := v;
      ran := random( MAXN );
      lc := 0 ; rc := 0 ; par := 0;
   end;
   
   x := root; y := 0;
  
   while x <> 0 do
   begin
      y := x;
      if v < tree[ x ].num then
	 x := tree[ x ].lc
      else
	 x := tree[ x ].rc;
   end;
   
   if y <> 0 then
   begin
      tree[ pos ].par := y;
      if v < tree[ y ].num then
	 tree[ y ].lc := pos
      else
	 tree[ y ].rc := pos;
   end
   else
      root := pos;
   {roate}
   while  ( tree[ pos ].par <> 0 )  and (tree[ tree[ pos ].par ].ran > tree[ pos ].ran) do
   begin
      if tree[ tree[ pos ].par ].lc = pos then
	 rr( pos )
      else
	 lr( pos );
   end;
  
end; { add }

function find(val : int ) : int;
var
   pos : int;
begin
   pos := root;
   while (pos <> 0) and (tree[ pos ].num <> val) do
      if tree[ pos ].num < val then
	 pos := tree[ pos ].rc
      else
	 pos := tree[ pos ].lc;
   find := pos;
end; { find }

procedure init();
var
   i : integer;
begin
   for i := 1 to MAXN do
      stack[ i ] := i;
   root := 0;
   top := 1;
   with tree[ 0 ] do
   begin
      num := 0 ; par := 0 ; ran := MAXN + 1 ; lc := 0 ; rc := 0 ;
   end;
end; { init }

begin
   init();
   repeat
      writeln('please input a value : ');
      read( ins );
      case ins of
	1 : 
	    begin
	       read(val);
	       add(val);
	    end;
	2 : 
	    begin
	       read(val);
	       val := find(val);
	       writeln('find : ' , val );
	       if val <> 0 then
		  del(val);
	    end;
      else ins := 0 ;
      end; { case }
      writeln('root ' , root );
      disp( root );
      readln;
   until ins = 0;
end.