CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors
LDFLAGS = -lm
TARGET = roomGame
SRCS = game.cpp
SRCS += Room.cpp
SRCS += Item.cpp
SRCS += Container.cpp
SRCS += LoadingDock.cpp
SRCS += Factory.cpp
SRCS += StorageCloset.cpp
SRCS += Office.cpp
SRCS += Restaurant.cpp
SRCS += PickupCounter.cpp
SRCS += Screwdriver.cpp
SRCS += Wrench.cpp
SRCS += Hammer.cpp
SRCS += MagnifyingGlass.cpp
SRCS += KnifeFork.cpp
SRCS += CommentCard.cpp
SRCS += CookDocument.cpp
SRCS += FactoryDocument.cpp
SRCS += FrontDocument.cpp
SRCS += Toolbox.cpp
SRCS += RecycleBin.cpp
SRCS += Briefcase.cpp
SRCS += Mailbox.cpp
HEADERS = ${SRCS:.cpp=.hpp}
OBJS = ${SRCS:.cpp=.o}

${TARGET} : ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${TARGET}

${OBJS} : ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm -r ${OBJS} ${TARGET}
