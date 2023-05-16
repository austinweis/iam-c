#!/bin/sh
mv bin/out bin/old
gcc -std=c99 -I src/ -lm -lraylib src/*.c -o bin/out -g -pg
bin/out
gprof bin/out ./gmon.out > profile
