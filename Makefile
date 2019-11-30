all: cmd_parse_app

cmd_parse_app: cmd_parse_app.o
	g++ -lm -o cmd_parse_app cmd_parse_app.o

cmd_parse_app.o: cmd_parse_app.cpp
	g++ -O -c cmd_parse_app.cpp

clean:
	rm -f *.o cmd_parse_app
