+~trancada(porta): true
	<- .send(porteiro,achieve,trancada(porta)).
	
+trancada(porta): true
	<- .print("Obrigado por trancar a porta").
