#import wx
import os
import sys
import __builtin__
import serial
import time
import threading
import thread

__builtin__.__dict__['HOMEPATH'] = os.path.abspath(os.path.dirname(sys.argv[0]))

class BasicThread:
    def __init__(self):
        self.keepGoing = self.running = False
        self.event = threading.Event()
        self.event.clear()

    def start(self):
        self.keepGoing = self.running = True
        thread.start_new_thread(self.run, ())

    def stop(self):
        self.keepGoing = self.running = False
        
    def wait(self, timeout):  
        self.event.wait(timeout) 

    def IsRunning(self):
        return self.running

    def run(self):
        print 'rodando virtual'

class SerialReception(BasicThread):
  def __init__(self, indentificador, parent, serial_port):
    BasicThread.__init__(self)
    self.id = indentificador
    self.parent = parent
    self.serial_port = serial_port
    self.Waiting = True
    print "init thread: ", self.id
  def run(self):
    print 'running dialog, ',self.id 
    count = 3
    self.Waiting = True 
    while self.IsRunning() and self.Waiting:
        self.com_output = self.serial_port.readline(256)
        if len(self.com_output) > 0:
            print '[serial monitor] ***>>> output: [%s]'%self.com_output.strip(' \r\n')

def main():
    if sys.platform == 'win32':
        port_number = 4
    else:
        port_number = '/dev/tty'
    retry_timeout = 3    
    s = serial.Serial(port_number,timeout=2)
    print '[serial monitor] port name: %s'%s.portstr
    reception_thread = SerialReception('reception',None,s)
    reception_thread.start()
    counter = 10
    commands = ['$$$\r\n','AT\r\n','AT+NAME?\r\n','AT','AT+NAME','+++\r\n','AT\r\n','AT+NAME?\r\n']
    while counter > 0 :
        for i in range(retry_timeout):
            print 'write in %d sec'%(retry_timeout - i)
            time.sleep(1)
        counter = counter - 1
        for cmd in commands:
            print '[serial monitor] write(%d): %s'%(counter,cmd)
            s.write(cmd)    
            time.sleep(1)
    reception_thread.stop()    
    s.close()
    
def bluetooth_pooling():
    if sys.platform == 'win32':
        port_number = 4
    else:
        port_number = '/dev/tty'
    retry_timeout = 3    
    s = serial.Serial(port_number,timeout=2)
    print '[serial monitor] port name: %s'%s.portstr
    reception_thread = SerialReception('reception',None,s)
    reception_thread.start()
    counter = 10
    commands = ['a','t','v']
    while counter > 0 :
        for i in range(retry_timeout):
            print '[serial monitor] write in %d sec'%(retry_timeout - i)
            time.sleep(2)
        counter = counter - 1
        for cmd in commands:
            print '[serial monitor] write(%d): %s'%(counter,cmd)
            s.write(cmd)    
            time.sleep(1)
    reception_thread.stop()    
    s.close()
    
                
if __name__ == '__main__':
    #main()
    bluetooth_pooling()                               

