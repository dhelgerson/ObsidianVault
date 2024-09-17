| var | repr.            |
| --- | ---------------- |
| X,Y | one or more char |
| x,y | single char      |
| @   | placeholder      |
1. A@Bx -> Ax*B
2. A@x   -> Ax.
3. Ax      -> x@A

	abcd
	d@abc
	dc@ab
	dcb@a
	dcba
$?X will match a string

