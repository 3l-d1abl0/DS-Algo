import os
import sys
import time
import shlex
import shutil
import pytest
import subprocess
from pathlib import Path

class ClassTest(object):

    testfolder_path = "/tmp/testfolder_{}".format(str(os.environ.get("PYTEST_XDIST_WORKER")))

    @pytest.fixture(scope="function", autouse=True)
    def temp_folder(self, request):
        print("Setup")
        if not os.path.exists(self.testfolder_path):
            os.mkdir(self.testfolder_path)

        def fin():
            print("Teardown")
            if os.path.exists(self.testfolder_path):
                shutil.rmtree(self.testfolder_path)

        request.addfinalizer(fin)

    def expensive_operation(self):
        time.sleep(1)

    def test_list_empty_folder(self):

        result = subprocess.run(['ls', self.testfolder_path], stdout=subprocess.PIPE)
        print(str(result.stdout))
        assert not result.stdout, "Error while listing folder"
        

    #@pytest.mark.usefixtures("afixture")
    def test_simple_ls(self):

        Path(self.testfolder_path+"/first.txt").touch()
        result = subprocess.run(['ls', self.testfolder_path], stdout=subprocess.PIPE)
        print('Result: [{}]'.format(result))
        assert 'first.txt' in str(result.stdout), "Error while listing a folder with one file !"

        

    def test_list_multiple_files(self):
        self.expensive_operation()
        Path(self.testfolder_path+"/first.txt").touch()
        Path(self.testfolder_path+"/second.doc").touch()
        result = subprocess.run(['ls', self.testfolder_path], stdout=subprocess.PIPE)
        print('Result: [{}]'.format(result))
        assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
        assert 'second.doc' in str(result.stdout), "Error while listing a folder with multiple !"


    def test_list_hidden_files(self):
        self.expensive_operation()
        Path(self.testfolder_path+"/first.txt").touch()
        Path(self.testfolder_path+"/.hidden_file").touch()
        result = subprocess.run(['ls', '-a', self.testfolder_path], stdout=subprocess.PIPE)
        print('Result: [{}]'.format(result))
        #assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
        assert '.hidden_file' in str(result.stdout), "Error while listing hidden files in a folder !"


    #Method 1
    @pytest.mark.skipif(not sys.platform.startswith("win"), reason="Skipping windows-only test !")
    def test_ls_windows(self):

        '''Method 2
        if not sys.platform.startswith("win"):
            pytest.skip("Skipping windows only test")
        '''
        self.expensive_operation()
        Path("c:\testfolder\first.txt").touch()
        result = subprocess.run(['dir', 'c:\testfolder'], stdout=subprocess.PIPE)
        print('Result: [{}]'.format(result))
        assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"


    #Expected failure, deliberate fail
    @pytest.mark.notpassing
    @pytest.mark.xfail(reason="-y parameter does not work !")
    def test_expected_fail(self):

        Path(self.testfolder_path+"/first.txt").touch()
        result = subprocess.run(['ls', '-y', self.testfolder_path], stdout=subprocess.PIPE)
        print('Result: [{}]'.format(result))
        assert 'first.txt' in str(result.stdout), "-y parameter not implemented Yet !"
        

    #paramaterized test, each test is tested independednet of each other
    @pytest.mark.parametrize("argument", ["","-r","-t","-rt"])
    #"argument" -> argument variable, [] -> actual params values
    def test_order(self, argument):

        Path(self.testfolder_path+"/first.txt").touch()
        time.sleep(0.5)
        Path(self.testfolder_path+"/second.txt").touch()

        command = ['ls', argument, self.testfolder_path]
        argument = ' '.join(x for x in command if x !='')

        print("argument = ", argument)
        result = subprocess.run( shlex.split(argument), stdout=subprocess.PIPE)
        print(result.stdout.decode("utf-8"))
        assert result.stdout.decode("utf-8").startswith("first.txt" if argument not in ["-rt", "-t"] else "second.txt"), "Output ls with -rt argument was Wrong !"


# python -m pytest tests.py -k “WindowsTest”
@pytest.mark.skipif(not sys.platform.startswith("win"), reason="skipping windows only test")
class WindowsTest(object):

    @staticmethod
    @pytest.mark.notpassing
    def test_ls_windows():
        try:

            os.mkdir("c:\testfolder")
            Path("c:\testfolder\first.txt").touch()
            result = subprocess.run(['dir', 'c:\testfolder'], stdout=subprocess.PIPE)
            print("Result: [{}]".format(result))
            assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
        finally:
            shutil.rmtree("c:\testfolder")

