ANTLR=antlr-4.8-complete.jar
PROJ=C
GEN=BaseListener.cpp BaseListener.h BaseVisitor.cpp BaseVisitor.h Lexer.cpp Lexer.h Listener.cpp Listener.h Parser.cpp Parser.h Visitor.cpp Visitor.h
GEN_FILES=$(patsubst %,generated/$(PROJ)%,$(GEN))

SRCS=$(filter %.cpp,$(GEN_FILES))
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
CXXFLAGS=-I/usr/include/antlr4-runtime -Igenerated -Wno-attributes -Wall -g -Og -fPIC -mfentry
# -ggdb -flto
LDFLAGS=-Og -fPIC -g
# -flto
LDLIBS=-lantlr4-runtime

generate: $(GEN_FILES)

all: $(PROJ) FORCE
	LD_LIBRARY_PATH=. ./$< in.c

generated/%BaseListener.cpp generated/%BaseListener.h generated/%BaseVisitor.cpp generated/%BaseVisitor.h generated/%Lexer.cpp generated/%Lexer.h generated/%Listener.cpp generated/%Listener.h generated/%Parser.cpp generated/%Parser.h generated/%Visitor.cpp generated/%Visitor.h: %.g4
	java -jar $(ANTLR) -visitor -Dlanguage=Cpp -o generated $^

main.cpp: $(filter %.h,$(GEN_FILES))

libparser.so: $(OBJS)
	$(CXX) $(LDFLAGS) -shared -o $@ $^ $(LDLIBS)

$(PROJ): main.o libparser.so
	$(CXX) $(LDFLAGS) -o $@ $< -L. -lparser $(LDLIBS)

clean:
	rm -f $(PROJ) *.so *.o generated/*.o

mrproper: clean
	rm -fr generated/

.PHONY: FORCE
