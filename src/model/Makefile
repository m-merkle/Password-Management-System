# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=User.cpp userType.cpp Credential.cpp modelTest.cpp
OBJS=${SRCS:S/cpp$/o/g}
# LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: drivertest

drivertest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

User.o : User.cpp User.h
userType.o : userType.cpp userType.h
Credential.o : Credential.cpp Credential.h

clean:
	@rm -f drivertest *.o

