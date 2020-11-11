src     = $(wildcard *.cpp)
obj     = $(patsubst %.cpp,%,$(src))
CC      = g++
CFLAGS += -g -Wall 

ALL:$(obj)

%:%.cpp
		        $(CC) $< -o $@ $(CFLAGS)

clean:
		        -rm -rf $(obj)

.PHONY:clean ALL
