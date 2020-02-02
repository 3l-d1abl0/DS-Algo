from .abs_auto import AbsAuto


class FordFocus(AbsAuto):
    def start(self):
        print('Cool Ford Focus Running !')

    def stop(self):
        print('Ford Focus shutting down !')