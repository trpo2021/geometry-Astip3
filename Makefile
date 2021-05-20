all:bin/main

bin/main: obj/src/main.o obj/lib/geometrylib.a
	g++ obj/src/main.o -Wall -Werror -L. obj/lib/geometrylib.a -o $@

obj/src/main.o:src/main.cpp
	g++ -c -g src/main.cpp -Wall -Werror  -o $@

obj/lib/check.o:src/lib/check.cpp
	g++ -c -g src/lib/check.cpp -Wall -Werror  -o $@
	
obj/lib/parse.o:src/lib/parse.cpp
	g++ -c -g src/lib/parse.cpp -Wall -Werror  -o $@
	
obj/lib/calculate.o:src/lib/calculate.cpp
	g++ -c -g src/lib/calculate.cpp -Wall -Werror  -o $@

obj/lib/geometrylib.a: obj/lib/check.o obj/lib/parse.o obj/lib/calculate.o
	ar rcs $@ $^
		
run:
	./bin/main

clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	rm bin/main

.PHONY: clean run all
