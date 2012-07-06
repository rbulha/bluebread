# -*- coding: utf-8 -*-
'''
Created on 15/02/2011

@author: Rogerio Bulha Siqueira
'''
import threading
from threading import Thread

class CBasicThread(Thread):
    def __init__(self, indentificador, parent=None):
        Thread.__init__(self)
        self.id = indentificador
        self.parent = parent
        self.keepGoing = self.running = False
        self.event = threading.Event()
        self.event.clear()

    def startup(self):
        self.keepGoing = self.running = True
        #self.thread_id = thread.start_new_thread(self.run, ())
        self.start()
        
    def stop(self):
        self.keepGoing = self.running = False
        
    def wait(self, timeout):  
        self.event.wait(timeout) 

    def IsRunning(self):
        return self.running

    def run(self):
        print 'rodando virtual'
