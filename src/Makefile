#Password Manager - Witty Application
#Makefile
#mmerkle, 11/15/2024

PROG=app
PORT=8097
SRCS=main.cpp passMangApp.cpp \
       #Credential.cpp User.cpp userType.cpp \
       #view/home.cpp
OBJS=${SRCS:S/cpp$/o/g}

CXXFLAGS=-Wall -std=c++17 -g
CXXFLAGS+=-I/usr/local/include -I${.CURDIR}/model -I${.CURDIR}/view
LDFLAGS=-L/usr/local/lib
LDFLAGS+=-lwthttp -lwt

.PHONY: all clean start stop

all: ${PROG}

${PROG}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

# model
#cred.o: model/Credential.cpp model/Credential.h
#user.o: model/User.cpp model/User.h model/userType.h
#usertype.o: model/userType.cpp model/userType.h

# views
#home.o: view/home.h view/home.cpp

# utilities
clean:
	@rm -f ${PROG} ${OBJS} *.core 

start: ${PROG}
	./${PROG} --docroot ../ --http-address 0.0.0.0 --http-port ${PORT} &

stop:
	@pkill ${PROG}
