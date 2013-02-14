#import wx
import os
import sys
import __builtin__
from serial import Serial
import time
import threading
import thread
from basicthread import CBasicThread

__builtin__.__dict__['HOMEPATH'] = os.path.abspath(os.path.dirname(sys.argv[0]))

class BBSerial(Serial):
    def __init__(self,port):
        Serial.__init__(self,port,baudrate=9600,timeout=2)
        self.interpdudelay = 0.5 
    def writeline(self,line):
        for pdu in line.strip('\r\n'):
            self.write(pdu)
            time.sleep(self.interpdudelay)
        self.write('\r')    
        time.sleep(self.interpdudelay)
        self.write('\n')
        time.sleep(self.interpdudelay)

class SerialReception(CBasicThread):
  def __init__(self, indentificador, parent, serial_port):
    CBasicThread.__init__(self, indentificador, parent)
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

def cmd_discovery():
    if sys.platform == 'win32':
        port_number = 4
    else:
        port_number = '/dev/tty'
    retry_timeout = 3    
    s = Serial(port_number,timeout=2)
    print '[serial monitor] port name: %s'%s.portstr
    reception_thread = SerialReception('reception',None,s)
    reception_thread.startup()
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
            time.sleep(2)
    reception_thread.stop()    
    s.close()
    
def bluetooth_pooling():
    if sys.platform == 'win32':
        port_number = 21
    else:
        port_number = '/dev/tty'
    retry_timeout = 3    
    s = BBSerial(port_number) 
    print '[serial monitor] port name: %s'%s.portstr
    print '[serial monitor] port :',s
    reception_thread = SerialReception('reception',None,s)
    reception_thread.startup()
    counter = 2
    commands = ['AT\r\n','AT+NAME?\r\n','AT+VERS?\r\n','AT+PORT?\r\n','AT+PUBL?\r\n']
    while counter > 0 :
        for i in range(retry_timeout):
            print '[serial monitor] write in %d sec'%(retry_timeout - i)
            time.sleep(1)
        counter = counter - 1
        for cmd in commands:
            print '[serial monitor] write(%d): %s'%(counter,cmd)
            s.writeline(cmd)    
            time.sleep(2)
    reception_thread.stop()  
    reception_thread.join()  
    s.close()
    
                
if __name__ == '__main__':
    #main()
    bluetooth_pooling()                               

