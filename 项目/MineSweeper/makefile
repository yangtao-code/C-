TARGET:=MineSweeper
CC:=arm-linux-gcc
HEADPATH:=inc
LIBPATH:= -L lib/
SRCPATH:=src
LINKLIB:=-lm -lpthread -ljpeg 

CSRC:=$(wildcard $(SRCPATH)/*.c)
OBJS:=$(patsubst %.c,%.o,$(CSRC))

$(TARGET):$(OBJS)
	$(CC) $^ -o $@ $(LIBPATH) $(LINKLIB) 

%.o:%.c
	$(CC) -c $< -o $@ -I$(HEADPATH)

$(LIBNAME):$(LIBOBJS)
	ar -rc $@ $<

.PHONY : clean

clean:
	rm -rf $(OBJS) $(TARGET) $(LIBOBJS)