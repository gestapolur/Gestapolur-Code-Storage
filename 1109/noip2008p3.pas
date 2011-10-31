program noip2008p3;
const
   MAXN = 51;
var 
   f     : array[ 1..MAXN , 1..MAXN , 1..MAXN ] of longint;
   w     : array[ 1..MAXN , 1..MAXN ] of longint;
   n , m : longint;

procedure init();
var
   i , j : integer;
begin 
   readln( n , m );
   for i := 1 to n do
      for j := 1 to m do
         read( w[ i , j ] );
   for i := 1 to n do
      for j := 1 to n do
      begin
      end;
   
end; { init }

procedure dp();
var
   i , j , k : integer;
begin
   for k := 2 to m do
      for i := 1 to n - 1 do
         for j := i + 1 to n do
         begin
            if ( i > 1 ) and ( j - 1 <> i )
               and ( f[ i , j , k ] < f[ i - 1 , j - 1 , k - 1 ] + w[ j - 1 , k ] + w[ j , k ] + w[ i - 1 , k ] + w[ i , k ] )
               then f[ i , j , k ] := f[ i - 1 , j - 1 , k - 1 ] + w[ j - 1 , k ] + w[ j , k ] + w[ i - 1 , k ] + w[ i , k ] ;
            if ( f[ i , j , k ] < f[ i , j , k - 1 ] + w[ j , k ] + w[ i , k ] )
               then f[ i , j , k ] := f[ i - 1 , j , k - 1 ] + w[ j , k ] + w[ i , k ];
            if ( j - 1 <> i ) and 
               ( f[ i , j , k ] < f[ i , j - 1 , k - 1 ] + w[ i , k ] + w[ j - 1 , k ] + w[ j , k ] )
               then f[ i , j , k ] := f[ i , j - 1 , k - 1 ] + w[ i , k ] + w[ j - 1 , k ] + w[ j , k ] ;
            if ( i > 1 )   
               and ( f[ i , j , k ] < f[ i - 1 , j , k - 1 ] + w[ i , k ] + w[ i - 1 , k ] + w[ j , k ] )
               then f[ i , j , k ] := f[ i - 1 , j , k - 1 ] + w[ i , k ] + w[ i - 1 , k ] + w[ j , k ];
         end;
end; { dp }

function max( a , b : longint ) : longint;
begin
   if( a > b ) then exit( a )
   else exit( b );
end;

procedure output();
begin
   f[ n , n , m ] := max( f[ n - 1 , n , m - 1 ] , f[ n , n - 1 , m - 1 ] ) + w[ n , n ];
   writeln( f[ n , n , m ] );
end; { output }

begin

   init();

   dp();

   output();
   
end.
