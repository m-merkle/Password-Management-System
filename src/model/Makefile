# Google's gtest unit test framework for C++
CXXFLAGS=-Wall -I/usr/local/include
SRCS=User.cpp userType.cpp Credential.cpp Database.cpp modelControl.cpp HashClass.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lsqlite3 -lssl -lcrypto 

.PHONY: all clean

all: drivertest

drivertest: ${OBJS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o $@ ${OBJS}

User.o : User.cpp User.h 
userType.o : userType.cpp userType.h
Credential.o : Credential.cpp Credential.h
Database.o : Database.cpp Database.h
modelControl.o : modelControl.cpp
HashClass.o : HashClass.cpp HashClass.h

clean:
	@rm -f drivertest *.o

