CC = gcc
CPP = g++
RM = rm -rf

## debug flag
DBG_ENABLE = 0

## source file path
SRC_PATH := .

## target exec file name
TARGET_CLIENT := ssl-client
TARGET_SERVER := ssl-server

## get all source files
SRCS_CLIENT += ssl-client.c
SRCS_SERVER += ssl-server.c

## all .o based on all .c
OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)
OBJS_SERVER := $(SRCS_SERVER:.c=.o)

## need libs, add at here
LIBS := ssl crypto

## used headers file path
INCLUDE_PATH := ../openssl_install_dir/include/

## used include librarys file path
LIBRARY_PATH := ../openssl_install_dir/lib/

## debug for debug info, when use gdb to debug
ifeq (1, ${DBG_ENABLE})
CFLAGS += -D_DEBUG -O0 -g -DDEBUG=1
endif

## get all include path
CFLAGS += $(foreach dir, $(INCLUDE_PATH),-I $(dir))
#SourceFiles  = $(foreach dir,$(SourcePath),$(shell find $(dir) -maxdepth 5 -name "*.c"))
## get all library path
LDFLAGS += $(foreach lib, $(LIBRARY_PATH), -L $(lib))

## get all librarys
LDFLAGS += $(foreach lib, $(LIBS), -l $(lib))

all: clean build

build:
	$(CC) -c $(SRCS_CLIENT) $(CFLAGS)
	$(CC) $(CFLAGS) -o $(TARGET_CLIENT) $(OBJS_CLIENT) $(LDFLAGS)
	#$(RM) $(OBJS)
	$(CC) -c $(SRCS_SERVER) $(CFLAGS)
	$(CC) $(CFLAGS) -o $(TARGET_SERVER) $(OBJS_SERVER) $(LDFLAGS)
	#$(RM) $(OBJS)

clean:
	$(RM) $(OBJS_CLIENT) $(TARGET_CLIENT)
	$(RM) $(OBJS_SERVER) $(TARGET_SERVER)