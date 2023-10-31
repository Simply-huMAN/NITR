;Header and description

(define (domain gripper)

    ;remove requirements that are not needed
    (:requirements :strips :negative-preconditions :equality)

    (:types ;todo: enumerate types and their hierarchy here, e.g. car truck bus - vehicle
        )

    ; un-comment following line if constants are needed
    ;(:constants )

    (:predicates ;todo: define predicates here
        (ROOM ?x)
        (BALL ?x)
        (GRIPPER ?x)
        (at-robby ?x)
        (at-ball ?x ?y)
        (free ?x)
        (carry ?x ?y)
    )

   

    ;define actions here
    (:action move
        :parameters (?x ?y)
        :precondition (and
            (ROOM ?x) (ROOM ?y)
            (at-robby ?x)
        )
        :effect (and
            (at-robby ?y)
            (not (at-robby ?x))
        )
    )

        (:action pick-up
            :parameters (?x ?y ?z)
            :precondition (and (BALL ?x) (ROOM ?y) (GRIPPER ?z)
                (at-ball ?x ?y) (at-robby ?y) (free ?z))
            :effect (and (carry ?z ?x)
                (not (at-ball ?x ?y)) (not (free ?z))
            )
        )

    (:action drop
        :parameters (?x ?y ?z)
        :precondition (and (BALL ?x) (ROOM ?y) (GRIPPER?z)
            (carry ?z ?x) (at-robby ?y))
        :effect (and (at-ball ?x ?y) (free ?z)
            (not (carry ?z ?x))
        )
    )

)