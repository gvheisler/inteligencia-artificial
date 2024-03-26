// Environment code for project Almoxarifado.mas2j

import jason.asSyntax.*;
import jason.environment.*;
import jason.asSyntax.parser.*;
import java.util.Random;
import java.util.logging.*;

public class Ambiente extends Environment {

    private Logger logger = Logger.getLogger("Almoxarifado.mas2j."+Ambiente.class.getName());

	private String sortearTamanhoCaixa() {
		Random gerador = new Random();
		
		switch (gerador.nextInt(3)) {
			case 0 : return  "pequena(caixa)";
			case 1 : return  "media(caixa)";
			case 2 : return  "grande(caixa)";
		}
		return "Erro";
	}
	
	private void chegouEnergia() {
		Random gerador = new Random();
		
		if (gerador.nextInt(3) == 0){
			addPercept(Literal.parseLiteral("carregarEnergia"));
		}
		
	}
	
	
    /** Called before the MAS execution with the args informed in .mas2j */
    @Override
    public void init(String[] args) {
        super.init(args);
        
		addPercept(Literal.parseLiteral(sortearTamanhoCaixa()));
    }

    @Override
    public boolean executeAction(String agName, Structure action) {
        if(action.getFunctor().equals("guardarCaixaPequena")) {
			logger.info("Caixa pequena está sendo guardada pelo "+agName);
			removePercept(Literal.parseLiteral("pequena(caixa)"));
		}
		else if(action.getFunctor().equals("guardarCaixaMedia")) {
			logger.info("Caixa média está sendo guardada pelo "+agName);
			removePercept(Literal.parseLiteral("media(caixa)"));
		}
		else if(action.getFunctor().equals("guardarCaixaGrande")) {
			logger.info("Caixa grande está sendo guardada pelo "+agName);
			removePercept(Literal.parseLiteral("grande(caixa)"));
		}
		else if(action.getFunctor().equals("empilharCaixaGrande")) {
			logger.info("Caixa grande está sendo empilhada pelo "+agName);
			removePercept(Literal.parseLiteral("grande(caixa)"));
		}
		
		
		
		try {
			Thread.sleep(1000);
		} catch (Exception e) {
			logger.info("Erro no sleep");
		}
		
		//adiciona uma percepção
		addPercept(Literal.parseLiteral(sortearTamanhoCaixa()));
		
		chegouEnergia();
		
		
        return true; // the action was executed with success
    }

    /** Called before the end of MAS execution */
    @Override
    public void stop() {
        super.stop();
    }
}

