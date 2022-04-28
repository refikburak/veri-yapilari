hepsi:derle bagla calistir

derle:
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include -o ./lib/Nokta.o -c ./src/Nokta.cpp
	g++ -I ./include -o ./lib/DogruKuyrugu.o -c ./src/DogruKuyrugu.cpp
	g++ -I ./include -o ./lib/AVLAgaci.o -c ./src/AVLAgaci.cpp

bagla:
	g++ -I ./include ./lib/main.o ./lib/Nokta.o ./lib/DogruKuyrugu.o ./lib/AVLAgaci.o -o ./bin/Uygulama
calistir:
	./bin/Uygulama