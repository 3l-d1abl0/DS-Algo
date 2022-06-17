'''DEMO/Test fixtures have four diﬀerent scopes:
- By default the scope is set to function and this specifies that the fixture should be called for all tests in the module.

- Class scope specifies the test fixture should be executed once per test class.
- Module scope specifies that the fixture should be executed once per module.
- Session scope specifies that the fixture should be executed once when PyTest starts.
'''


import pytest


@pytest. fixture(scope="session", autouse=True)
def setupSession():
    print("\nSetup Session")

@pytest. fixture(scope="module", autouse=True)
def setupModule():
    print("\nSetup Module")

@pytest. fixture(scope="function", autouse=True)
def setupFunction():
    print("\nSetup Function")


def test1():
    print("Executing test1!")
    assert True

def test2():
    print ("Executing test2!")
    assert True