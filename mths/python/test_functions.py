import pytest
from functions import *

## most basic test ever
def test_return():
    assert func(5) == 6

@pytest.mark.parametrize("values,expected", [(4,5), (6,7), (9,10)])
def test_more(values, expected):
    assert func(values) == expected
