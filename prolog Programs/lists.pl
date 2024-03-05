member(X,[X|T]).
member(X,[H|Tail]):-member(X,Tail).

add(X,L,[X|L]).

del(X,[X|L],L).
del(X,[H|T],[H|T1]):-del(X,T,T1).

conc([],L1,L1).
conc([X|L1],L2,[X|L3]):-conc(L1,L2,L3).