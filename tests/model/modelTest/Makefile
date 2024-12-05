# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=User.cpp userType.cpp Credential.cpp modelTest.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: modeltest

modeltest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS}

User.o : ../../../src/model/User.cpp ../../../src/model/User.h
userType.o : ../../../src/model/userType.cpp ../../../src/model/userType.h
Credential.o : ../../../src/model/Credential.cpp ../../../src/model/Credential.h

clean:
	@rm -f modeltest *.o

