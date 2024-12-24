import asyncio
from dataclasses import dataclass
from threading import Thread, Semaphore

from pydatagramdb import DataFormatHandler, DataFormat
import PyDatagramDB.gsm

def thread_reader(self):
    """
    Main method reading the data as a producer thread
    """
    self._writer.callback_reader(self.outPath, self.format, lambda x: self.set_object_to(x))
    self.set_object_to(None) # Stopping the iteration

class gsm_read:
    def __init__(self, outPath: str, format: DataFormat):
        """
        :param outPath: Where to read from the content
        :param format:  Format of the serialization
        """
        self.format = format
        self.outPath = outPath
        self._writer = DataFormatHandler()
        self.object = None
        self.wait_for_reading_next = Semaphore(0)
        self.wait_for_writing_next = Semaphore(0)
        self.producer_thread = Thread(target=lambda : thread_reader(self))

    def set_object_to(self, x):
        self.object = x
        # print(f"releasing as the object #{x.id if x is not None else -1} was set")
        self.wait_for_reading_next.release()
        # print(f"waiting for the obejct to be read")
        self.wait_for_writing_next.acquire()
        # print("I can write the next object")

    def __iter__(self):
        self.producer_thread.start()
        return self

    def __next__(self): # Python 2: def next(self)
        # print("waiting for next object")
        self.wait_for_reading_next.acquire()
        # print("getting the object")
        if self.object is not None:
            copy = self.object
            # print("releasing before returning")
            self.wait_for_writing_next.release()
            # print("releasing was done")
            return copy
        self.wait_for_writing_next.release()
        raise StopIteration