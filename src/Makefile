#Password Manager - Witty Application
#Makefile
#mmerkle, 11/15/2024

PROG=app
PORT=8096
SRCS=main.cpp passMangApp.cpp \
       UserForm.cpp addUserView.cpp CredentialForm.cpp addCredentialView.cpp searchCredView.cpp searchUserView.cpp statusView.cpp \
       userType.cpp  #Credential.cpp User.cpp userType.cpp \
       
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
userType.o: model/userType.cpp model/userType.h

# views
UserForm.o: view/UserForm.h view/UserForm.cpp #model/UserList.h
addUserView.o: view/addUserView.h view/addUserView.cpp #model/UserList.h
CredentialForm.o: view/CredentialForm.h view/CredentialForm.cpp #model/CredentialList.h
addCredentialView.o: view/addCredentialView.h view/addCredentialView.cpp #model/CredentialList.h
searchCredView.o: view/searchCredView.h view/searchCredView.cpp #model/CredentialList.h
searchUserView.o: view/searchUserView.h view/searchUserView.cpp #model/UserList.h
statusView.o: view/statusView.h view/statusView.cpp

# utilities
clean:
	@rm -f ${PROG} ${OBJS} *.core 

start: ${PROG}
	./${PROG} --docroot ../ --http-address 0.0.0.0 --http-port ${PORT} &

stop:
	@pkill ${PROG}
