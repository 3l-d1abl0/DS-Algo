from pytest import raises

def raisesValueException():
    #No exception raised will amount to error
    raise ValueError


def test_exception():
    with raises(ValueError):
        raisesValueException()