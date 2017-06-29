var i,j,n,m,z,t,flag,k,x,y,a,b,c,d:longint;
    f:array[0..55]of int64;
begin
  readln(k,x,n,m);
  for i:=0 to n div 2 do
    for j:=0 to m div 2 do
      for a:=0 to 1 do
        for b:=0 to 1 do
          for c:=0 to 1 do
            for d:=0 to 1 do
  begin
         if (i*2+a+b>n)or(j*2+c+d>m) then continue;
         f[1]:= i; f[2]:= j; t:= 0;
         if (b<>0)and(c<>0) then inc(t);
         for z:=3 to k do
         begin
             f[z]:=f[z-1]+f[z-2];
             if (t<>0) then begin inc(f[z]); dec(t); end;
             if (z>3)and(d<>0)and(a<>0)and(z mod 2=0) then inc(f[z]);
             if (z>3)and(d<>0)and(c<>0)and(z mod 2=1) then inc(f[z]);
         end;
         if (f[k]=x) then
         begin
             if (a<>0) then write('C');
             for Z:=0 to i-1 do write('AC');  //writeln;
             for z:=0 to n-i*2-a-b-1 do write('Q');
             if (b<>0) then write('A');  writeln;

             if (c<>0) then begin write('C'); end;
             for z:=0 to j-1 do write('AC');
             for z:=0 to m-j*2-c-d-1 do write('Q');
             if (d<>0) then write('A'); writeln;
             halt;
         end;
  end;
  writeln('Happy new year!');
end.
