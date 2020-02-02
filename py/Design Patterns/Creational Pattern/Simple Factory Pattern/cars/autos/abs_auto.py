import abc

class AbsAuto(object):

    __metaclass__ = abc.ABCMeta

    #@abc.abstractclassmethod
    @abc.abstractmethod
    def start(self):
        pass

    #@abc.abstractclassmethod
    @abc.abstractmethod
    def stop(self):
        pass