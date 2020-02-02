FILES := $(wildcard *.c)
COMPILES_FILES += $(filter-out pagerank.c inverted.c searchPagerank.c, $(FILES))

OBJS:=$(patsubst %c,%o,$(COMPILES_FILES))

pg :$(OBJS)
	@echo "Page Rank FILES" $(OBJS)
	gcc -Wall -Werror pagerank.c $(OBJS) -o pagerank.out

iv :$(OBJS)
	@echo "Page Rank FILES" $(OBJS)
	gcc -Wall -Werror inverted.c $(OBJS) -o inverted.out

sp :$(OBJS)
	@echo "Page Rank FILES" $(OBJS)
	gcc -Wall -Werror searchPagerank.c $(OBJS) -o searchPagerank.out

$.o:%.c
	$(CC) $(STD) -c $< -o $@


clean:
	rm *.o
	rm *.out