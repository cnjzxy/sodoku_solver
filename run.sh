#!/bin/sh

if g++ read_input.cpp -o rd && g++ print_result.cpp -o prnt; then
	if [ $# -eq 0 ]; then
		echo "########################"
		echo "Please input the sudoku."
		echo "For example:"
		echo "000000047"
		echo "003001800"
		echo "058000090"
		echo "000029300"
		echo "009003018"
		echo "004000050"
		echo "000095004"
		echo "000600000"
		echo "300000701"
		echo "########################"
		
		./rd >expression.in
	else
		./rd <$1 >expression.in
	fi

	minisat expression.in expression.out
	./prnt <expression.out

	rm expression.in expression.out
fi

rm rd prnt
