final: utPod_driver.o UtPod.o song.o
	g++ -otest  utPod_driver.o UtPod.o song.o
utPod_driver.o: utPod_driver.cpp UtPod.h song.h
	g++ -c utPod_driver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c song.cpp