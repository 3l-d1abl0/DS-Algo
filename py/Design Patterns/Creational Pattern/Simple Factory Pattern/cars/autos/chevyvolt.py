from .abs_auto import AbsAuto


class ChevyVolt(AbsAuto):

    def start(self):
        print('Chevrolet Volt Running !')

    def stop(self):
        print('Chevrolet Volt Shutting Down !')