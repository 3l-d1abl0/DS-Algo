from logger_base import Logger


logger = Logger('my.log')
logger.write_log('Logging with classic Singleton Pattern')


logger2 = Logger('myNew.log')
logger2.write_log('Another log record')
logger2.write_log('_+_+_+_+_')

logger.close_log()


with open('my.log', 'r') as f:
    for line in f:
        print(line)
