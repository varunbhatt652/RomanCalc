CC = gcc
OBJECTS = romancalc.c tests/*.c
TESTFLAGS = -Wall -std=c11 -O0
CFLAGS = $(TESTFLAGS) -coverage
LDFLAGS = -pthread -lcheck -lrt -lm

check: run_tests

run_tests: compile_tests
		@echo ""
		@echo "**************************"
		@echo "**    Running Tests     **"
		@echo "**************************"
		@${CURDIR}/test
		@echo ""
		@echo "**************************"
		@echo "**     Test Coverage    **"
		@echo "**************************"
		@gcov -n romancalc.c

compile_tests: $(OBJECTS)
		$(CC) $(CFLAGS) -o test $^ $(LDFLAGS)

clean:
	rm -f test *.o *.gc[nod][oav]







