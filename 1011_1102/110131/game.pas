program Game;

const
	inf	=	'game.in';
	ouf	=	'game.out';

type
	Tmaze	=	array [ 1 .. 4 , 1 .. 4 ] of byte;

var
	hash	:	array [ 0 .. 65535 ] of longint;
	queue	:	array [ 1 .. 10000 ] of longint;
	step	:	array [ 1 .. 10000 ] of longint;
	num	:	array [ 1 .. 10000 ] of longint;
	start	:	Tmaze;
	min , S	:	longint;
	h , t	:	longint;

procedure init;
    var
	i , j	:	longint;
	ch	:	char;
    begin
	while seekeoln ( input ) do readln;
	for i := 1 to 4 do
	begin
		for j := 1 to 4 do
		begin
			read ( ch );
			start [ i , j ] := ord ( ch ) - ord ( 'A' );
		end;
		readln;
	end;
    end;

function code ( var maze : Tmaze ) : longint;
    var
	i , j , S	:	longint;
    begin
	S := 0;
	for i := 1 to 4 do
		for j := 1 to 4 do S := S * 2 + maze [ i , j ];
	code := S;
    end;

function decode ( num : longint ) : Tmaze;
    var
	i , j	:	longint;
	tmp	:	Tmaze;
    begin
	for i := 4 downto 1 do
		for j := 4 downto 1 do
		begin
			tmp [ i , j ] := num and 1;
			num := num shr 1;
		end;
	decode := tmp;
    end;

procedure swap ( var a , b : byte );
    var
	c	:	longint;
    begin
	c := a ; a := b ; b := c;
    end;

procedure BFS;
    var
	i , j	:	longint;
	ii , kk : longint;
	v	:	longint;
	tmp	:	Tmaze;
    begin
	fillchar ( hash , sizeof ( hash ) , 0 );
	fillchar ( step , sizeof ( step ) , 0 );
	fillchar ( num , sizeof ( num ) , 0 );
	h := 0 ; t := 0;

	for i := 1 to 3 do
		for j := 1 to 3 do
		begin
			fillchar ( tmp , sizeof ( tmp ) , 0 );
			tmp [ i , j ] := 1 ;
			tmp [ i + 1 , j ] := 1;
			tmp [ i , j + 1 ] := 1;
			tmp [ i + 1 , j + 1 ] := 1;
			inc ( t ) ; queue [ t ] := code ( tmp );
			//writeln(i,' ',j,' ',queue[ t ],' ');
			hash [ queue [ t ] ] := t;
			step [ t ] := 0;
			num [ t ] := 1;
		end;
	
	repeat
		inc ( h ) ; tmp := decode ( queue [ h ] );
		writeln(h);
		for ii := 1 to 4 do
			begin			
				for kk := 1 to 4 do
					write(tmp[ ii , kk ]);
				writeln();
			end;	
		for i := 1 to 4 do
			for j := 1 to 3 do
			begin
				swap ( tmp [ i , j ] , tmp [ i , j + 1 ] );
				v := code ( tmp );
				
				if ( hash [ v ] = 0 ) or ( step [ h ] + 1 = step [ hash [ v ] ] ) then
				begin
					if hash [ v ] = 0 then
					begin
						inc ( t ) ; queue [ t ] := v;
						hash [ v ] := t;
						step [ t ] := step [ h ] + 1;
					end;
					inc ( num [ hash [ v ] ] , num [ h ] );
				end;
	
				swap ( tmp [ i , j ] , tmp [ i , j + 1 ] );				
			end;

		for i := 1 to 3 do
			for j := 1 to 4 do
			begin
				swap ( tmp [ i , j ] , tmp [ i + 1 , j ] );
				v := code ( tmp );
				
				if ( hash [ v ] = 0 ) or ( step [ h ] + 1 = step [ hash [ v ] ] ) then
				begin
					if hash [ v ] = 0 then
					begin
						inc ( t ) ; queue [ t ] := v;
						hash [ v ] := t;
						step [ t ] := step [ h ] + 1;
					end;
					inc ( num [ hash [ v ] ] , num [ h ] );
				end;

				swap ( tmp [ i , j ] , tmp [ i + 1 , j ] );				
			end;
	until h = t;
    end;

procedure Main;
    var
	ch	:	longint;
	i , j	:	longint;
	ii , kk : longint;
	tmpS	:	longint;
	tmp	:	Tmaze;
    begin
	min := maxlongint;
	for ch := 0 to 3 do
	begin
		for i := 1 to 4 do
		for j := 1 to 4 do
			if start [ i , j ] = ch then tmp [ i , j ] := 1 else tmp [ i , j ] := 0;
		tmpS := hash [ code ( tmp ) ];
		writeln(tmpS,' ',code(tmp));
		for ii := 1 to 4 do
			begin
				for kk := 1 to 4 do
						write(tmp[ii , kk]);
				writeln();
			end;
		if step [ tmpS ] <= min then
		begin
			if step [ tmpS ] < min then S := 0;
			S := S + num [ tmpS ];
			min := step [ tmpS ];
		end;
	end;
    end;

procedure out;
    begin
	writeln ( min , ' ' , S );
    end;

procedure openFile;
    begin
	assign ( input , inf ) ; reset ( input );
	assign ( output , ouf ) ; rewrite ( output );
    end;

procedure closeFile;
    begin
	close ( input );
	close ( output );
    end;

var
	data	:	longint;

begin
	openFile;

	BFS;

	readln ( data );
	for data := 1 to data do
	begin
		init;
		Main;
		out;
	end;

	closeFile;
end.
