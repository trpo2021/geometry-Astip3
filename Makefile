all:bin/main

bin/main: obj/src/main.o obj/lib/staticlib.a
	g++ obj/src/main.o -Wall -Werror -L. obj/lib/staticlib.a -o $@

obj/src/main.o:src/geomviz/main.cpp
	g++ -c -g src/geomviz/main.cpp -Wall -Werror  -o $@
	
	
	
obj/src/check.o: src/lib/check.cpp	
	g++ -c -g src/lib/check.cpp -Wall -Werror  -o $@
	
obj/lib/staticlib.a: obj/src/check.o
	ar rcs $@ $^
	
run:
	./bin/main

clean:
	find . -name "*.o" -exec rm {} \;
	rm bin/main

.PHONY: clean run all
