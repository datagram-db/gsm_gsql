__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"
class uniqueId:
    def __init__(self):
        self.int = dict()
        self.n = 0

    def setOrGet(self, x):
        if x in self.int:
            return self.int[x]
        else:
            self.int[x] = self.n
            self.n = self.n +1
            return self.n -1