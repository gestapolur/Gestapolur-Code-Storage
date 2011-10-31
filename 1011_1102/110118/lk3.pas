program SGU_223;
var
  f:array[0..1,0..1024,0..50] of int64;
  v:array[0..11] of boolean;
  c,s:array[1..1024] of longint;
  n,k,tot,i,m,p,j:longint;
  ans:int64;
   
procedure dfs(step:longint);
begin
  if step=n then
    begin
      inc(tot);
      for i:=1 to n do
        if v[i] then
	begin
            inc(c[tot]);
            s[tot]:=s[tot]+1 shl (i-1);
          end;
      exit;
    end;
  dfs(step+1);
  if not v[step] then
    begin
      v[step+1]:=true;
      dfs(step+1);
      v[step+1]:=false;
    end;
end; { dfs }

begin
   {assign(input,'./lk.in');
   assign(output,'./lk2.out');
   reset(input);
   rewrite(output);}
  readln(n,m);
   writeln(sqr((n+1)/2));
  if (m>sqr((n+1)/2)) then
  begin
     writeln(0);
     {close(input);
     close(output);}
     halt;
  end;
  dfs(0);
   {
   for i:=1 to tot do
      write(c[i],' ');
   writeln();
   for i:=1 to tot do
      write(s[i],' ');
   writeln();
   }
  f[0,1,0]:=1;
  for i:=1 to n do
    begin
    for j:=1 to tot do
      for k:=c[j] to m do
        for p:=1 to tot do
          if (s[p] and s[j]=0) and ((s[j] shl 1) and s[p]=0) and ((s[j] shr 1) and s[p]=0) and (k-c[j]>=c[p]) then
            f[i and 1,j,k]:=f[i and 1,j,k]+f[1-i and 1,p,k-c[j]];
    fillchar(f[1-i and 1],sizeof(f[1-i and 1]),0);
    end;
  ans:=0;
  for i:=1 to tot do
    inc(ans,f[n and 1,i,m]);
  writeln(ans);
   {close( input );
   close( output );}
end.
