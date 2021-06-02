#!/bin/bash
sed -n '2~2p' | sed -n 's/:x:.*//p' | rev | sort -r | sed -n "${MY_LINE1},${MY_LINE2}p" | sed -e :a -e '$!N; s/\n/, /; ta' | sed 's/$/./' | cat