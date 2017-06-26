var
   n,i,j,k,ans,kk:longint;
   map:array[0..55,0..55]of longint;
   ok:boolean;
begin
   readln(n);
   for i:=1 to n do
     for j:=1 to n do read(map[i,j]);
   for i:=1 to n do
     for j:=1 to n do
     if map[i,j]<>1 then
     begin
       ok:=false;
       for k:=1 to n do
       begin
         for kk:=1 to n do
         if map[i,k]+map[kk,j]=map[i,j] then begin ok:=true; break; end;
         if ok then break;
       end;
       if not ok then begin writeln('No'); halt; end;
     end;
   writeln('Yes');
end.
