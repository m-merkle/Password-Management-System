# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=User.cpp userType.cpp UserType_unittest.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

User.o : ../../../src/model/User.cpp ../../../src/model/User.h
userType.o : ../../../src/model/userType.cpp ../../../src/model/userType.h

clean:
	@rm -f utest *.o

