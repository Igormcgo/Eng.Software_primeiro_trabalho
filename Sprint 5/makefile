run_u:
	./bin/unitario

run_f:
	./bin/funcional

all: sim functional unit

functional: ./bin/sim.dll
	g++ ./teste/funcional/funcional_tests.cpp ./teste/funcional/main.cpp -o ./bin/funcional -L./bin -lsim

sim:
	g++ -shared ./src/flow.cpp ./src/system.cpp ./src/model.cpp -o ./bin/sim.dll

unit:
	g++ ./src/*.cpp ./teste/unit/*.cpp -o ./bin/unitario

./bin/sim.dll:
	g++ -shared ./src/flow.cpp ./src/system.cpp ./src/model.cpp -o ./bin/sim.dll

