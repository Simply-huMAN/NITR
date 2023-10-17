american(west).
country(nono).
missile(m1).
hostile(nono).

criminal(X) :- american(X), sells_weapons_to_hostile(Y), country(Y), hostile(Y).
sells_weapons_to_hostile(Y) :- american(X), missile(Z), country(Y), hostile(Y), sells(X,Z,Y).

sells(west,m1,nono).