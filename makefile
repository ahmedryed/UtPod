final: UtPodDriver.o UtPod.o song.o
	g++ -otest  UtPodDriver.o UtPod.o song.o
driver: UtPodDriver.cpp UtPod.h song.h
	g++ -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c song.cpp