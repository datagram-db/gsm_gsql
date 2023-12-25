    var nodes = new vis.DataSet([]);
    var edges = new vis.DataSet([]);

    function makeulli(data) {
        var sub_ul = $('<ul/>');
        $.each(data, function(index, value) {
            // access like value.yourvalue
            var sub_li = $('<li/>');
            sub_li.append(document.createTextNode(value));
            sub_ul.append(sub_li);
        });
        return sub_ul[0];
    }

    function generateFromNode(nodeObject, nodeID, id) {
        var ell = nodeObject.ell;
        var xi = nodeObject.xi;
        var properties = nodeObject.properties;
        //alert(nodeID);
        var node = document.getElementById(id);
        //node.innerHTML = '';

        // Node ID
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Node Id: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode('' + nodeID));
            node.appendChild(pTag);
        }
        // Provenance
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Provenance: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode(nodeObject.provenance));
            node.appendChild(pTag);
        }

        // Labels
        {
            var ellTag = document.createElement("p");
            if (ell.length == 0) {
                var iTag = document.createElement("i");
                iTag.appendChild(document.createTextNode("No Labels"));
                ellTag.appendChild(iTag);
            } else {
                var bTag = document.createElement("b");
                bTag.appendChild(document.createTextNode("Labels: "));
                ellTag.appendChild(bTag);
                ellTag.appendChild(makeulli(ell))
            }
            node.appendChild(ellTag);
        }

        // Values
        {
            var ellTag = document.createElement("p");
            if (xi.length == 0) {
                var iTag = document.createElement("i");
                iTag.appendChild(document.createTextNode("No Values"));
                ellTag.appendChild(iTag);
            } else {
                var bTag = document.createElement("b");
                bTag.appendChild(document.createTextNode("Values: "));
                ellTag.appendChild(bTag);
                ellTag.appendChild(makeulli(xi))
            }
            node.appendChild(ellTag);
        }

        // Properties
        {
            var propTag = document.createElement("p");
            if (Object.keys(properties).length === 0) {
                var iTag = document.createElement("i");
                iTag.appendChild(document.createTextNode("No Properties"));
                propTag.appendChild(iTag);
            } else {
                var table = document.createElement('table');
                $(table).attr('id', 'customers');
                var header = document.createElement('tr');
                var th1 = document.createElement('th');
                $(th1).append("Property");
                var th2 = document.createElement('th');
                $(th2).append("Value");
                header.appendChild(th1);
                header.appendChild(th2);
                table.appendChild(header);
                for (const [key, value] of Object.entries(properties)) {
                    var row = document.createElement('tr');
                    var td1 = document.createElement('td');
                    var td2 = document.createElement('td');
                    $(td1).append("" + key);
                    $(td2).append("" + value);
                    row.appendChild(td1);
                    row.appendChild(td2);
                    table.appendChild(row);
                }
                propTag.appendChild(table);
            }
            node.appendChild(propTag);
        }
    }

    function constructNode(nodeID) {
        generateFromNode(nodes.get(nodeID), nodeID, "contento");
    }

    function generateFromEdge(edgeObject) {
        var node = document.getElementById("contento");
        var properties = edgeObject.properties;
        //node.innerHTML = '';

        // From
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Parent: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode('' + edgeObject.from));
            node.appendChild(pTag);
        }
        // Label
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Label: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode('' + edgeObject.from));
            node.appendChild(pTag);
        }
        // To
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Content: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode('' + edgeObject.to));
            node.appendChild(pTag);
        }
        // Instance
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Instance: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode('' + edgeObject.instance));
            node.appendChild(pTag);
        }
        // Provenance
        {
            var pTag = document.createElement("p");
            var bTag = document.createElement("b");
            bTag.appendChild(document.createTextNode("Provenance: "));
            pTag.appendChild(bTag);
            pTag.appendChild(document.createTextNode(edgeObject.provenance));
            node.appendChild(pTag);
        }

        // Properties
        {
            var propTag = document.createElement("p");
            if (Object.keys(properties).length === 0) {
                var iTag = document.createElement("i");
                iTag.appendChild(document.createTextNode("No Properties"));
                propTag.appendChild(iTag);
            } else {
                var table = document.createElement('table');
                $(table).attr('id', 'customers');
                var header = document.createElement('tr');
                var th1 = document.createElement('th');
                $(th1).append("Property");
                var th2 = document.createElement('th');
                $(th2).append("Value");
                header.appendChild(th1);
                header.appendChild(th2);
                table.appendChild(header);
                for (const [key, value] of Object.entries(properties)) {
                    var row = document.createElement('tr');
                    var td1 = document.createElement('td');
                    var td2 = document.createElement('td');
                    $(td1).append("" + key);
                    $(td2).append("" + value);
                    row.appendChild(td1);
                    row.appendChild(td2);
                    table.appendChild(row);
                }
                propTag.appendChild(table);
            }
            node.appendChild(propTag);
        }
    }

    function constructEdge(edgeID) {
        generateFromEdge(edges.get(edgeID));
    }
    
    var previousSelection = [];
    var previousColor = {};
    
    function arrayEquals(a, b) {
        return Array.isArray(a) &&
        Array.isArray(b) &&
        a.length === b.length &&
        a.every((val, index) => val === b[index]);
    }
    
    function callrow(node) {
        const objects = [];
        var j = 0;
    	var cells = node.getElementsByTagName('td');
    	for (var i = 0; i < cells.length; i++) {
    	  var obj = cells[i];
    	  var a = obj.getElementsByTagName('a');
    	  if (a.length == 1) {
    	      nodes.update({id:parseInt(a[0].textContent), color:"green"});
    	      objects[j++] = a[0].textContent;
    	  }
	}
	if (arrayEquals(previousSelection,objects)) {
	   for (var i = 0; i<objects.length; i++) {
	      let n= nodes.get(parseInt(objects[i]));
	      var col = "#89B6F2";
	       if (n.id in previousColor) {
	          col = previousColor[n.id];
	       }
	       nodes.update({id:parseInt(objects[i]), color:col});
	   }
	   previousSelection = [];
	} else {
	   for (var i = 0; i<previousSelection.length; i++) {
	      let n= nodes.get(parseInt(previousSelection[i]));
	      var col = "#89B6F2";
	       if (n.id in previousColor) {
	          col = previousColor[n.id];
	       } 
               nodes.update({id:parseInt(previousSelection[i]), color:col});
	   }
	   for (var i = 0; i<objects.length; i++) {
	      let n= nodes.get(parseInt(objects[i]));
	      nodes.update({id:parseInt(objects[i]), color:"green"});
	   }
	   previousSelection = objects;
	}
    }

    function draw() {
        $.getJSON("/" + type + "/nodes/" + folder, function(dataNodes) {
            for (var i = 0; i<dataNodes.length; i++) {
                let n = dataNodes[i];
                if (n.hasOwnProperty("color")) {
                   previousColor[n.id] = n.color;
                }
            }
            nodes = new vis.DataSet(dataNodes);
            
            $.getJSON("/" + type + "/edges/" + folder, function(dataEdges) {
                edges = new vis.DataSet(dataEdges);
                var data = {
                    nodes: nodes,
                    edges: edges
                };

                var options = {
                    interaction: {
                        hover: true
                    },
                    nodes: {
                        shape: "dot"
                    }
                    /*,
                              layout: {
                                hierarchical: {
                                  direction: "UD",
                                  sortMethod: "directed",
                                },
                              },
                             physics: {
                                hierarchicalRepulsion: {
                                  avoidOverlap: +1.0
                                }
                              }*/
                };
                var container = document.getElementById("mynetwork");
                var network = new vis.Network(container, data, options);
                network.on('click', function(properties) {
                    if ((properties.edges.length == 1) || (properties.nodes.length == 1)) {
                        var node = document.getElementById("contento");
                        node.innerHTML = '';
                    }

                    if (properties.nodes.length == 1) {
                        var nodeId = properties.nodes[0];
                        constructNode(nodeId);
                    } else if (properties.edges.length == 1) {
                        var edgeId = properties.edges[0];
                        constructEdge(edgeId);
                    }
                });
            });
        });
        $("a").bind("mousemove", function(event) {
            var request = "/input/node/"+folder+"/"+$(this).text();
            $.getJSON( request, function( dataNodes ) {
            	$("#contento2").empty();
                generateFromNode(dataNodes,$(this).text(), "contento2");
                $("div.tooltip").css({
        		top: event.pageY + 10 + "px",
        		left: event.pageX + 10 + "px"
    	        }).show();
            });
	});
	$('.close').bind('click', function(){
  	  $("div.tooltip").fadeOut();
	});
    }
