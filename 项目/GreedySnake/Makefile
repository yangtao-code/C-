TARGET:=GreedySnake
CC:=arm-linux-g++ -std=c++11
HEADPATH:= inc
LIBPATH:= -L lib/
SRCPATH:= src
LINKLIB:=

CSRC:=$(wildcard $(SRCPATH)/*.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(CSRC))

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIBPATH) $(LINKLIB) 

%.o:%.cpp
	$(CC) -c $< -o $@ -I$(HEADPATH)

.PHONY : clean

clean:
	rm -rf $(OBJS) $(TARGET) $(LIBOBJS)


cp:
	cp /home/china/code/project/GreedySnake/ /mnt/hgfs/share/study/project -r