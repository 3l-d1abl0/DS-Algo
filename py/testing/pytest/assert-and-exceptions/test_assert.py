'''
Pytest allows the use of the built in python assert statement for performing verifications in a unit test.
- The normal comparison operators can be used on all python data types: less than, greater than, less than or equal, greater than or equal, equal, or not equal
- Pytest expands on the messages that are reported for assert failures to provide more context in the test results.

Validating floating point values can sometimes be diﬃcult as internally the value is stored as a series of binary fractions.
- Because of this some comparisons that we’d expect to pass will fail.
- Pytest provides the “approx” function which will validate that two floating point values are “approximately” the same value as each other to within a default tolerance of
1 time E to the -6 value.

In some test cases we need to verify that a function raises an exception under certain conditions.
- Pytest provides the raises helper to perform this verification using the “with” keyword.
- When the “raises” helper is used the unit test will fail if the specified exception is not thrown in the code block after the “raises line.

'''
from pytest import approx

def test_IntAssert():
    assert 1 == 1

def test_StrAssert():
    assert "str" == "str"
    
def test_floatAssert():
    assert 1.0 == 1.0
    
def test_arrayAssert():
    assert [1,2,3] == [1,2,3]

def test_dictAssert():
    assert {"1":1} == {"1":1}

def test_float():
    #floating point will give error due to precision
    #assert(0.1+0.2) == 0.3
    assert(0.1+0.2) == approx(0.3)
