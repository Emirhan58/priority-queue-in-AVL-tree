hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Nokta.o -c ./src/Nokta.cpp
	g++ -I ./include/ -o ./lib/NodeNokta.o -c ./src/NodeNokta.cpp
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Nokta.o ./lib/NodeNokta.o ./lib/DogruKuyrugu.o ./lib/Node.o ./lib/AVL.o ./src/Main.cpp
	
calistir:
	./bin/Test
