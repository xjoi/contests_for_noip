var
  n,m,k,i,j,x,y:longint;
  a,b,l,r,d,num,q,vis:array[0..100005]of int64;
begin
  readln(n,m,k);
  fillchar(vis,sizeof(vis),0);
  fillchar(num,sizeof(num),0);
  fillchar(q,sizeof(q),0);
  for i:=1 to n do read(num[i]);
  for i:=1 to m do begin readln(L[i],r[i],d[i]); inc(r[i]); end;
  for i:=1 to k do
  begin readln(x,y); inc(vis[x]); dec(vis[y+1]);  end;
  for i:=1 to m do vis[i]:=vis[i]+vis[i-1];
  for i:=1 to m do inc(q[l[i]],vis[i]*d[i]);
  for i:=1 to m do dec(q[r[i]],vis[i]*d[i]);
  for i:=1 to n do q[i]:=q[i-1]+q[i];
  for i:=1 to n do write(q[i]+num[i],' ');writeln;
end.
