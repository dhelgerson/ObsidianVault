import pytest

## function to be tested
def returnSum(num):
    return num + 1

def convert(item):
    try:
        item = int(item)

    except:
        print("oops, wrong value")

def printGreeting(name):
    print("Hello,", name)

def test_printGreeting(capsys):
    printGreeting("Maggie")

    captured_stdout, captured_stderr = capsys.readouterr()
    assert captured_stdout.strip() == "Hello, Maggie"

def inputTest():
    number = int(input("Enter a number: "))

    return number * 2

def test_inputTest(monkeypatch):
    monkeypatch.setattr('builtins.input', lambda _: "8")

    assert inputTest() == 16

@pytest.mark.parametrize("values", ["hello", 5, "5.0", "5", False, 6.0])
def test_convert(values):
    assert convert(values) == None

@pytest.mark.parametrize("number,sum", [(3, 4), (7, 8)])

## PyTest testing function
def test_returnSum(number, sum):
    assert returnSum(number) == sum

## Purposefully failing test
#def test_returnSum_fail():
#    assert returnSum(5) == 7
