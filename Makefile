 # Makefile
 # COMP15
 #Spring 2019
 #
 # Lewis Bobrow


CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -g

SeqMatch: main.o Trie.o
		${CXX} ${CXXFLAGS} -o SeqMatch main.o Trie.o

main.o:      main.cpp Trie.h Trie.cpp
Trie.o:  Trie.cpp Trie.h

# provide:
# provide comp15 hw4 main.cpp Trie.cpp Trie.h \
#		README Makefile