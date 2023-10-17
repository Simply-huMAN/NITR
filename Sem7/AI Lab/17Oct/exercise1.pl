animal(lion).
animal(tiger).
animal(cow).
carnivore(lion).
carnivore(tiger).

check_carnivore(X):- animal(X),carnivore(X).
