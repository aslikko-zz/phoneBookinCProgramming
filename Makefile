# kullanilan derleyici
CC   = gcc

OBJ=190101138.o
# derleyici flagleri
CFLAGS = -c -ansi -pedantic-errors

#source dosyasi
SOURCES= 190101138.c
#executable dosya
BIN  = yalphone
#silmek icin flagler
RM = rm -f

all: obj

derle:
	$(CC) $(CFLAGS) $(SOURCES)
	
obj: derle
	$(CC) $(OBJ) -o $(BIN)

calistir: derle
	./$(BIN) -a add "Yunus Emre Avcı" "02268155348" "Bilgisayar Mühendisliği Öğretim Elemanı"
val: derle
	valgrind --leak-check=yes ./$(BIN) -a add "Yunus Emre Avcı" "02268155348" "Bilgisayar Mühendisliği Öğretim Elemanı" 

clean: 
	${RM} $(OBJ) $(BIN) 
