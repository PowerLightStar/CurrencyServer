R=lambda:map(int,input().split())
s=sorted
t,=R()
exec(t*'R();_,a=zip(*s(zip(R(),range(7**6))));_,a=zip(*s(zip(a,s(R()))));print(*a);')