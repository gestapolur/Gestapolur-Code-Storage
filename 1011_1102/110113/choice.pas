program choice;
type //C++ structure
 nodetype=record l,r,w:longint; end;

var n,m,i:longint;
    node:array[-1..201] of nodetype;
    dp:array[-1..300, 0..300] of longint;

procedure dfs(i,j:longint);
var k,max,temp:longint;
begin
 if(dp[i,j]>-1) then exit;
 dfs(node[i].r,j);
 max:=dp[node[i].r,j];
 for k:= 1 to j do
 begin
   dfs(node[i].l,k-1);
   dfs(node[i].r,j-k);
   temp:=dp[node[i].l,k-1]+dp[node[i].r,j-k]+node[i].w;
   if(max < temp) then max:=temp;
 end;
 dp[i,j]:=max;
end;

procedure init;
var a,b,i,j:longint;
begin
 for i:= 0 to n do
  with node[i] do
  begin
   l:=-1;
   r:=-1;
   w:=-1;
  end;

 for i:= 1 to n do
 begin
  readln(a,b);
  node[i].r:=node[a].l;
  node[a].l:=i;
  node[i].w:=b;
 end;


 for i:=-1 to n do
  for j:=0 to m do
   if(i=-1) or (j=0) then dp[i,j]:=0 else dp[i,j]:=-1;
   //edge area

 dfs(node[0].l,m);
end;


begin
   assign(input,'./choice.in');
   assign(output,'./choice2.out');
   reset(input);
   rewrite(output);

 readln(n,m);
 init;

 writeln(dp[node[0].l,m]);
 close(input);
 close(output);
end.
