#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main(void ){
	setlocale(LC_ALL, "Portuguese");
	char cpf[14], nome[30], categoria[4], escolha, escolha2;
	bool executando = true;
	float peso, altura;	
	int idade, op;
	int total = 0, total3km = 0, total5km = 0, total10km = 0;
	int idade3km = 0, idade5km = 0, idade10km = 0;
	int ate18 = 0, de19a35 = 0, de36a50 = 0, acima50 = 0;
	float mediaidade3km = 0, mediaidade5km = 0, mediaidade10km = 0;
	float pesomediototal = 0, peso3km= 0, peso5km= 0, peso10km = 0;
	float alturamediatotal = 0, altura3km = 0, altura5km = 0, altura10km = 0;
	float perc3km = 0, perc5km = 0, perc10km = 0;
	float percidadeate18 = 0, percidadeate35 = 0, percidadeate50 = 0, percidadeacima50 = 0;
		
	printf("=== CADASTRO DE PARTICIPANTES ===");	
	 while(executando == true){
	 	
		printf("\nDigite o CPF do(a) Participante (Com pontuação!): ");
		fflush(stdin);
		gets(cpf);
		
		printf("\nDigite o Nome do(a) Participante:");
		fflush(stdin);
		gets(nome);
		
		do {
			printf("\nDigite a Idade: ");
		fflush(stdin);
		scanf(" %i", &idade);
		if(idade < 10 || idade > 100){
			printf("\nErro: Idade Inválida! Escolha um valor entre 10 e 100.");
		}
		 }while(idade < 10 || idade > 100);
		 
		 if(idade < 18){
		 	ate18 ++;
		 }else if(idade <= 35){
		 	de19a35 ++;
		 }else if(idade <= 50){
		 	de36a50 ++;
		 }else{
		 	acima50 ++;
		 }
	
		do {
		printf("\nDigite o Peso (em kilogramas): ");
		fflush(stdin);
		scanf(" %f", &peso);
		if(peso <= 0){
			printf("\nErro: Peso Inválido! Escolha um valor positivo!");
		}
		}while(peso <= 0);
		
		printf("\nDigite a Altura: ");
		fflush(stdin);
		scanf(" %f", &altura);
		
		do{
		printf("\nSelecione a Categoria: ");
		printf("\n1 - 3KM");
		printf("\n2 -  5KM");
		printf("\n3 - 10km \n");
		fflush(stdin);
		scanf(" %d", &op);
		if(op < 1 || op > 3){
			printf("Erro: Opção Inválida");
		  }
		}while(op < 1 || op > 3);
		
		switch(op){
			case 1 :
				total ++;
				total3km ++;
				idade3km += idade;
				peso3km += peso;
				altura3km += altura;	 
				printf("\nCandidadato Cadastrado com Sucesso! Deseja Cadastrar outro Participante? S - Sim & N - Não\n");
					scanf(" %c", &escolha);
					if(escolha == 'N' || escolha == 'n'){
						executando = false;
					}else if(escolha == 'S' || escolha == 's'){
						executando = true;
						
					}
					
		    	break;
			case 2 :
				total ++;
				total5km ++;
				idade5km += idade;
				peso5km += peso;
				altura5km += altura;
				printf("\nCandidadato Cadastrado com Sucesso! Deseja Cadastrar outro Participante? S - Sim & N - Não\n");
				scanf(" %c", &escolha);
				if(escolha == 'N' || escolha == 'n'){
					executando = false;
				}else if(escolha == 'S' || escolha == 's'){
				executando = true; 
				}
				break;
			case 3:
				total ++;
				total10km ++;
				idade10km += idade;
				peso10km += peso;
				altura10km += altura;
				printf("\nCandidadato Cadastrado com Sucesso! Deseja Cadastrar outro Participante? S - Sim & N - Não\n");
				scanf(" %c", &escolha);
					if(escolha == 'N' || escolha == 'n'){
						executando = false;
					}else if(escolha == 'S' || escolha == 's'){
						executando = true;
					}
				break;
			default:
				break;
		}		
		
					
		}
		
		//calculos
		//media idade
		if(total3km > 0){
			
				mediaidade3km = (float)idade3km / total3km;
		}
		if(total5km > 0){
			
		mediaidade5km = (float)idade5km / total5km;	
		}
		if(total10km > 0){
			
		mediaidade10km = (float)idade10km / total10km;	
		}
		
		
		
		//peso medio
		if(total > 0) {
			pesomediototal = (peso3km + peso5km + peso10km) / total;
		}
	
		
		//altura media
		if(total > 0) {
			alturamediatotal = (altura3km + altura5km + altura10km) / total;
		}
		
		
		//percentual por categoria
		
		if(total > 0){
		perc3km = (float)total3km / total * 100;
		perc5km = (float)total5km / total * 100;	
		perc10km = (float)total10km / total * 100;
		}
		
		
		//percentutal idade
		
		if(total > 0){
			percidadeate18 = (float)ate18 / total * 100;
			percidadeate35 = (float)de19a35 / total * 100;
			percidadeate50 = (float)de36a50 / total * 100;
			percidadeacima50 = (float)acima50 / total * 100;
		}
		
	
		
		
		printf("\n====RELATÓRIO DE PARTICIPANTES====");
		printf("\nTotal de participantes: %i", total);
		printf("\nTotal Inscritos Categoria 3km: %i", total3km);
		printf("\nPorcentagem de Inscritos na Categoria 3km: %.2f", perc3km);
		printf("\n Total Inscritos Categoria 5km: %i", total5km);
		printf("\nPorcentagem de Inscritos na Categoria 5km: %.2f", perc5km);
		printf("\n Total Inscritos Categoria 10km: %i", total10km);
		printf("\nPorcentagem de Inscritos na Categoria 10km: %.2f", perc10km);
		
		printf("\nQuantidade de Corredores até 18 anos: %i", ate18 );
		printf("\nPercentual de Participantes até 18 anos: %.2f", percidadeate18);
		printf("\nQuantidade de Corredores de 19 até 35 anos: %i", de19a35 );
		printf("\nPercentual de Participantes de 19 até 35 anos: %.2f", percidadeate35);
		printf("\nQuantidade de Corredores de 36 até 50 anos: %i", de36a50);
		printf("\nPercentual de Participantes de 36 até 50 anos : %.2f", percidadeate50);
		printf("\nQuantidade de Corredores com 50 anos ou mais: %i", acima50);
		printf("\nPercentual de Participantes acima de 50 anos: %.2f", percidadeacima50);
		
		printf("\nIdade Média da Categoria 3km: %.2f", mediaidade3km);
	    printf("\nIdade Média da Categoria 5km: %.2f", mediaidade5km);
		printf("\nIdade Média da Categoria 10km: %.2f", mediaidade10km);
		
		printf("\nPeso Médio de todos os Participantes: %.2f", pesomediototal);
		
		printf("\nAltura Média de todos os Participantes: %.2f", alturamediatotal);
				
		
		

	
	return 0;
}
