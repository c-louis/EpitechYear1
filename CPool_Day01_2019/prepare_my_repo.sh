#!/bin/bash
blih -u louis.christ@epitech.eu repository create $1
blih -u louis.christ@epitech.eu repository setacl $1 ramassage-tek r
blih -u louis.christ@epitech.eu repository getacl $1
