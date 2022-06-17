import pytest

'''
Each test fixture can specify their own teardown code that should be executed.
- There are two methods of specifying a teardown code for a test fixture: The “yield” keyword and the request-context object’s “addfinalizer” method.
'''


'''
The code after the yield is executed after the fixture goes out of scope.
- The yield keyword is a replacement for return and any return values should be passed to it.

'''

print("===================================")

@pytest.fixture()
def setup1():
    print("\nSetup 1")
    yield
    print("\nTeardown 1")


@pytest.fixture()
def setup2(request):
    print("\nSetup 2")

    def teardown_a():
        print("\nTeardown A")

    def teardown_b():
        print("\nTeardown B")

    request.addfinalizer(teardown_a)
    request.addfinalizer(teardown_b)


def test1(setup1):
    print("Execute test1")
    assert True

def test2(setup2):
    print("Execute test2")
    assert True


'''
The addfinalizer method of adding teardown code is a little more complicated but also a little more capable than the yield statement.
- With the addfinalizer method one or more finalizer functions are added via the request-context’s addfinalizer method.
- One of the big diﬀerences between this method and the yield keyword method is that this method allows for multiple finalization functions to be specified.

'''