Recognizer: Recognizer.o
  gcc -o Recognizer Recognizer.o

Recognizer.o: Recognizer.c
  gcc -c Recognizer.c

clean: *.o
  rm -rf *.o Recognizer
