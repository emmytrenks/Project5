COMPILER=g++ --std=c++11
EXECUTABLES=test.out

all:
	make $(EXECUTABLES)

test.out: test.cpp
	$(COMPILER) -o $@ $^

test: test.out
	./test.out

clean:
	rm -f $(EXECUTABLES)
