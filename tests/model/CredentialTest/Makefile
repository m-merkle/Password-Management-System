CXXFLAGS=-Wall -I/usr/local/include
SRCS= Credential.cpp Credential_unittest.cpp 
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

Credential.o: ../../../src/model/Credential.h ../../../src/model/Credential.cpp

clean:
	@rm -f utest *.o
