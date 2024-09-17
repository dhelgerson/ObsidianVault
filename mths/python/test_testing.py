import pytest
from testing import *

def test_func(): assert func() == True

def test_doNothing(): assert doNothing() == None

@pytest.mark.parametrize("item", ['hi', 3, '3', 'hello',[1,2,3],True])
def test_convert(item):
    assert convert(item) == None

def test_returnSum():
    assert returnSum(x,y) == z