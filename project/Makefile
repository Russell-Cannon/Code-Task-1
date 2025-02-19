CPP := g++ # change to clang++, if needed

main:	main.o ResizingArray.o UnionFind.o
	$(CPP) -o main main.o ResizingArray.o UnionFind.o

main.o:	main.cpp
	$(CPP) -c -o $@ $<

UnionFind.o:	UnionFind.cpp UnionFind.h ResizingArray.h
	$(CPP) -c -o $@ $<

ResizingArray.o:	ResizingArray.h
	$(CPP) -c -o $@ $<
