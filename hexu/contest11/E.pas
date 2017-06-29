const mo=1000000007;
type arr=array[0..18,0..18]of int64;
var
   n,k,i,j,p,len,ii:longint;
   times,m:int64;
   x,y,h:array[0..105]of int64;
   base,ans,c:arr;
procedure sort(l,r: longint);
var i,j: longint;
    xx,yy:int64; 
begin
  i:=l;j:=r;xx:=y[random(R-L+1)+L];
  repeat
    while y[i]<xx do inc(i);
    while xx<y[j] do dec(j);
    if not(i>j) then begin yy:=y[i];y[i]:=y[j];y[j]:=yy; yy:=x[i];x[i]:=x[j];x[j]:=yy; yy:=h[i];h[i]:=h[j];h[j]:=yy; inc(i);j:=j-1; end;
  until i>j;
  if l<j then sort(l,j);
  if i<r then sort(i,r);
end;
function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;
function cheng(a,b:arr):arr;
var i,j,kk:longint;
begin
  fillchar(c,sizeof(c),0);
  for i:=1 to len do
    for j:=1 to len do
      for kk:=1 to len do c[i,j]:=(c[i,j]+a[i,kk]*b[kk,j]) mod mo;
  exit(c);
end;
begin
  readln(n,m);
  for i:=1 to n do begin readln(x[i],y[i],h[i]); inc(h[i]); end;
  sort(1,n);
  ans[1,1]:=1;
  for ii:=1 to n do
  begin
    //writeln(h[ii]);
    fillchar(base,sizeof(base),0);
    base[1,1]:=1; base[1,2]:=1;
    for i:=2 to h[ii]-1 do begin base[i,i-1]:=1; base[i,i]:=1; base[i,i+1]:=1; end;
    i:=h[ii];  base[i,i]:=1; base[i,i-1]:=1;   len:=h[ii];
    if (m>=x[ii])and(m<=y[ii]) then times:=m-x[ii] else times:=y[ii]-x[ii];
    while times>0 do
    begin
      if times and 1=1 then ans:=cheng(base,ans);
      base:=cheng(base,base);
      times:=times shr 1;
    end;
  end;
  writeln(ans[1,1]);
end.
