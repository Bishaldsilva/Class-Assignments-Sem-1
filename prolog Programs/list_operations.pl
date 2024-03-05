member(X, [X|L]).
member(X, [Head|Tail]):-member(X, Tail).

conc([], L, L).
conc([X|L1], L2, [X|L3]):-conc(L1, L2, L3).

del(X, [X|L], L).
del(X, [Y|L], [Y|L1]):- del(X, L, L1).

insert(X, L, BL):- del(X, BL, L).

sublist(S, L):- conc(L1, L2, L), conc(S, L3, L2).

permute([], []).
permute([X|L], P):-permute(L, L1), insert(X, L1, P).

len([], 0).
len([H|T],L):-len(T,L1),L is L1 + 1.

rev([],[]).
rev([X|L],R) :- rev(L, R1),conc(R1, [X], R).

palindrome(List) :- rev(List,List).

sum([],0).
sum([H|T],S) :- sum(T, S1), S is S1 + H.

union([], L, L).
union([X|L], L2, U) :- member(X, L2), union(L, L2, U).
union([X|L], L2, [X|U]) :-  \+ member(X, L2), union(L, L2, U).

intersection([], L, []).
intersection([X|L], L2, [X|I]) :- member(X, L2), intersection(L, L2, I).
intersection([X|L], L2, I) :- \+ member(X, L2), intersection(L, L2, I).

qsort([],[]).
qsort([H|T], Sortlist) :-
    partition(H, T, Less, Greater),
    qsort(Less, Sortedless),
    qsort(Greater, Sortedgreater),
    conc(Sortedless, [H|Sortedgreater], Sortlist).

partition(_, [], [], []).
partition(P, [H|T], [H|Less], Greater):- H =< P, partition(P, T, Less, Greater).
partition(P, [H|T], Less, [H|Greater]):- H > P, partition(P, T, Less, Greater).