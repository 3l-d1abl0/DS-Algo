import os
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