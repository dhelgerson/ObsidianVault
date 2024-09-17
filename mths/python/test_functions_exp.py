import pytest
from functions import *

## parametrize -- multiple test values to send to the function
@pytest.mark.parametrize("values", ["hello", "5", "5.0", 5, 5.0, False])
def test_foo(values):
    assert foo(values) == None

@pytest.mark.parametrize("values", ["hello", "kortni"])
def test_raise(values):
    with pytest.raises(ValueError):
        bar(values)


## ********************************
## INPUT TESTING

## multiple input set up
## this makes it where each item follows the inputs
## in order of input statements
def geninputs():
    inputs = ["6", "3"]

    for item in inputs:
        yield item

## sets up our inputs
GEN = geninputs()

def test_input(monkeypatch):
    ## passes input to the command-line
    ## if a single input statement, can just pass the string
    # monkeypatch.setattr('builtins.input', lambda _: next(GEN))
    TEST = (x for x in ["6","3"])
    monkeypatch.setattr('builtins.input', lambda _: next(TEST))

    assert inputTest() == 2.0

if __name__ == "__main__":
    print(type(GEN),type(x for x in ["4","8"]))

## ********************************


## ********************************
## OUTPUT TESTING

## output catches EVERYTHING the function output

def test_print(capsys):
    ## calls test function
    printTest()

    ## sets up print test
    captured_stdout, captured_stderr = capsys.readouterr()

    ## tests print -- also strips whitespace from the end
    assert captured_stdout.strip() == "Hello world"

@pytest.mark.parametrize("values,expected", [("Maggie", "Hello, Maggie"), ("Kortni", "Hello, Kortni")])
def test_print2(capsys, values, expected):
    printTestPara(values)

    captured_stdout, captured_stderr = capsys.readouterr()
    assert captured_stdout.strip() == expected

## ********************************


## ********************************
## INPUT/OUTPUT TESTING

## also shows multiple output statements taken into consideration
@pytest.mark.parametrize("values,expected", [("Maggie", "Hello, Maggie\nyo"), ("Kortni", "Hello, Kortni\nyo")])
def test_in_out(capsys, monkeypatch, values, expected):
    monkeypatch.setattr('builtins.input', lambda _: values)
    inputOutput()

    captured_stdout, captured_stderr = capsys.readouterr()
    assert captured_stdout.strip() == expected

## ********************************
