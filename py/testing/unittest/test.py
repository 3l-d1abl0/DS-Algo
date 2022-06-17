import unittest
import example1


class TestMain(unittest.TestCase):

    def setUp(self):
        print('about to test a function')

    def test_do_stuff(self):
        '''First Test'''
        test_param = 10
        result = example1.do_stuff(test_param)
        
        self.assertEqual(result, 15)


    def test_do_stuff2(self):

        test_param = 'shkshks'
        result = example1.do_stuff(test_param)
        #self.assertEqual(result, ValueError)

        #self.assertTrue(isinstance(result, ValueError))

        self.assertIsInstance(result, ValueError)


    def test_do_stuff4(self):

        test_param = None
        result = example1.do_stuff(test_param)
        self.assertEqual(result, 'Please enter Number')


    def test_do_stuff3(self):

        test_param = ''
        result = example1.do_stuff(test_param)

        self.assertEqual(result, 'Please enter Number')

    def tearDown(self):
        print('cleaning up')
if __name__ == "__main__":

    unittest.main()