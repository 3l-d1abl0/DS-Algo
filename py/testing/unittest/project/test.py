import unittest

from my_sum import sum

from fractions import Fraction


#sum = target.sum
#target = __import__("my_sum.py")


class TestSum(unittest.TestCase):

    
    def test_list_int(self):
        """
        Test that it can sum a list of integers
        """
        data = [1, 2, 3]
        result = sum(data)
        self.assertEqual(result, 6)

    def test_list_fraction(self):
        """
        Test that it can sum a list of fractions
        """
        data = [Fraction(1, 4), Fraction(1, 4), Fraction(2, 5)]
        result = sum(data)
        self.assertNotEqual(result, 1)

    def test_bad_type(self):
        data = "banana"
        with self.assertRaises(TypeError):
            result = sum(data)

if __name__ == '__main__':
    unittest.main()

'''

    python -m unittest test

    python -m unittest -v test

    python -m unittest discover
    > This will search the current directory for any files named test*.py and attempt to test them.

    python -m unittest discover -s tests
    > Once you have multiple test files, as long as you follow the test*.py naming pattern, you can provide the name of the directory instead by using the -s flag

    python -m unittest discover -s tests -t src
    > src/



'''
