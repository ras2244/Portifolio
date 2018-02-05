# Script file /home/greg/sh/makemake.sh generated Makefile for building csvdump
# from the .cpp/[.h] files in folder:  /home/greg/seneca/345/p/GB-rev/2168/b
# optional compliler flags: (none)
# Author: Greg Blair

C11FLAG = -std=c++11
CXX     = g++

ifeq ($(HOSTNAME),matrix)
  # four compiler options:
  # 1. SUSE g++
  CXX     = g++
  C11FLAG = std=c++0x 
      # SUSE g++ is 4.6.2, released October 26, 2011
  # 2. 2013-05-20 vintage g++ (GCC) 4.9.0 20130520 (experimental) was installed in folder
  CXX     = /usr/local/gcc/gcc-cilk/bin/g++
  C11FLAG = -std=c++11 
      # this compiler is EXPERIMENTAL and is NOT recommended for compiling production code.
  # 3. clang
  CXX     = clang++
  C11FLAG = -std=c++11 
  # 4. g++ 5.2.0 installed Dec 2015
  CXX     = /usr/local/gcc/5.2.0/bin/g++
  C11FLAG = -std=c++11 
endif


ALL = csvread csvdump  item order task i-test o-test t-test iot factory
all : $(ALL)

CXXFLAGS=$(C11FLAG) -ggdb 

csvread : csvread.cpp
	$(CXX) $(CXXFLAGS) csvread.cpp -o $@ -pthread

csvdump : csvdump.cpp util.cpp util.h
	$(CXX) $(CXXFLAGS) csvdump.cpp util.cpp -o $@ -pthread

item : item.cpp util.cpp util.h
	$(CXX) $(CXXFLAGS) item.cpp util.cpp -o $@ -pthread

order : order.cpp util.cpp util.h
	$(CXX) $(CXXFLAGS) order.cpp util.cpp -o $@ -pthread

task : task.cpp util.cpp util.h
	$(CXX) $(CXXFLAGS) task.cpp util.cpp -o $@ -pthread

i-test : i-test.cpp i.cpp i.h t.cpp t.h util.cpp util.h
	$(CXX) $(CXXFLAGS) i-test.cpp i.cpp t.cpp util.cpp -o $@ -pthread

o-test : o-test.cpp o.cpp o.h i.cpp i.h t.cpp t.h util.cpp util.h
	$(CXX) $(CXXFLAGS) o-test.cpp i.cpp o.cpp t.cpp  util.cpp -o $@ -pthread

t-test : t-test.cpp t.cpp i.h util.cpp util.h
	$(CXX) $(CXXFLAGS) t-test.cpp t.cpp util.cpp -o $@ -pthread

iot : iot.cpp o.cpp o.h i.cpp i.h t.cpp t.h util.cpp util.h
	$(CXX) $(CXXFLAGS) iot.cpp i.cpp o.cpp t.cpp  util.cpp -o $@ -pthread

factory : factory.cpp o.cpp o.h i.cpp i.h t.cpp t.h util.cpp util.h
	$(CXX) $(CXXFLAGS) factory.cpp i.cpp o.cpp t.cpp  util.cpp -o $@ -pthread


clean :
	-rm $(ALL)

# to let g++ generate list of include file dependencies, run:
# g++ -MM *.cpp >> Makefile
csvdump.o: csvdump.cpp util.h
csvread.o: csvread.cpp
factory.o: factory.cpp util.h i.h t.h o.h machine.h job.h
i.o: i.cpp util.h i.h t.h
iot.o: iot.cpp util.h i.h t.h o.h
item.o: item.cpp util.h
i-test.o: i-test.cpp util.h i.h t.h
o.o: o.cpp util.h o.h i.h t.h
order.o: order.cpp util.h
o-test.o: o-test.cpp util.h o.h i.h t.h
task.o: task.cpp util.h
t.o: t.cpp util.h t.h
t-test.o: t-test.cpp util.h t.h
util.o: util.cpp util.h
