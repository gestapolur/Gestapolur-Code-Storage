program Zoo;

{$S-,R-,Q-}
{$inline on}

const
	inf	=	'zoo.in';
	ouf	=	'zoo.out';
	MaxN	=	100000;
	MaxM	=	50000;

type
	Tseg	=	record
				L , R , k , idx	:	longint;
			end;

var
	seg	:	array [ 1 .. MaxM ] of Tseg;
	num	:	array [ 1 .. MaxN ] of longint;
	pos	:	array [ 1 .. MaxN ] of longint;
	key	:	array [ 1 .. MaxN ] of longint;
	sum	:	array [ 1 .. MaxN shl 3 ] of longint;
	res	:	array [ 1 .. MaxM ] of longint;
	N , M	:	longint;
	tot	:	longint;

procedure init;
    var
	i	:	longint;
    begin
	assign ( input , inf ) ; reset ( input );
	readln ( N , M );
	for i := 1 to N do read ( num [ i ] );
	for i := 1 to M do
	with seg [ i ] do
	begin
		readln ( L , R , k );
		idx := i;
	end;
	close ( input );
    end;

procedure sort ( L , R : longint );
    var
	i , j , cmp	:	longint;

	procedure swap ( var a , b : longint ); inline;
	var
		c	:	longint;
	begin
		c := a ; a := b ; b := c;
	end;

    begin
	if L >= R then exit;
	i := L ; j := R ; cmp := key [ ( L + R ) shr 1 ];
	repeat
		while key [ i ] < cmp do inc ( i );
		while key [ j ] > cmp do dec ( j );
		if i <= j then
		begin
			swap ( key [ i ] , key [ j ] );
			inc ( i ) ; dec ( j );
		end;
	until i > j;
	sort ( L , j ) ; sort ( i , R );
    end;

procedure sortS ( L , R : longint );
    var
	i , j , cmp	:	longint;

	procedure swap ( var a , b : Tseg ); inline;
	var
		c	:	Tseg;
	begin
		c := a ; a := b ; b := c;
	end;

    begin
	if L >= R then exit;
	i := L ; j := R ; cmp := seg [ ( L + R ) shr 1 ] . L;
	repeat
		while seg [ i ] . L < cmp do inc ( i );
		while seg [ j ] . L > cmp do dec ( j );
		if i <= j then
		begin
			swap ( seg [ i ] , seg [ j ] );
			inc ( i ) ; dec ( j );
		end;
	until i > j;
	sortS ( L , j ) ; sortS ( i , R );
    end;

function find ( num : longint ) : longint; inline;
    var
	L , R , mid	:	longint;
    begin
	L := 1 ; R := tot;
	repeat
		mid := ( L + R ) shr 1;
		if key [ mid ] = num then begin find := mid ; exit ; end else
		if key [ mid ] > num then R := mid - 1 else L := mid + 1;
	until L > R;
    end;

procedure prepare;
    var
	i	:	longint;
    begin
	sortS ( 1 , M );
	for i := 1 to N do key [ i ] := num [ i ];
	sort ( 1 , N );
	tot := 0;
	for i := 1 to N do
	if ( i = 1 ) or ( key [ i ] <> key [ i - 1 ] ) then
	begin
		inc ( tot ) ; key [ tot ] := key [ i ];
	end;
	for i := 1 to N do
		pos [ i ] := find ( num [ i ] );
    end;

procedure insert ( cnt , L , R , p , delta : longint ); inline;
    var
	mid	:	longint;
    begin
	if ( L > p ) or ( R < p ) then exit;
	inc ( sum [ cnt ] , delta );
	if L = R then exit;

	mid := ( L + R ) shr 1;
	insert ( cnt shl 1 , L , mid , p , delta );
	insert ( cnt shl 1 + 1 , mid + 1 , R , p , delta );
    end;

function query ( cnt : longint ; L , R , k : longint ) : longint; inline;
    var
	mid	:	longint;
    begin
	if L = R then begin query := key [ L ] ; exit ; end;

	mid := ( L + R ) shr 1;
	if sum [ cnt shl 1 ] >= k then
		query := query ( cnt shl 1 , L , mid , k )
	else
		query := query ( cnt shl 1 + 1 , mid + 1 , R , k - sum [ cnt shl 1 ] );
    end;

function min ( a , b : longint ) : longint; inline;
    begin
	if a < b then min := a else min := b;
    end;

function max ( a , b : longint ) : longint; inline;
    begin
	if a > b then max := a else max := b;
    end;

procedure Main;
    var
	i , j	:	longint;
    begin
	fillchar ( sum , sizeof ( sum ) , 0 );
	for i := 1 to M do
	begin
		if i > 1 then
		begin
			for j := seg [ i - 1 ] . L to min ( seg [ i - 1 ] . R , seg [ i ] . L - 1 ) do
				insert ( 1 , 1 , tot , pos [ j ] , -1 );
			for j := max ( seg [ i ] . L , seg [ i - 1 ] . R + 1 ) to seg [ i ] . R do
				insert ( 1 , 1 , tot , pos [ j ] , 1 );
		end else
			for j := seg [ i ] . L to seg [ i ] . R do
				insert ( 1 , 1 , tot , pos [ j ] , 1 );
		res [ seg [ i ] . idx ] := query ( 1 , 1 , tot , seg [ i ] . k );
	end;
    end;

procedure out;
    var
	i	:	longint;
    begin
	assign ( output , ouf ) ; rewrite ( output );
	for i := 1 to M do writeln ( res [ i ] );
	close ( output );
    end;

begin
	init;
	prepare;
	Main;
	out;
end.

