import os
import sys
import time
import shlex
import shutil
import pytest
import subprocess
from pathlib import Path

class ClassTest(object):

    @staticmethod
    def test_list_empty_folder():
        try:
            os.mkdir("/tmp/testfolder")
            result = subprocess.run(['ls', '/tmp/testfolder'], stdout=subprocess.PIPE)
            print(str(result.stdout))
            assert not result.stdout, "Error while listing folder"
        finally:
            shutil.rmtree("/tmp/testfolder")

    @staticmethod
    def test_simple_ls():
        try:
            os.mkdir("/tmp/testfolder")
            Path("/tmp/testfolder/first.txt").touch()
            result = subprocess.run(['ls', '/tmp/testfolder'], stdout=subprocess.PIPE)
            print('Result: [{}]'.format(result))
            assert 'first.txt' in str(result.stdout), "Error while listing a folder with one file !"
        finally:
            shutil.rmtree('/tmp/testfolder')

    @staticmethod
    def test_list_multiple_files():
        try:
            os.mkdir("/tmp/testfolder")
            Path("/tmp/testfolder/first.txt").touch()
            Path("/tmp/testfolder/second.doc").touch()
            result = subprocess.run(['ls', '/tmp/testfolder'], stdout=subprocess.PIPE)
            print('Result: [{}]'.format(result))
            assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
            assert 'second.doc' in str(result.stdout), "Error while listing a folder with multiple !"
        finally:
            shutil.rmtree('/tmp/testfolder')


    @staticmethod
    def test_list_hidden_files():
        try:
            os.mkdir("/tmp/testfolder")
            Path("/tmp/testfolder/first.txt").touch()
            Path("/tmp/testfolder/.hidden_file").touch()
            result = subprocess.run(['ls', '-a', '/tmp/testfolder'], stdout=subprocess.PIPE)
            print('Result: [{}]'.format(result))
            #assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
            assert '.hidden_file' in str(result.stdout), "Error while listing hidden files in a folder !"
        finally:
            shutil.rmtree('/tmp/testfolder')

    
    @staticmethod
    #Method 1
    @pytest.mark.skipif(not sys.platform.startswith("win"), reason="Skipping windows-only test !")
    def test_ls_windows():

        '''Method 2
        if not sys.platform.startswith("win"):
            pytest.skip("Skipping windows only test")
        '''

        try:
            os.mkdir("c:\testfolder")
            Path("c:\testfolder\first.txt").touch()
            result = subprocess.run(['dir', 'c:\testfolder'], stdout=subprocess.PIPE)
            print('Result: [{}]'.format(result))
            assert 'first.txt' in str(result.stdout), "Error while listing a folder with multiple !"
        finally:
            shutil.rmtree("c:\testfolder")


    #Expected failure, deliberate fail
    @staticmethod
    @pytest.mark.xfail(reson="-y parameter does not work !")
    def test_expected_fail():

        try:
            os.mkdir("/tmp/testfolder")
            Path("/tmp/testfolder/first.txt").touch()
            result = subprocess.run(['ls', '-y', '/tmp/testfolder'], stdout=subprocess.PIPE)
            print('Result: [{}]'.format(result))
            assert 'first.txt' in str(result.stdout), "-y parameter not implemented Yet !"
        finally:
            shutil.rmtree('/tmp/testfolder')


    #paramaterized test, each test is tested independednet of each other
    @staticmethod
    @pytest.mark.parametrize("argument", ["","-r","-t","-rt"])
    def test_order(argument):
        try:
            os.mkdir("/tmp/testfolder")
            Path("/tmp/testfolder/first.txt").touch()
            time.sleep(0.5)
            Path("/tmp/testfolder/second.txt").touch()

            command = ['ls', argument, '/tmp/testfolder']
            argument = ' '.join(x for x in command if x !='')

            result = subprocess.run( shlex.split(argument), stdout=subprocess.PIPE)
            print(result.stdout.decode("utf-8"))
            assert result.stdout.decode("utf-8").startswith("first.txt" if argument not in ["-rt", "-t"] else "second.txt"), "Output ls with -rt argument was Wrong !"

        finally:
            shutil.rmtree("/tmp/testfolder")