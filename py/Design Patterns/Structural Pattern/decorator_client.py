
from decorator import Window, BorderDecorator, VerticalSBDecorator, HorizontalSBDecorator


w = Window()
w.build()


print('================================')


wb = BorderDecorator(w)
wb.build()


print("=================================")


wbv = VerticalSBDecorator(wb)
wbv.build()


print("=================================")


best_window = HorizontalSBDecorator(wbv)
best_window.build()
