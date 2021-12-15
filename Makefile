
all: test clean

test: main.o Button.o i3window.o shader.o ModelEngine.o
	g++ main.o Button.o i3window.o shader.o ModelEngine.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLEW -lglfw

main.o: src/main.cpp
	g++ -c src/main.cpp

Button.o: src/Button.cpp
	g++ -c src/Button.cpp

i3window.o: src/i3window.cpp
	g++ -c src/i3window.cpp

shader.o: src/shader.cpp
	g++ -c src/shader.cpp

ModelEngine.o: src/ModelEngine.cpp
	g++ -c src/ModelEngine.cpp

clean:
	rm -rf *.o

run: all
	./app