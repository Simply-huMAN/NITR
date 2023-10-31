(define (problem gripper_name) (:domain gripper)
(:objects 
    rooma roomb ball1 ball2 ball3 ball4 left right
)

(:init
    ;todo: put the initial state's facts and numeric values here
    (ROOM rooma) (ROOM roomb)
    (BALL ball1) (BALL ball2) (BALL ball3) (BALL ball4)
    (GRIPPER left) (GRIPPER right) (free left) (free right)
    (at-robby rooma)
    (at-ball ball1 rooma) (at-ball ball2 rooma)
    (at-ball ball3 rooma) (at-ball ball4 rooma)
)

(:goal (and
    ;todo: put the goal condition here
    (at-ball ball1 roomb)
    (at-ball ball2 roomb)
    (at-ball ball3 roomb)
    (at-ball ball4 roomb)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
