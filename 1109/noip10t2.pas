program noip2010t2;
const 
   MAXN = 350;
   MAXM = 40;
var
   f     : array[0..MAXN,0..MAXM,0..MAXM,0..MAXM,0..MAXM] of longint;
   cnt   : array[ 1..4 ] of integer;
   w     : array[ 1..MAXN ] of integer;
   n , m : integer;
         
procedure dp(w1 , w2 , w3 , w4 , i : integer );
begin
   writeln( w1 , w2 , w3 , w4 , i );
   if ( i - 1 > 0 ) and ( w1 + 1 <= cnt[ 1 ] ) then begin
      dp(  w1 + 1 , w2 , w3 , w4 , i - 1 );
      if f[ i , w1 , w2 , w3 , w4 ] < f[ i - 1 , w1 + 1 , w2 , w3 , w4 ] + w[ i ]
         then f[ i , w1 , w2 , w3 , w4 ] := f[ i - 1 , w1 + 1 , w2 , w3 , w4 ] + w[ i ] ;
   end;
   if ( i - 2 > 0 ) and ( w2 + 1 <= cnt[ 2 ] ) then begin
      dp(  w1 , w2 + 1 , w3 , w4 , i - 2 );
      if f[ i , w1 , w2 , w3 , w4 ] < f[ i - 1 , w1 + 1 , w2 , w3 , w4 ] + w[ i ]
         then f[ i , w1 , w2 , w3 , w4 ] := f[ i - 2 , w1 , w2 + 1 , w3 , w4 ] + w[ i ] ;
   end;
   if ( i - 3 > 0 ) and ( w3 + 1 <= cnt[ 3 ] ) then begin
      dp(  w1 , w2 , w3 + 1 , w4 , i - 3 );
      if f[ i , w1 , w2 , w3 , w4 ] < f[ i - 1 , w1 + 1 , w2 , w3 , w4 ] + w[ i ]
         then f[ i , w1 , w2 , w3 , w4 ] := f[ i - 3 , w1 , w2 , w3 + 1 , w4 ] + w[ i ] ;
   end;
   if ( i - 4 > 0 ) and ( w4 + 1 <= cnt[ 4 ] ) then begin
      dp(  w1 , w2 , w3 , w4 + 1 , i - 4 );
      if f[ i , w1 , w2 , w3 , w4 ] < f[ i - 1 , w1 + 1 , w2 , w3 , w4 ] + w[ i ]
         then f[ i , w1 , w2 , w3 , w4 ] := f[ i - 4 , w1 , w2 , w3 , w4 + 1 ] + w[ i ] ;
   end;
   
end; { dp }

procedure init();
var
   i , tmp : integer;
begin
   readln( n , m );
   for i := 1 to n do
      read( w[ i ] );
   readln;
   
   for i := 1 to m do
   begin
      read( tmp );
      inc( cnt[ tmp ] );
   end;
   readln;
  
   f[ 1 , cnt[ 1 ] , cnt[ 2 ] , cnt[ 3 ] , cnt[ 4 ] ] := w[ 1 ];
   writeln('finish');
end; { init }


begin
   
   init();

   dp( 0 , 0 , 0 , 0 , n );

   writeln( f[ 0 , 0 , 0 , 0 , n ] );
   
end.