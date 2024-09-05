O= build
OBJs= $(O)/BST.o $(O)/main.o

BST: $(OBJs)
	gcc $(OBJs) -o BST

$(O)/%.o: %.c $(O)
	gcc -c $< -o $@

$(O):
	mkdir $(O)

run: BST
	./BST

clean:
	rm -rf build BST