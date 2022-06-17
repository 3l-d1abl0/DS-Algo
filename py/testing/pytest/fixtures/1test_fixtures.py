import pytest

'''
Test fixtures allows for reuse and setup of teardown code across tests.
'''


'''
@pytest. fixture()
def setup():
    print ("\nSetup")


def testl(setup):
    print("Executing testl!")
    assert True


@pytest.mark.usefixtures ("setup")
def test2():
    print("Executing test2!")
    assert True

'''
#autouse makes it by default called by every function
@pytest. fixture(autouse=True)
def setup():
    print ("\nSetup")


def testl():
    print("Executing testl!")
    assert True

def test2():
    print("Executing test2!")
    assert True

