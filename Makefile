CC=g++
FLAGS=-Wall -Wextra -Werror -std=c++17
FLAGS_SAN=-fsanitize=address -pedantic
COVFLAGS=--coverage 
LDLIBS=-lgtest

TEST_DIR = ./tests
REPORT_DIR = ./report

SOURCES = ./*.cc ./controller/*.cc ./model/*.cc ./view/*.cc ./tests/*.cc
HEADERS = ./controller/*.h ./model/*.h ./view/*.h
TESTS = $(wildcard $(TEST_DIR)/*.cc ./model/*.cc)

OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	OPEN = open
	RUN = open ./build/3DViewer2.app/
	LEAKS =	leaks -atExit -- 
else
	OPEN = xdg-open
	RUN = ./build/3DViewer2
	LEAKS = valgrind 
endif

rebuild: clean all

all: tests install run

install: clean
	mkdir build
	cd build && qmake ../3DViewer2.pro && make

run:
	$(RUN)

uninstall: 
	rm -rf ./build/

dvi:
	cd doxygen && doxygen 3D_Viewer2_config
	open doxygen/html/index.html

dist: install
	tar -cf 3dviewer-2_0.tar build/*

tests: clean txtobj
	$(CC) $(FLAGS) $(FLAGS_SAN) $(TESTS) $(LDLIBS) -o tests.out
	./tests.out
	make objtxt

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

gcov_report: $(REPORT_DIR) txtobj
	$(CC) $(FLAGS) $(FLAGS_SAN) $(COVFLAGS) $(TESTS) $(LDLIBS) -o report.out
	./report.out
	lcov -o $(REPORT_DIR)/3dviewer.info  -c -d . --ignore-errors mismatch --no-external
	genhtml $(REPORT_DIR)/3dviewer.info -o $(REPORT_DIR)
	rm -rf *.gcda *.gcno
	make objtxt
	$(OPEN) $(REPORT_DIR)/index.html

clean:
	@rm -rf *.app *.cfg *.out
	@rm -rf *.gcda *.gcno *.info
	@rm -rf doxygen/html
	@rm -rf build* *user
	@rm -rf $(REPORT_DIR)
	@rm -rf *tar 

style:
	cppcheck $(SOURCES) $(HEADERS) --language=c++
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(SOURCES) $(HEADERS)
	clang-format -n $(SOURCES) $(HEADERS)
	rm -rf .clang-format

leaks: clean
	$(CC) $(FLAGS) $(TESTS) $(LDLIBS) -o tests.out
	$(LEAKS) ./tests.out

objtxt:
	$(shell for file in obj/*.obj; do j=`echo $$file | cut -d . -f 1`;j=$$j".txt"; mv $$file $$j; done)

txtobj:
	$(shell for file in obj/*.txt; do j=`echo $$file | cut -d . -f 1`;j=$$j".obj"; mv $$file $$j; done)
