(define (domain trucking)

(:requirements :strips :negative-preconditions :equality)

(:predicates
    (CITY ?x)
    (TRUCK ?x)
    (PACKAGE ?x)
    (is-empty ?x)
    (at-city ?x ?y)
    (carry ?x ?y)
)

(:action load
    :parameters (?x ?y ?z)
    :precondition (and 
        (PACKAGE ?x) (TRUCK ?y) (CITY ?z)
        (at-city ?x ?z)
        (at-city ?y ?z)
        (is-empty ?y)
    )
    :effect (and
        (not (is-empty ?y))
        (carry ?y ?x)
        ; (not (at-city ?x ?z))
    )
)
(:action unload
    :parameters (?x ?y ?z)
    :precondition (and
        (PACKAGE ?x) (TRUCK ?y) (CITY ?z)
        ; (not (at-city ?x ?z))
        (at-city ?y ?z)
        (not (is-empty ?y))
        (carry ?y ?x)
    )
    :effect (and
        (is-empty ?y)
        (at-city ?x ?z)
    )
)
(:action drive
    :parameters (?x ?y ?z ?p1)
    :precondition (and
        (CITY ?x) (CITY ?y) (TRUCK ?z) (PACKAGE ?p1)
        (at-city ?z ?x)
        (carry ?z ?p1)
        (at-city ?p1 ?x)
        (not (at-city ?p1 ?y))
    )
    :effect (and
        (at-city ?z ?y)
        (not (at-city ?z ?x))
        (at-city ?p1 ?y)
        (not (at-city ?p1 ?x))
    )
)
)