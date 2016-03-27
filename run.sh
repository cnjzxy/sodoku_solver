#!/bin/sh

g++ transform_input.cpp -o transform_input
./transform_input <sodoku.in >expression.in

minisat expression.in expression.out

g++ transform_output.cpp -o transform_output
./transform_output <expression.out
