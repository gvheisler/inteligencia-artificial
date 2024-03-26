// Environment code for project Quarto.mas2j

import jason.asSyntax.*;
import jason.environment.*;
import jason.asSyntax.parser.*;

import java.util.logging.*;

public class Ambiente extends Environment {

	Literal trancada = Literal.parseLiteral("trancada(porta)");
	Literal destrancada = Literal.parseLiteral("~trancada(porta)");


    /** Called before the MAS execution with the args informed in .mas2j */
    @Override
    public void init(String[] args) {
        addPercept(trancada);
    }

    @Override
    public boolean executeAction(String agName, Structure action) {
		System.out.println("Agente: "+agName+" - Ação: "+action);
        clearPercepts();
		
		if(action.getFunctor().equals("trancar")) {
			addPercept(trancada);
		}
		if(action.getFunctor().equals("destrancar")) {
			addPercept(destrancada);
		}
		
		
        return true; // the action was executed with success
    }

    /** Called before the end of MAS execution */
    @Override
    public void stop() {
        super.stop();
    }
}

