cc=gcc
cflags=-c
objs=cat.o cd.o cp.o ls.o main.o mkdir.o printinfo.o rm.o rmdir.o shell.o touch.o

minishell:$(objs)
	$(cc) $^ -o $@

cat.o: cat.c 
	$(cc) $(cflags) $< -o $@
cd.o: cd.c 
	$(cc) $(cflags) $< -o $@
cp.o: cp.c 
	$(cc) $(cflags) $< -o $@
ls.o: ls.c 
	$(cc) $(cflags) $< -o $@
main.o: Main.c 
	$(cc) $(cflags) $< -o $@
mkdir.o: mkdir.c 
	$(cc) $(cflags) $< -o $@
printinfo.o: printinfo.c 
	$(cc) $(cflags) $< -o $@
rm.o: rm.c 
	$(cc) $(cflags) $< -o $@
rmdir.o: rmdir.c 
	$(cc) $(cflags) $< -o $@
shell.o: shell.c 
	$(cc) $(cflags) $< -o $@
touch.o: touch.c 
	$(cc) $(cflags) $< -o $@

clean:
	rm *.o