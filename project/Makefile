CPP := g++ # change to clang++, if needed

main:	main.o UnionFind.o
	$(CPP) -o main main.o UnionFind.o

main.o:	main.cpp
	$(CPP) -c -o $@ $<

UnionFind.o:	UnionFind.cpp UnionFind.h
	$(CPP) -c -o $@ $<
