CXX = g++
CXXFLAGS += -I/path/to/gtest/include 
LDFLAGS += -L/path/to/gtest/lib -lgtest -lgtest_main -pthread

main : main.o symtable_link.o symtable_test.o
	$(CXX)	$(CXXFLAGS)	$^	-o	$@	$(LDFLAGS)

main.o : main.cpp
	$(CXX)	$(CXXFLAGS)	-c	$^	-o	$@

symtable_link.o : symtable_link.cpp
	$(CXX)	$(CXXFLAGS)	-c	$^	-o	$@ 

symtable_test.o: symtable_test.cpp
	$(CXX)	$(CXXFLAGS)	-c	$^	-o	$@

test: symtable_test.o symtable_link.o
	$(CXX)	$(CXXFLAGS)	-o	$@	$^	$(LDFLAGS)

clean:
	rm -f main.o symtable_link.o symtable_test.o main