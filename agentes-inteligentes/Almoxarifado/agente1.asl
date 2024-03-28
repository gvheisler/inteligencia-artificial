// Esse agente só guarda caixas pequenas 


+pequena(C) : true
	<- .print("percebi uma caixa pequena e vou guarda-la");
		guardarCaixaPequena.
		
+!media(C) [source(Agente)] : true
	<-
		.print("O ", Agente, " mandou eu guardar uma caixa média");
		guardarCaixaMedia.
