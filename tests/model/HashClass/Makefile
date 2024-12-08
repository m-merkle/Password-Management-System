CXXFLAGS=-Wall -I/usr/local/include
SRCS= HashClass.cpp HashClass_unittest.cpp 
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main -lcrypto

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

HashClass.o: ../../../src/model/HashClass.h ../../../src/model/HashClass.cpp

clean:
	@rm -f utest *.o
