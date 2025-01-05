all: consumer producer

consumer: consumer.o readline.o 
	gcc consumer.o readline.o -o consumer

producer: producer.o readline.o
	gcc producer.o readline.o -o producer

producer.o: producer.c readline.h
	gcc -c producer.c

consumer.o: consumer.c readline.h
	gcc -c consumer.c

readline.o: readline.c readline.h
	gcc -c readline.c

clean:
	rm -f *.o consumer producer