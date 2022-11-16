outfile:main.o kit.o lc.o  
	cc main.o kit.o lc.o -o lab
main.o:main.c
	cc -c main.c
kit.o:kit.c
	cc -c kit.c
lc.o:lc.c
	cc -c lc.c

clear:
	@echo "clearing..." # echo-for printing ( if no @ then print echo too ) 
	@rm *.o *.txt
