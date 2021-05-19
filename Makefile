all:bin/main

bin/main: obj/src/main.o
	g++ obj/src/main.o -Wall -Werror -o $@

obj/src/main.o:src/geomviz/main.cpp
	g++ -c -g src/geomviz/main.cpp -Wall -Werror  -o $@
		
run:
	./bin/main

clean:
	find . -name "*.o" -exec rm {} \;
	rm bin/main

.PHONY: clean run all
