import wx
import os
import sys
import __builtin__
import serial
import time

__builtin__.__dict__['HOMEPATH'] = os.path.abspath(os.path.dirname(sys.argv[0]))

def main():
            port_number = '/dev/tty'
            s = serial.Serial(port_number,timeout=2)
            print '[OnButton_wxButtonConnect] port name: %s'%s.portstr
            #self.wxTextPortName.SetValue(str(s.portstr))
            #time.sleep(5)
            #command_list = str(self.wxTextConfigurationCommand.GetValue())
            #print '[OnButton_wxButtonConnect] configuratin token: ',command_list
            #s.write(command_list)
            #time.sleep(5)
            #com_output = s.read(100)
            #print '[OnButton_wxButtonConnect] port output: ',com_output
            time.sleep(1)
            #serial_number = str(123)
            equip_tag = 'AT\r\n' 
            s.write(equip_tag)   
            time.sleep(5)
            com_output = s.read(10)
            print '[OnButton_wxButtonConnect] port output: ',com_output
            s.close()
                
if __name__ == '__main__':
    main()                                

