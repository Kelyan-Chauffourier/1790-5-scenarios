WorkerScript.onMessage = function(msg) {
	if (msg.action == 'addEvent') {
		var data = {'action': msg.name, 'declencheur': msg.type};
		msg.model.insert(msg.index, data);
		msg.model.sync();   // updates the changes to the list
	}
	else if (msg.action == 'deleteEvent') {
		msg.model.remove(msg.index) ;
		msg.model.sync() ;
	}
}
