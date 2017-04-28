WorkerScript.onMessage = function(msg) {
	if (msg.action == 'addEvent') {
		var data = {'name': msg.name, 'action': msg.actions, 'declencheur': msg.declencheur};
		msg.model.insert(msg.index, data);
		msg.model.sync();   // updates the changes to the list
	}
	else if (msg.action == 'deleteEvent') {
		msg.model.remove(msg.index) ;
		msg.model.sync() ;
	}
	else if (msg.action == 'restartScn') {
		msg.model.clear() ;
		msg.model.sync() ;
	}
}
