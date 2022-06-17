#https://realpython.com/python-testing/#choosing-a-test-runner

There are many test runners available for Python. The one built into the Python standard library is called unittest. In this tutorial, you will be using unittest test cases and the unittest test runner. The principles of unittest are easily portable to other frameworks. The three most popular test runners are:

unittest
nose or nose2
pytest
Choosing the best test runner for your requirements and level of experience is important.

unittest
unittest has been built into the Python standard library since version 2.1. You’ll probably see it in commercial Python applications and open-source projects.

unittest contains both a testing framework and a test runner. unittest has some important requirements for writing and executing tests.

unittest requires that:

You put your tests into classes as methods
You use a series of special assertion methods in the unittest.TestCase class instead of the built-in assert statement
To convert the earlier example to a unittest test case, you would have to:

Import unittest from the standard library
Create a class called TestSum that inherits from the TestCase class
Convert the test functions into methods by adding self as the first argument
Change the assertions to use the self.assertEqual() method on the TestCase class
Change the command-line entry point to call unittest.main()


The Python application that executes your test code, checks the assertions, and gives you test results in your console is called the test runner.

The data that you create as an input is known as a fixture. It’s common practice to create fixtures and reuse them.

If you’re running the same test and passing different values each time and expecting the same result, this is known as parameterization.
