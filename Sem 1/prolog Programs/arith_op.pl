gcd(X,X,X).
gcd(X,Y,G):-X < Y,Y1 is Y - X,gcd(X,Y1,G).
gcd(X,Y,G):-X > Y,gcd(Y,X,G).

fact(0,1).
fact(1,1).
fact(N,F):-N1 is N-1, fact(N1,F1), F is F1 * N.