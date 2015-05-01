CXX=clang++
#CXX=g++
CXXFLAGS=-g -Wall -std=c++11 $(shell pkg-config opencv --cflags)
LDFLAGS=-g $(shell pkg-config opencv --libs)

ALL=imshow smooth pyrdown canny camera findContours_demo otsu

all : $(ALL)

imshow : imshow.cc
smooth : smooth.cc
pyrdown : pyrdown.cc
canny : canny.cc
otsu : otsu.cc
camera : camera.cc
findContours_demo : findContours_demo.cpp

clean:
	$(RM) -f $(ALL)

