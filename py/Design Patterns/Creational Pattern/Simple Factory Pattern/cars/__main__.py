from autofactory import AutoFactory


factory = AutoFactory()

for carname in 'ChevyVolt', 'FordFocus', 'JeepSahara', 'Falcon X':

    car = factory.create_instance(carname)
    car.start()
    car.stop()


print AutoFactory.__dict__
