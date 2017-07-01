type rec=record
       l,r,x,y:longint;
     end;
var h:array[0..800010]of rec;
    a,b,x,y,pos:array[0..200010]of longint;
    vis:array[0..200010]of boolean;
    i,n,m,k,t:longint;
    c:char;
procedure qsort(l,r:longint);
  var i,j,p,mid:longint;
begin
  i:=l;
  j:=r;
  mid:=a[random(r-l+1)+l];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
    if i<=j then
    begin
      p:=a[i]; a[i]:=a[j]; a[j]:=p;
      p:=b[i]; b[i]:=b[j]; b[j]:=p;
      inc(i); dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if l<j then qsort(l,j);
end;
procedure build(x,l,r:longint);
  var mid:longint;
begin
  h[x].l:=l;
  h[x].r:=r;
  h[x].x:=0;
  h[x].y:=k+1;
  mid:=(l+r) div 2;
  if l<r then
  begin
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
  end
  else pos[l]:=x;
end;
function findy(x:longint):longint;
  var t:longint;
begin
  t:=maxlongint;
  while x>0 do
  begin
    if h[x].y<t then t:=h[x].y;
    x:=x div 2;
  end;
  exit(t);
end;
function findx(x:longint):longint;
  var t:longint;
begin
  t:=0;
  while x>0 do
  begin
    if h[x].x>t then t:=h[x].x;
    x:=x div 2;
  end;
  exit(t);
end;
procedure workx(x,l,r,k:longint);
  var mid:longint;
begin
  if (h[x].l=l) and (h[x].r=r) then
  begin
    if k>h[x].x then h[x].x:=k;
    exit;
  end;
  mid:=(h[x].l+h[x].r) div 2;
  if r<=mid then workx(x*2,l,r,k)
  else if l>=mid+1 then workx(x*2+1,l,r,k)
  else
  begin
    workx(x*2,l,mid,k);
    workx(x*2+1,mid+1,r,k);
  end;
end;
procedure worky(x,l,r,k:longint);
  var mid:longint;
begin
  if (h[x].l=l) and (h[x].r=r) then
  begin
    if k<h[x].y then h[x].y:=k;
    exit;
  end;
  mid:=(h[x].l+h[x].r) div 2;
  if r<=mid then worky(x*2,l,r,k)
  else if l>=mid+1 then worky(x*2+1,l,r,k)
  else
  begin
    worky(x*2,l,mid,k);
    worky(x*2+1,mid+1,r,k);
  end;
end;
begin
  randomize;
  readln(n,m);
  for i:=1 to m do
  begin
    read(x[i],k,c,c);
    a[i]:=x[i];
    if c='U' then y[i]:=0 else y[i]:=1;
    b[i]:=i;
  end;
  qsort(1,m);
  for i:=1 to m do
  begin
    if a[i]>a[i-1] then inc(t);
    x[b[i]]:=t;
  end;
  t:=0; 
  for i:=1 to m do
  if a[i]>a[i-1] then
  begin
    inc(t);
    a[t]:=a[i];
  end;
  k:=t;
  a[0]:=0;
  a[k+1]:=n+1;
  build(1,1,k);
  fillchar(vis,sizeof(vis),false);
  for i:=1 to m do
  begin
    if vis[x[i]] then writeln('0')
    else if y[i]=0 then
    begin
      t:=findy(pos[x[i]]);
      writeln(a[t]-a[x[i]]);
      if x[i]+1<=t-1 then workx(1,x[i]+1,t-1,x[i]);
    end
    else
    begin
      t:=findx(pos[x[i]]);
      writeln(a[x[i]]-a[t]);
      if t+1<=x[i]-1 then worky(1,t+1,x[i]-1,x[i]);
    end;
    vis[x[i]]:=true;
  end;
end.
