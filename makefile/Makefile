
#-----------------------------------------
#指定目录找寻依赖和目标
VPATH = src:../headers

#指定文件格式找寻依赖和目标，.c文件在当前目录查找
vpath %.c .

#清除符合模式搜索目录
#vpath %.c

#清除所有符合模式搜索目录
#vpath

#符合模式按照定义顺序搜索
#-----------------------------------------

#objs = $(wildcard *.o)

objs = main.o

edit:$(objs)
	@gcc -o $@ $<

$(objs):%.o:%.c
	@gcc -c $< -o $@

%.d:%.c
	gcc -MM $< > %@

all:edit

#伪目标
.PHONY:all

.PHONY:clean
clean :
	-rm edit $(objs)

exec:
	cd ~/
	pwd       
	cd ~/;pwd
