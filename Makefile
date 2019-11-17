runproject: fraction.o point.o project1.o
		g++ -o runproject project1.o fraction.o point.o 
fraction.o: fraction.cc fraction.h
		g++ -c fraction.cc
point.o: point.cc fraction.h point.h
		g++ -c point.cc
project1.o: project1.cc fraction.h point.h 
		g++ -c project1.cc
