const maxn=10000; inf=maxlongint div 3;
var x,y,dis,vis:array[0..maxn+2]of longint;
    n,m,k,i,j,kk,xx,yy,minn:longint;
    ok:boolean;
function min(a,b:longint):longint;
begin
  if a>b then exit(b) else exit(a);
end;
begin
   readln(n,m,k);
   for i:=1 to k do begin readln(x[i],y[i]); dis[i]:=maxlongint div 3; if (x[i]=n)and(y[i]=m) then ok:=true; end;
   if ok then begin inc(k); x[k]:=n; y[k]:=m; dis[k]:=inf; end
         else begin inc(k); x[k]:=n+1; y[k]:=m+1; dis[k]:=inf; end;
   dis[0]:=0; x[0]:=1; y[0]:=1;
   for i:=0 to k do
   begin
     minn:=k;
     for j:=0 to k-1 do if (vis[j]<>1) and (dis[j]<dis[minn]) then minn:=j;
     vis[minn]:=1;
     for j:=0 to k do if vis[j]<>-1 then begin
                                           xx:=abs(x[j]-x[minn]); yy:=abs(y[j]-y[minn]);
                                           if xx+yy<=1 then dis[j]:=dis[minn] else if (xx<=2) or (yy<=2) then dis[j]:=min(dis[j],dis[minn]+1);
                                         end;
   end;
   if dis[k]=inf then writeln('-1') else writeln(dis[k]);


end.
