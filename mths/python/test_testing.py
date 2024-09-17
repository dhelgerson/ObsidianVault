import pytest
from testing import *

def test_func(): assert func() == True

def test_doNothing(): assert doNothing() == None

@pytest.mark.parametrize("item", ['hi', 3, '3', 'hello',[1,2,3],True])
def test_convert(item):
    assert convert(item) == None

@pytest.mark.parametrize("x,y,z",[(2,3,5),(1,2,3),(2,4,6),(1,7,8)])
def test_returnSum(x,y,z):
    assert returnSum(x,y) == z

def geninputs():
    for item in ["8","4"]:
        yield item

GEN = geninputs()

def test_inputs(monkeypatch):
    TEST = (x for x in ["6","3"])
    monkeypatch.setattr('builtins.input', lambda _: next(TEST))
    assert inputs() == 2.0

if __name__ == "__main__":
    print(type(GEN)," ",GEN)
    print(next(x for x in ["1","2"]))