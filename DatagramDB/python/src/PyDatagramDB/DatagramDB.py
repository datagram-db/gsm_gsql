import os.path
from typing import List, Tuple

import pydatagramdb

class DatagramDB:
    def __init__(self, data:str, query:str, visualizer:str=None, opt_data_schema:str=None, run_script_over_graph:int=-1, full_server_output:bool=True, isSerializationFull:bool=False, conf:List[Tuple[pydatagramdb.SerialisationType,pydatagramdb.SerialisationStyle]]=None, benchmark_log:str=None):
        self.data = str(data) if data is not None else None
        self.isdatafile = os.path.isfile(self.data)
        self.query = str(query) if query is not None else None
        self.run_script_over_graph = run_script_over_graph
        self.full_server_output = full_server_output
        if self.query is not None:
            self.isqueryfile = os.path.isfile(query)
        else:
            self.isdatafile = False
        if visualizer is None:
            self.visualizer = os.path.join("visualizer", "python", "data")
        else:
            self.visualizer = str(visualizer)
        if opt_data_schema is None:
            self.opt_data_schema = ""
        else:
            self.opt_data_schema = str(opt_data_schema)
        if isSerializationFull:
            self.conf = [(pydatagramdb.SerialisationType.OUTPUT_DATA,pydatagramdb.SerialisationStyle.JSON_OUTPUT),
                         (pydatagramdb.SerialisationType.REMOVED_DATA,pydatagramdb.SerialisationStyle.JSON_OUTPUT),
                         (pydatagramdb.SerialisationType.INSERTED_DATA,pydatagramdb.SerialisationStyle.JSON_OUTPUT),
                         (pydatagramdb.SerialisationType.INPUT_DATA,pydatagramdb.SerialisationStyle.JSON_OUTPUT)]
        else:
            if conf is None:
                self.conf = []
            else:
                self.conf = list(conf)
        if benchmark_log is None:
            self.benchmark_log = ""
        else:
            self.benchmark_log = benchmark_log

    def run(self):
        conf = pydatagramdb.Configuration()
        conf.data = pydatagramdb.ConfigurationArguments(self.data, self.isdatafile)
        if self.query is not None:
            conf.query = pydatagramdb.ConfigurationArguments(self.query, self.isqueryfile)
        else:
            conf.query = None
        conf.conf = list(map(lambda x: pydatagramdb.Serialisation(x[0], x[1]), self.conf))
        conf.opt_data_schema = self.opt_data_schema
        conf.output_folder = self.visualizer
        conf.run_script_over_graph = self.run_script_over_graph
        conf.full_server_output = self.full_server_output
        conf.benchmark_log = self.benchmark_log
        env = pydatagramdb.Environment(conf)
        env.run()