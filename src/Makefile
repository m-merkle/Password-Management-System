#Password Manager - Witty Application
#Makefile
#mmerkle, 12/5/2024

PROG=app
PORT=8088
SRCS=main.cpp passMangApp.cpp \
       UserForm.cpp addUserView.cpp CredentialForm.cpp addCredentialView.cpp searchCredView.cpp searchUserView.cpp statusView.cpp editCredentialView.cpp editUserView.cpp\
       userType.cpp Database.cpp User.cpp Credential.cpp HashClass.cpp \
       
OBJS=${SRCS:S/cpp$/o/g}

CXXFLAGS=-Wall -std=c++17 -g
CXXFLAGS+=-I${.CURDIR} -I/usr/local/include -I${.CURDIR}/model -I${.CURDIR}/view
LDFLAGS=-L/usr/local/lib
LDFLAGS+=-lwthttp -lwt -lsqlite3 -lssl -lcrypto

.PHONY: all clean start stop

all: ${PROG}

${PROG}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

# model
Database.o: model/Database.cpp model/Database.h model/
User.o: model/User.cpp model/User.h model/userType.h
userType.o: model/userType.cpp model/userType.h
Credential.o: model/Credential.cpp model/Credential.h
HashClass.o: model/HashClass.cpp model/HashClass.h

# views
UserForm.o: view/UserForm.h view/UserForm.cpp
addUserView.o: view/addUserView.h view/addUserView.cpp
CredentialForm.o: view/CredentialForm.h view/CredentialForm.cpp
addCredentialView.o: view/addCredentialView.h view/addCredentialView.cpp
searchCredView.o: view/searchCredView.h view/searchCredView.cpp
searchUserView.o: view/searchUserView.h view/searchUserView.cpp
statusView.o: view/statusView.h view/statusView.cpp
editCredentialView.o: view/editCredentialView.h view/editCredentialView.cpp
editUserView.o: view/editUserView.h view/editUserView.cpp

# utilities
clean:
	@rm -f ${PROG} ${OBJS} *.core 

start: ${PROG}
	./${PROG} --docroot ../ --http-address 0.0.0.0 --http-port ${PORT} &

stop:
	@pkill ${PROG}
