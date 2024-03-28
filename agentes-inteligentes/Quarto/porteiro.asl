

+!trancada(porta)[source(paranoico)] : ~trancada(porta)
	<-
	.print("Vou trancar a porta...");
	.wait(500);
	trancar. //manda pro ambiente a função trancar
	
+!destrancar(porta) [source(claustrofobico)] : trancada(porta)
	<- 
	.print("Vou destrancar a porta...");
	.wait(500);
	destrancar.


