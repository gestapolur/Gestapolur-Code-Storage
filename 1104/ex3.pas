{i/o}
program ex3;

var
   fin,fout : text;
   x,y	    : longint;
begin
   assign(fout,'input.txt');
   rewrite( fout );
   Randomize;
   x := random(MaxLongInt shr 1 );
   write(fout,x,' ');
   write(x,' ');
   x := random(MaxLongInt shr 1 );
   writeln(fout,x);
   writeln(x);
   close( fout );
   assign( fin , 'input.txt');
   assign( fout , 'output.txt');
   reset( fin );
   rewrite( fout );
   readln(fin , x , y );
   writeln(fout,x + y);
   close( fin );
   close( fout );
end.