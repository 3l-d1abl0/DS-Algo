'''
PyTest Test Fixtures allow you to optionally return data from the fixture that can be used in the test.
- The optional params array argument in the fixture decorator can be used to specify one or more values that should be passed to the test.
- When a params argument has multiple values then the test will be called once with each value.
'''

import pytest
@pytest. fixture(params=(1,2,3))
def setup(request):
    retVal = request.param
    print("\nSetup! retVal = {}".format(retVal))
    return retVal

def testl(setup):
    print("\nsetup = {}". format(setup))
    assert True