program substr;
const
  fin='n.in';
  fout='substr.ans';
var
  tr:array[0..524287,#0..#127]of longint;
  s:array[0..1024]of char;
  tt,t,n,i,j,p:longint;
   
procedure insert(x,ad:longint);
var
  r,i:longint;
  c:char;
begin
  for i:=x to n do
  begin
 
     c:=s[i];r:=tr[ad,c];{r whether it visted }
     if r<=t shl 19 then{ not visited }
     begin
	inc(p);tr[ad,c]:=p or t shl 19;{ mark visted }
	ad:=p;{ add is the number of substring in current end c}
     end
     else{ visited yet , start from that point visted , the num of last point }
     begin
	ad:=r and ( 1 shl 19 - 1 );{ take out marked in line 23 }
     end;
  end;
end; { insert }

begin
   //   assign(input,fin);reset(input);
   //   assign(output,fout);rewrite(output);
   readln(tt);
   // readln;
   fillchar(tr,sizeof(tr),0);
  for t:=1 to tt do
  begin
    // writeln('Case #',t);
    n:=0;
    while not eoln do
    begin
      inc(n);read(s[n]);
    end;
    p:=1;
    for i:=1 to n do
    insert(i,1);
     writeln(p-1);
     // if t<tt then writeln;
     readln;
  end;
   // close(input);close(output);
end.
