#include <stdio.h>
#include <locale.h>

int main(void ){
	setlocale(LC_ALL, "Portuguese");
	char cpf[14], nome[30], categoria[4], escolha;
	bool executando = true;
	float peso, altura;	
	int idade, op;
	int total = 0, total3km = 0, total5km = 0, total10km = 0;
	int totalid3km = 0; int totalid5km = 0, totalid10km =0;
	float mediaidade3km, mediaidade5km, mediaidade10km;
	float peso3km, pesomedio3km, peso5km, pesomedio5km, peso10km, pesomedio10km;
	float altura3km, alturamedia3km, altura5km, alturamedia5km, altura10km, alturamedia10km;
		
	printf("=== CADASTRO DE PARTICIPANTES ===");	
	 while(executando == true){
	 	
		printf("\nDigite o CPF do(a) Participante (Com pontuação!):");
		fflush(stdin);
		gets(cpf);
		
		printf("\nDigite o Nome do(a) Participante:");
		fflush(stdin);
		gets(nome);
		
		do {
			printf("\nDigite a Idade:");
		fflush(stdin);
		scanf("%i", &idade);
		if(idade < 10 || idade > 100){
			printf("\nErro: Idade Inválida! Escolha um valor entre 10 e 100.");
		}
		 }while(idade < 10 || idade > 100);
	
		do {
		printf("\nDigite o Peso (em kilogramas):");
		fflush(stdin);
		scanf("%f", &peso);
		if(peso <= 0){
			printf("\nErro: Peso Inválido! Escolha um valor positivo!");
		}
		}while(peso <= 0);
		
		printf("\nDigite a Altura");
		fflush(stdin);
		scanf("%f", &altura);
		
		printf("\nSelecione a Categoria:");
		printf("\n1 - 3KM");
		printf("\n2 -  5KM");
		printf("\n3 - 10km");
		
		switch (op){
			case 1:
				total ++;
				total3km ++;
			    totalid3km += idade;
			    peso3km += peso;
			    altura3km += altura;
			    printf("\nParticipante Cadastrado com sucesso! Deseja Cadastrar um novo? S ou N?");
			    scanf("%c", escolha);
			    if(escolha == 'S'|| escolha == 's'){
			    	executando = true;
				}else if(escolha == 'N' || escolha == 'n'){
					executando == false;
				}
				
				break;
			case 2:
				total ++;
				total5km++;
				totalid5km += idade;
				peso5km += peso;
				altura5km += altura;
				printf("\nParticipante Cadastrado com sucesso! Deseja Cadastrar um novo? S ou N?");
			    scanf("%c", escolha);
			    if(escolha == 'S'||escolha == 's'){
			    	executando = true;
				} else if (escolha == 'N' || escolha == 'n'){
					executando = false;
				}
				
				break;
			case 3:
				total ++;
				total10km ++;
				totalid10km += idade;
				peso10km += peso;
				altura10km += altura;
				printf("\nParticipante Cadastrado com sucesso! Deseja Cadastrar um novo? S ou N?");
			    scanf("%c", escolha);
			    if(escolha == 'S'|| escolha == 's'){
			    	executando = true;
				}else if (escolha == 'N' || escolha == 'n'){
					executando == false;
				}
				
				break;
			default:
			 printf("\nErro: Opção Inválida!");
				break;
					
		}
		}
		
		
		printf("\n====RELATÓRIO DE PARTICIPANTES====");
		printf("\nTotal de participantes: %i", total);
		printf("\n Total Inscritos Categoria 3km: %i", total3km);
		printf("\n Total Inscritos Categoria 5km: %i", total5km);
		printf("\n Total Inscritos Categoria 10km: %i", total10km);
		

	
	return 0;
}
