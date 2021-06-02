#!/bin/bash

COMMAND=$(make re)

if [ COMMAND ]
then
    echo -e "-- [ASSERTION 1.0] \e[32mPASSED\e[39m - Compilation successfull"
else
    echo -e "-- [ASSERTION 1.0] \e[31mFAILED\e[39m - Compilation error"
    exit
fi


if [ -f "./gameoflife" ]
then
    echo -e "-- [ASSERTION 2.0] \e[32mPASSED\e[39m - Binary found"
else
    echo -e "-- [ASSERTION 2.0] \e[31mFAILED\e[39m - Binary not found"
    exit
fi


GOL=$(./gameoflife tests/maps/map_gen0.txt 0)
EXAMPLE=$(cat tests/maps/map_gen0.txt)

if [ "$GOL" == "$EXAMPLE" ]
then
    echo -e "-- [ASSERTION 3.0] \e[32mPASSED\e[39m - Map gen 0"
else
    echo -e "-- [ASSERTION 3.0] \e[31mFAILED\e[39m - Map gen 0
--------------RESULT:--------------
$GOL
-------------EXPECTED:-------------
$EXAMPLE"
fi


GOL=$(./gameoflife tests/maps/map_gen0.txt 1)
EXAMPLE=$(cat tests/maps/map_gen1.txt)

if [ "$GOL" == "$EXAMPLE" ]
then
    echo -e "-- [ASSERTION 3.1] \e[32mPASSED\e[39m - Map gen 1"
else
    echo -e "-- [ASSERTION 3.1] \e[31mFAILED\e[39m - Map gen 1
--------------RESULT:--------------
$GOL
-------------EXPECTED:-------------
$EXAMPLE"
fi


GOL=$(./gameoflife tests/maps/map_gen0.txt 2)
EXAMPLE=$(cat tests/maps/map_gen2.txt)

if [ "$GOL" == "$EXAMPLE" ]
then
    echo -e "-- [ASSERTION 3.2] \e[32mPASSED\e[39m - Map gen 2"
else
    echo -e "-- [ASSERTION 3.2] \e[31mFAILED\e[39m - Map gen 2
--------------RESULT:--------------
$GOL
-------------EXPECTED:-------------
$EXAMPLE"
fi


GOL=$(./gameoflife tests/maps/10cellrow_gen0.txt 0)
EXAMPLE=$(cat tests/maps/10cellrow_gen0.txt)

if [ "$GOL" == "$EXAMPLE" ]
then
    echo -e "-- [ASSERTION 4.0] \e[32mPASSED\e[39m - 10cellrow gen 0"
else
    echo -e "-- [ASSERTION 4.0] \e[31mFAILED\e[39m - 10cellrow gen 0
--------------RESULT:--------------
$GOL
-------------EXPECTED:-------------
$EXAMPLE"
fi


GOL=$(./gameoflife tests/maps/10cellrow_gen0.txt 2)
EXAMPLE=$(cat tests/maps/10cellrow_gen2.txt)

if [ "$GOL" == "$EXAMPLE" ]
then
    echo -e "-- [ASSERTION 4.1] \e[32mPASSED\e[39m - 10cellrow gen 2"
else
    echo -e "-- [ASSERTION 4.1] \e[31mFAILED\e[39m - 10cellrow gen 2
--------------RESULT:--------------
$GOL
-------------EXPECTED:-------------
$EXAMPLE"
fi
