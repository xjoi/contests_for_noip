type trec=record
       sum,ans:int64;
       l,r,cnt,lson,rson,mid:longint;
     end;
var t:array[0..6000000]of trec;
    w:longint;
function new(l,r:longint):longint;
begin
  inc(w);
  t[w].l:=l;
  t[w].r:=r;
  t[w].mid:=l+((r-int64(l)) shr 1);
  t[w].lson:=0;
  t[w].rson:=0;
  t[w].sum:=0;
  t[w].ans:=0;
  exit(w);
end;
procedure updata(s,x,d:longint);
begin
  if t[s].l=t[s].r then
  begin
    inc(t[s].cnt,d);
    inc(t[s].sum,d*int64(x));
    exit;
  end;
  if x<=t[s].mid then
  begin
    if t[s].lson=0 then t[s].lson:=new(t[s].l,t[s].mid);
    updata(t[s].lson,x,d);
  end
  else
  begin
    if t[s].rson=0 then t[s].rson:=new(t[s].mid+1,t[s].r);
    updata(t[s].rson,x,d);
  end;
  t[s].sum:=t[t[s].lson].sum+t[t[s].rson].sum;
  t[s].cnt:=t[t[s].lson].cnt+t[t[s].rson].cnt;
  t[s].ans:=t[t[s].lson].ans+t[t[s].rson].ans+
  (t[t[s].lson].cnt*t[t[s].rson].sum)-(t[t[s].rson].cnt*t[t[s].lson].sum);
end;
function calc(s,l,r,cntleft:longint;sumleft:int64;
              var cnt:longint; var sum:int64):int64;
  var cnt1:longint;
      sum1,res:int64;
begin
  if (t[s].l>=l)and(t[s].r<=r) then
  begin
    cnt:=t[s].cnt;
    sum:=t[s].sum;
    exit(t[s].ans+(cntleft*sum)-(cnt*sumleft));
  end;
  res:=0;
  cnt:=0;
  sum:=0;
  if (t[s].lson>0)and(l<=t[t[s].lson].r) then
  begin
    inc(res,calc(t[s].lson,l,r,cntleft,sumleft,cnt1,sum1));
    inc(cnt,cnt1);
    inc(sum,sum1);
  end;
  if (t[s].rson>0)and(r>=t[t[s].rson].l) then
  begin
    inc(res,calc(t[s].rson,l,r,cntleft+cnt,sumleft+sum,cnt1,sum1));
    inc(cnt,cnt1);
    inc(sum,sum1);
  end;
  exit(res);
end;
var n,m,i,aaa,l,r,tt:longint;
    bbb:int64;
    x:array[0..100000]of longint;
begin
  w:=0;
  new(-1500000000,1500000000);
  readln(n);
  for i:=1 to n do
  begin
    read(x[i]);
    updata(1,x[i],1);
  end;
  readln(m);
  for i:=1 to m do
  begin
    readln(tt,l,r);
    if tt=1 then
    begin
      updata(1,x[l],-1);
      inc(x[l],r);
      updata(1,x[l],1);
    end
    else writeln(calc(1,l,r,0,0,aaa,bbb));
  end;
end.
