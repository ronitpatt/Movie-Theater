# Movie Theater Seating Challenge

## Problem:
Fulfill reservations for a given movie theater.

## Specifications Given
10 x 20 movie theater
Keep 3 seat buffer and/or one row difference
## Input
Ex: R001 2
    R002 4
    R003 4
    R004 3
where the number denotes the number of seats

## Assumptions
Priority is given to people with the earliest reservations hence the list of reservations is not sorted.
Exits with code 1 when capacity is filled.


## Algorithm Structure
1) Find open row if possible
2) Make buffer of 3 seats
3) Optimize location if possible
    - Location Optimization : Ideal location for a customer is generally in the middle of the movie theater. In the algorithm, this idea is reflected by placing the earlier reservations in the middle rows as possible.
However, placing a customer in the middle columns generally reduces the amount of open seats for other customers due to the buffer.
Difference between placing customer in edge (optimal location) versus middle:
reservation size 1 to 14: 3 open spots lost minimum
reservation size 15: 2 open spots lost
reservation size 16: 1 open spot lost
reservation size 17: No open spots lost
reservation size 18: No open spots lost
reservation size 19: No open spots lost
reservation size 20: No open spots lost

Hence, for smaller amount of seat sizes, it is better to place in the edges as to ensure that the number of seats lost is minimized. This is reflected in my algorithm where for seat size reservations of size 14 or below, the reservation is placed in the edge of the theater if possible. Furthermore, for reservations of size 15 or higher, the customers are placed in the middle of the theater to maximize satisfaction as the amount of valid seats lost is minimal.

## Test Cases





