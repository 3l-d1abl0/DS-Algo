import program
import pytest

def test_doubleit():
    assert program.doubleit(10) == 20

def test_doubleit_type():
    with pytest.raises(TypeError):
        program.doubleit('hello')
