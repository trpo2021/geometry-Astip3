
all:bin/main

bin/main: obj/src/main.o 
	g++ obj/src/main.o -Wall -Werror -std=c++17  -o $@

obj/src/main.o:src/main.cpp
	g++ src/main.cpp -Wall -Werror -std=c++17  -o $@

	
run:
	./bin/main

clean:
	find . -name "*.o" -exec rm {} \;
	rm bin/main

.PHONY: clean run all
