# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=Database.cpp  Database_unittest.cpp HashClass.cpp User.cpp userType.cpp Credential.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lsqlite3 -lgtest -lgtest_main -lcrypto 

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

Database.o : ../../../src/model/Database.cpp ../../../src/model/Database.h
HashClass.o : ../../../src/model/HashClass.cpp ../../../src/model/HashClass.h
Credential.o : ../../../src/model/Credential.cpp ../../../src/model/Credential.h
User.o : ../../../src/model/User.cpp ../../../src/model/User.h
userType.o : ../../../src/model/userType.cpp ../../../src/model/userType.h

clean:
	@rm -f utest *.o

