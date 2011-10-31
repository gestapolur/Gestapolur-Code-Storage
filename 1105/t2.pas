program lesson_6_7_example;
const
  hl:array[0..20] of longint=(1,2,4,8,16,32,
                        64,128,256,512,1024,
                 2048,4096,8192,16384,32768,
          65536,131072,262144,524288,1048576);
  { hl[i]:=2^i;}
var
  i,j,v,n,sn,s1,q:longint;
  s:array[0..1048575] of string;
  w,a,b:array[0..1048575] of longint;
  c,f:array[0..20,0..104857] of longint;
function place(k,h:longint):boolean;
  begin
    place:=true;
    s[h+1]:='';
    w[h+1]:=0;
    repeat
      s[h+1]:=chr(48+k mod 2)+s[h+1];
      if s[h+1][1]='1' then inc(w[h+1]);
      k:=k div 2;
    until i = 0;
  end;
function h(n:longint):longint;
  var
    i:longint;
  begin
    h:=0;
    for i:=1 to hl[n]-1 do
      if place(i,h) then begin
        h:=h+1;
        a[i]:=h;
        b[h]:=i;
        inc(c[w[h],0]);
        c[w[h],c[w[h],0]]:=h;
      end;
  end;
begin
  readln(n);
  s[0]:='';
  for i:=1 to n do s[0]:=s[0]+'0';
  w[0]:=0;
  sn:=h(n);
  f[0,0]:=1;
  for i:=1 to n do
    for j:=1 to c[i,0] do
      for v:=1 to length(s[c[i,j]]) do begin
        s1:=b[c[i,j]] xor hl[v-1];
        q:=a[s1];
        if w[q]=i-1 then
          f[i,b[c[i,j]]]:=f[i,b[j]]+f[i-1,b[q]];
      end;
  writeln(f[n,sn]);
end.
