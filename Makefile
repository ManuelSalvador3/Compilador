default:
	clear
	flex -o ./src/lex.yy.c -l ./src/lexer.l 
	bison -b ./src/y -dy ./src/parser.y 
	gcc -o ./ejecutable/adac ./src/y.tab.c ./src/lex.yy.c -lm