uses math;
const
        nmax    =       51;
        modul   =       1000000007;
var
        n,k,fron,righ:longint;
        qx,qy,qz:array[0..nmax*nmax*2] of longint;
        F,d:array[0..nmax,0..nmax,0..1] of longint;
        c:Array[0..nmax,0..nmax] of int64;
        sl:array[1..2] of longint;
procedure push(u,v,t:longint);
begin
        inc(righ);qx[righ]:=u;qy[righ]:=v;qz[righ]:=t;
end;
procedure pop(var u,v,t:longint);
begin
        u:=qx[fron];v:=qy[fron];t:=qz[fron];inc(fron);
end;
procedure process;
var i,j,u,v,t,uu,vv:longint;
begin
        read(n,k);k:=k div 50;
        for i:=1 to n do
          begin
            read(u);
            u:=u div 50;inc(sl[u]);
          end;
        c[0][0]:=1;
        for i:=1 to n do for j:=-0 to i do if (j=0)or(j=i) then c[i][j]:=1
        else c[i][j]:=(c[i-1][j]+c[i-1][j-1])mod modul;
        F[sl[1],sl[2],0]:=1;d[sl[1],sl[2],0]:=1;
        fron:=1;righ:=0;
        push(sl[1],sl[2],0);
        while fron<=righ do
          begin
            pop(u,v,t);
            if t=0 then
              begin
                for i:=0 to u do for j:=0 to v do if (i+j>0)and(i+2*j<=k) then
                  begin
                    uu:=u-i;vv:=v-j;
                    if (d[uu][vv][1]=0)or(d[uu][vv][1]=d[u][v][t]+1)then
                     begin
                      if d[uu][vv][1]=0 then
                        begin
                          d[uu][vv][1]:=d[u][v][t]+1;
                          push(uu,vv,1);
                        end;
                      F[uu][vv][1]:=(F[uu][vv][1]+F[u][v][t]*((c[u][i]*c[v][j])mod modul))mod modul;
                     end;
                  end;
              end
            else
              begin
                for i:=0 to sl[1]-u do for j:=0 to sl[2]-v do if (i+j>0)and(i+2*j<=k) then
                  begin
                   uu:=u+i;vv:=v+j;
                   if (d[uu][vv][0]=0)or(d[uu][vv][0]=d[u][v][t]+1) then
                     begin
                       if d[uu][vv][0]=0 then
                         begin
                           d[uu][vv][0]:=d[u][v][t]+1;
                           push(uu,vv,0);
                         end;
                       F[uu][vv][0]:=(F[uu][vv][0]+F[u][v][t]*((c[sl[1]-u][i]*c[sl[2]-v][j])mod modul))mod modul;
                     end;
                  end;
              end;
          end;
        if d[0][0][1]=0 then
         begin
           writeln(-1);writeln(0);
         end
        else
          begin
            writeln(d[0][0][1]-1);
            writeln(F[0][0][1]);
          end;
end;
begin
    //    assign(input,'');reset(input);
        assign(output,'');rewrite(output);
          process;
      //  close(input);
     //   close(output);
end.
