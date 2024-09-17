def func(x):
    return x + 1

def foo(number):
    try:
        number = int(number)

    except ValueError:
        print("oops, wrong type")

def bar(number):
    try:
        number = float(number)

    except ValueError:
        raise ValueError("You entered the wrong type")

def inputTest():
    num1 = int(input("Enter a number: "))
    num2 = int(input("Enter another number: "))

    result = num1 / num2

    return result

def printTest():
    print("Hello world")

def printTestPara(name):
    print("Hello,", name)

def inputOutput():
    name = input("Enter your name: ")

    print("Hello,", name)
    print("yo")
