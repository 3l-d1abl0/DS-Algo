'''
Decorator Pattern helps us in adding New features to an existing Object Dynamically,
without Subclassing.

The idea behind Decorator Patter is to Attach additional responsibilities to an object Dynamically.
Decorator provide a flexible alternative to subclassing for extending Functionality.

'''

class WindowInterface:

    def build(self): pass



class Window(WindowInterface):

    def build(self):
        print("Building Window")


class AbstractWindowDecorator(WindowInterface):
    """
    Maintain a reference to a Window Object and define an interface
    that conforms to Window's Interface.
    """

    def __init__(self, window):
        self._window = window


    def build(self): pass



class BorderDecorator(AbstractWindowDecorator):
    def add_border(self):
        print("Adding Border")

    def build(self):
        self.add_border()
        self._window.build()


class VerticalSBDecorator(AbstractWindowDecorator):

    def add_vertical_scroll_bar(self):
        print("Adding Vertical Scroll Bar")

    def build(self):
        self.add_vertical_scroll_bar()
        self._window.build()


class HorizontalSBDecorator(AbstractWindowDecorator):

    def add_horizontal_scroll_bar(self):
        print("Adding Horizontal Scroll Bar")

    def build(self):
        self.add_horizontal_scroll_bar()
        self._window.build()
