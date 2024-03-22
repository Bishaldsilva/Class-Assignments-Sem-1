parent(maegor,visenya).
parent(maegor,aegon_I).
parent(aenys_I,aegon_I).
parent(aenys_I,rhaenys).
parent(jaehaerys_I,aenys_I).
parent(jaehaerys_I,alyssa).
parent(alysanne,aenys_I).
parent(alysanne,alyssa).
parent(aemon,jaehaerys_I).
parent(aemon,alysanne).
parent(daella,jaehaerys_I).
parent(daella,alysanne).
parent(baelon,jaehaerys_I).
parent(baelon,alysanne).
parent(alyssa_t,jaehaerys_I).
parent(alyssa_t,alysanne).
parent(rhaenys_II,jocelyn).
parent(rhaenys_II,aemon).
parent(aemma,rodrik).
parent(aemma,daella).
parent(viserys_I,baelon).
parent(viserys_I,alyssa_t).
parent(daemon,baelon).
parent(daemon,alyssa_t).
parent(rhaenyra,aemma).
parent(rhaenyra,viserys_I).
parent(aegon_II,viserys_I).
parent(aegon_II,alicent).

male(aegon_I).
male(maegor).
male(aenys_I).
male(jaehaerys_I).
male(aemon).
male(rodrik).
male(baelon).
male(viserys_I).
male(daemon).
male(aegon_II).

female(visenya).
female(rhaenys).
female(alyssa).
female(alysanne).
female(jocelyn).
female(daella).
female(alyssa_t).
female(rhaenys_II).
female(aemma).
female(alicent).
female(rhaenyra).

grandfather(C,G):-parent(C,X),parent(X,G),male(G).
grandmother(C,G):-parent(C,X),parent(X,G),female(G).

/* recursion */
ancestor(C,T):-parent(C,T).

ancestor(C,T):-parent(C,Y),ancestor(Y,T).