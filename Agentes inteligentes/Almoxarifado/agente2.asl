//crença
viagens(5).

+carregarEnergia : viagens(T) & T < 5
	<- 
		.print("Vou me recarregar..");
		X = T + 1;
		-viagens(T);
		+viagens(X).

+media(C) : viagens(T) & T > 0
	<- 
		X = T - 1;
		.print("percebi uma caixa media e vou guarda-la, porem tenho mais ", X, " viagens");
		-viagens(T);
		+viagens(X);
		guardarCaixaMedia.
		
+grande(C) : viagens(T) & T > 0
	<- 
		X = T - 1;
		.print("percebi uma caixa grande e vou guarda-la, porem tenho mais ", X, " viagens");
		-viagens(T);
		+viagens(X);
		guardarCaixaGrande.

+grande(C) : true
	<-
		.print("Percebi uma caixa grande e vou empilhar na entrada")
		empilharCaixaGrande.

		
+media(C) : true
	<- 
		.print("percebi uma caixa media e vou mandar para o agente 1");
		.send(agente1, achieve, media(C)).