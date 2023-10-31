(define (problem problem_name) (:domain trucking)
(:objects truck1 truck2 package1 package2 package3 package4 package5 package6 package7 package8 city1 city2)

(:init
    (TRUCK truck1) (TRUCK truck2)
    (CITY city1) (CITY city2)
    (PACKAGE package1) (PACKAGE package2)
    ; (PACKAGE package3) (PACKAGE package4)
    (PACKAGE package5) (PACKAGE package6)
    ; (PACKAGE package7) (PACKAGE package8)
    (at-city package1 city1) (at-city package2 city1)
    ; (at-city package3 city1) (at-city package4 city1)
    (at-city package5 city2) (at-city package6 city2)
    ; (at-city package7 city2) (at-city package8 city2)
    (is-empty truck1) (is-empty truck2)
    (at-city truck1 city1)
    (at-city truck2 city2)
)

(:goal (and
    (at-city package1 city2) (at-city package2 city2)
    ; (at-city package3 city2) (at-city package4 city2)
    (at-city package5 city1) (at-city package6 city1)
    ; (at-city package7 city1) (at-city package8 city1)
))

;un-comment the following line if metric is needed
;(:metric minimize (???))
)
