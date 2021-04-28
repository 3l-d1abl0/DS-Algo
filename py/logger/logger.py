import logging


'''
logging.DEBUG -> 10
logging.INFO ->20
logging.WARNING -> 30
'''

#logging.basicConfig(level=logging.DEBUG)
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(levelname)s: %(message)s', datefmt='%m/%d/%Y %I:%M:%S %p')

#logging.basicConfig(level=logging.DEBUG, filename='example.log', filemode ='a')

logging.debug('Ignored !')
logging.info('This should be logged')
logging.warning('And this , too')
