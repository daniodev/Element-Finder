#!/bin/bash
@echo off
clear
gcc -o elementFinder elementFinder.c
./elementFinder "$1" "$2" "$3"
rm elementFinder
