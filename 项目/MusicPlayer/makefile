TARGET:=MusicPlayer
CC:=arm-linux-g++
HEADPATH:=inc
LIBPATH:= -L lib/
SRCPATH:=src
LINKLIB:=-ljpeg -lpthread

CSRC:=$(wildcard $(SRCPATH)/*.cpp)
OBJS:=$(patsubst %.cpp,%.o,$(CSRC))

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIBPATH) $(LINKLIB) 

%.o:%.cpp
	$(CC) -c $< -o $@ -I$(HEADPATH)


.PHONY : clean
clean:
	rm -rf $(OBJS) $(TARGET) $(LIBOBJS)