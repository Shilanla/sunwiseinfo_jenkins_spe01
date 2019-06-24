DIR_INCLUDE=-I ../src_ctrl -I ../src_main -I ../src_sys -I ../src_1553b

libfile=libsys.a
lib=startup.o BSPInit.o 1553b.o
app=main.o io.o controller.o modeImpl.o
all=$(lib) $(app) 

XCC = /opt/rtems-4.6/bin/sparc-rtems-gcc -D __LEON3__
XDUMP = /opt/rtems-4.6/bin/sparc-rtems-objdump

FLAGS_ASM = -c -Wa -gdwarf-2,--gstabs 
FLAGS_C   = -c -O2 -Wall -gdwarf-2

ENTRY_ADDR = 0x40000000
ENTRY_SYMBOL = _trap_table

startup.o:  ../src_sys/startup.S 
	$(XCC) $(FLAGS_ASM) -mcpu=v8 $(DIR_INCLUDE) ../src_sys/startup.S
BSPInit.o: ../src_sys/BSPInit.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_sys/BSPInit.c
1553b.o: ../src_1553b/1553b.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_1553b/1553b.c
io.o: ../src_main/io.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_main/io.c
main.o: ../src_main/main.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_main/main.c
controller.o: ../src_ctrl/controller.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_ctrl/controller.c
modeImpl.o: ../src_ctrl/modeImpl.c
	$(XCC) $(FLAGS_C) -mcpu=v8 $(DIR_INCLUDE) ../src_ctrl/modeImpl.c

ld:
	$(XCC) $(all) -gdwarf-2 $(DIR_INCLUDE) -nostdlib -nostartfiles -N -L -v -Wl -Wall -TLinkcmds -e $(ENTRY_SYMBOL) -Ttext=$(ENTRY_ADDR)  -lm -lc -lgcc
	rm -rf *.o *.a
	$(XDUMP) -xDS a.out > list_upload.lst

# 从源代码编译可执行文件
upload: $(all)
	make ld

# 将系统软件库文件和控制软件源代码联合编译为可执行文件
link: $(app)
	cp ../lib/$(libfile) ./
	tar -xf $(libfile)
	make ld

# 将系统软件相关源代码打包为库文件
lib: $(lib)
	rm -rf *.a
	tar -cvf $(libfile) $(lib)
	rm -rf ../lib/*.a
	cp $(libfile) ../lib
	rm -rf *.o *.a

clean:
	rm -rf *.bak *.o *.lst *.out
