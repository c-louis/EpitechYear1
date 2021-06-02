#!/bin/bash
[ -z $1 ] && wc -l || grep -i -c ";$1"