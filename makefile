objects = meshSimplify.o myVec3d.o vector4.o matrix.o vertex.o vertexGroup.o edge.o edgeHeap.o config.o solve.o 

all: main.exe clean test005 test001 test03

main.exe: main.cpp $(objects)
	g++ main.cpp $(objects) -o main.exe -O3

meshSimplify.o: meshSimplify.h meshSimplify.cpp
	g++ -c meshSimplify.cpp -O3

myVec3d.o: myVec3d.h myVec3d.cpp
	g++ -c myVec3d.cpp -O3
	
vector4.o: vector4.h vector4.cpp
	g++ -c vector4.cpp -O3

matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp -O3

vertex.o: vertex.h vertex.cpp
	g++ -c vertex.cpp -O3

vertexGroup.o: vertexGroup.h vertexGroup.cpp
	g++ -c vertexGroup.cpp -O3

edge.o: edge.h edge.cpp
	g++ -c edge.cpp -O3

edgeHeap.o: edgeHeap.h edgeHeap.cpp
	g++ -c edgeHeap.cpp -O3

config.o : config.h config.cpp
	g++ -c config.cpp -O3

solve.o : solve.h solve.cpp
	g++ -c solve.cpp -O3

clean:
	rm *.o
	
test005:
	main Arma.obj Arma005.obj 0.05
	main block.obj block005.obj 0.05
	main Buddha.obj Buddha005.obj 0.05
	main bunny.obj bunny005.obj 0.05
	main cube.obj cube005.obj 0.05
	main dinosaur.obj dinosaur005.obj 0.05
	main dragon.obj dragon005.obj 0.05
	main fandisk.obj fandisk005.obj 0.05
	main horse.obj horse005.obj 0.05
	main kitten.obj kitten005.obj 0.05
	main rocker.obj rocker005.obj 0.05
	main sphere.obj sphere005.obj 0.05

test001:
	main Arma.obj Arma001.obj 0.01
	main block.obj block001.obj 0.01
	main Buddha.obj Buddha001.obj 0.01
	main bunny.obj bunny001.obj 0.01
	main cube.obj cube001.obj 0.01
	main dinosaur.obj dinosaur001.obj 0.01
	main dragon.obj dragon001.obj 0.01
	main fandisk.obj fandisk001.obj 0.01
	main horse.obj horse001.obj 0.01
	main kitten.obj kitten001.obj 0.01
	main rocker.obj rocker001.obj 0.01
	main sphere.obj sphere001.obj 0.01

test03:
	main Arma.obj Arma03.obj 0.3
	main block.obj block03.obj 0.3
	main Buddha.obj Buddha03.obj 0.3
	main bunny.obj bunny03.obj 0.3
	main cube.obj cube03.obj 0.3
	main dinosaur.obj dinosaur03.obj 0.3
	main dragon.obj dragon03.obj 0.3
	main fandisk.obj fandisk03.obj 0.3
	main horse.obj horse03.obj 0.3
	main kitten.obj kitten03.obj 0.3
	main rocker.obj rocker03.obj 0.3
	main sphere.obj sphere03.obj 0.3





