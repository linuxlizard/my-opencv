#CXX=clang++
CXX=g++
CXXFLAGS=-g -Wall -std=c++11 $(shell pkg-config opencv --cflags)
LDFLAGS=-g $(shell pkg-config opencv --libs) -lstdc++

#ALL=imshow smooth 
ALL=imshow smooth pyrdown canny camera findContours_demo otsu rgbtolab

all : $(ALL)

%:%.o
	$(CXX) $(CFLAGS) -o $@ $^ $(LDFLAGS) -lstdc++

imshow : imshow.o
smooth : smooth.o
pyrdown : pyrdown.o
canny : canny.o
otsu : otsu.o
camera : camera.o
rgbtolab : rgbtolab.o
findContours_demo : findContours_demo.o

clean:
	$(RM) -f $(ALL) *.o

