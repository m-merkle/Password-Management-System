# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=Database.cpp  Database_unittest.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lsqlite3 -lgtest -lgtest_main

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

Database.o : ../../../src/model/Database.cpp ../../../src/model/Database.h

clean:
	@rm -f utest *.o

