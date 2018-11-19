#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Usuario{
	char login[20], senha[15];
}UsuarioCad;

typedef struct Vendedor{
	char nome[20], cpf[20], mat[20];
	struct Usuario usu; 
}VendedorCad;
	
typedef struct Cliente{
	char nome[20], telefone[20];
	struct Usuario usu; 
}ClienteCad;

typedef struct Produto{
	char descricao[20];
	float preco;
}ProdutoCad;

//chamada de Procedimentos
void cadastroVendedor();
void cadastroCliente();
void cadastroProduto();
void validaLogin();
void menuAdministrador();
void menuVendedor();
void menuCliente(ClienteCad cli);
void listarProdutos();
void listarClientes();
void listarDadosCliente(ClienteCad cli);
//Chamada de Funções
int verificaLoginDuplicado(char login[20], char senha[20]);

//Chamada de Arquivos Globais
FILE *vendedor;
FILE *produto;
FILE *cliente;

int main(){
	
	validaLogin();
	
}

//Procedimento Cadastro de Vndedores
void cadastroVendedor(){
	
	if(vendedor!=NULL){
		VendedorCad vend;	
		int verificador = 1;
		
		printf("----------------------------------------------\n\tCadastro de Vendedores\n----------------------------------------------\n\n");
		printf(" Informe os dados do vendedor\n");
		printf(" Nome: ");
		fflush(stdin);
		gets(vend.nome);
		printf(" CPF: ");
		fflush(stdin);
		gets(vend.cpf);
		printf(" Matricula: ");
		fflush(stdin);
		gets(vend.mat);
		
		do{
			printf("\n\n Informe dados para Acesso ao sistema\n----------------------------------------------\n");
			printf(" Login: ");
			fflush(stdin);
			gets(vend.usu.login);
			printf(" Senha: ");
			fflush(stdin);
			gets(vend.usu.senha);
		
			if (verificaLoginDuplicado(vend.usu.login, vend.usu.senha) == 1){
				printf("\n\n ATENCAO!\n Login ja utilizado. Informe novamente os dados!\n ");
				verificador = 1;
			}else{
				verificador = 0;
			}
		}while(verificador == 1);
		
		vendedor = fopen("vendedor.txt","a+");
		fprintf(vendedor,"%s\n%s\n%s\n%s\n%s\n",vend.nome,vend.cpf,vend.mat,vend.usu.login,vend.usu.senha);
		fclose(vendedor);
		printf("\n\n Cadastro realizado com sucesso!\n ");
		system("pause");
		system("cls");
	}else{
		printf(" Erro: Arquivo inexitente!\n ");
		system("pause");
	}
	
}

//Procedimento Cadastro de Clientes
void cadastroCliente(){
	if(cliente!=NULL){
		ClienteCad cli;	
		int verificador = 1;
		
		printf("----------------------------------------------\n\tCadastro de CLientes\n----------------------------------------------\n\n");
		printf(" Informe os dados do Cliente\n");
		printf(" Nome: ");
		fflush(stdin);
		gets(cli.nome);
		printf(" Telefone: ");
		fflush(stdin);
		gets(cli.telefone);
		
		do{
			printf("\n\n Informe dados para Acesso ao sistema\n----------------------------------------------\n");
			printf(" Login: ");
			fflush(stdin);
			gets(cli.usu.login);
			printf(" Senha: ");
			fflush(stdin);
			gets(cli.usu.senha);
		
			if (verificaLoginDuplicado(cli.usu.login, cli.usu.senha) == 1){
				printf("\n\n ATENCAO!\n Login ja utilizado. Informe novamente os dados!\n ");
				verificador = 1;
			}else{
				verificador = 0;
			}
		}while(verificador == 1);
		
		cliente = fopen("cliente.txt","a+");
		fprintf(cliente,"%s\n%s\n%s\n%s\n",cli.nome,cli.telefone,cli.usu.login,cli.usu.senha);
		fclose(cliente);
		printf("\n\n Cadastro realizado com sucesso!\n ");
		system("pause");
		system("cls");
	}else{
		printf("Erro: Arquivo inexitente!\n ");
		system("pause");
	}
	
}

//Procedimento Cadastro de Produtos
void cadastroProduto(){
	produto = fopen("produto.txt","a+");
	if(produto!=NULL){
		ProdutoCad prod;	
		printf("----------------------------------------------\n\tCadastro de Produtos\n----------------------------------------------\n\n");
		printf(" Informe os dados do Produto\n");
		printf(" Descricao: ");
		fflush(stdin);
		gets(prod.descricao);
		do{
			printf(" Preco R$: ");
			scanf("%f",&prod.preco);
			if(prod.preco <=0){
				printf("\n Preco do produto invalido! Informe outro valor.\n\n");
			}
		}while(prod.preco <=0);
		fprintf(produto,"%s\n%f\n",prod.descricao,prod.preco);
		fclose(produto);
		printf("\n\n Cadastro realizado com sucesso!\n ");
		system("pause");
		system("cls");
	}else{
		printf(" Erro: Arquivo inexitente!\n ");
		system("pause");
	}
	
}


void menuAdministrador(){
	int opcao;
	do{
		system("cls");
		printf("----------------------------------------------\n\tMenu de Opcoes - ADMINISTRADOR\n----------------------------------------------");
		printf("\n\n [ 1 ] Cadastro de Vendedores\n [ 2 ] Cadastro de Clientes\n [ 3 ] Cadastro de Produtos\n [ 4 ] Listagem de Produtos\n [ 5 ] Listagem de Clientes\n [ 0 ] Sair\n\n Opcao: ");
		
		scanf("%d",&opcao);
	
		switch(opcao){
			case 1:
				system("cls");
				cadastroVendedor();
				break;
			case 2:
				system("cls");
				cadastroCliente();
				break;
			case 3:
				system("cls");
				cadastroProduto();
				break;
			case 4:
				system("cls");
				listarProdutos();
				break;
			case 5:
				system("cls");
				listarClientes();
				break;
			case 0:
				system("cls");
				main();
				exit(0);
				break;
			
		}
		if ((opcao < 0) || (opcao > 5)){
	        printf("\n Opcao invalida!\n ");
			system("pause");	
		}
	}while(opcao !=0);
}


void menuVendedor(){
	int opcao;
	do{
		system("cls");
		printf("----------------------------------------------\n\tMenu de Opcoes - VENDEDOR\n----------------------------------------------");
		printf("\n\n [ 1 ] Cadastro de Produtos\n [ 2 ] Listagem de Produtos\n [ 3 ] Cadastro de Clientes\n [ 4 ] Listagem de Clientes\n [ 0 ] Sair\n\n Opcao: ");
		scanf("%d",&opcao);
	
		switch(opcao){
			case 1:
				system("cls");
				cadastroProduto();
				break;
			case 2:
				system("cls");
				listarProdutos();
				break;
			case 3:
				system("cls");
				cadastroCliente();
				break;
			case 4:
				system("cls");
				listarClientes();
				break;
			case 0:
				system("cls");
				main();
				exit(0);
				break;
			
		}
		if ((opcao < 0) || (opcao > 4)){
	          	printf("\n Opcao invalida!\n ");
				system("pause");
				
		
		}
	}while(opcao !=0);
}

void menuCliente(ClienteCad cli){
	int opcao;
	do{
		system("cls");
		printf("----------------------------------------------\n\tMenu de Opcoes - CLIENTE\n----------------------------------------------");
		printf("\n\n [ 1 ] Listagem de Produtos \n [ 2 ] Listar Dados do Cliente\n [ 0 ] Sair\n\n Opcao: ");
		scanf("%d",&opcao);
	
		switch(opcao){
			case 1:
				system("cls");
				listarProdutos();
				break;
			case 2:
				system("cls");
				listarDadosCliente(cli);
				break;
			case 0:
				system("cls");
				main();
				exit(0);
				break;
			
		}
		if ((opcao < 0) || (opcao > 2)){
	          	printf("\n Opcao invalida!\n ");
				system("pause");
				
		
		}
	}while(opcao !=0);
}

void listarProdutos(){
	
	ProdutoCad prod;
	produto = fopen("produto.txt","r");
	
	printf("----------------------------------------------\n\tListagem de Produtos Cadastrados\n----------------------------------------------\n");
	if(produto!=NULL){
		rewind(produto);
		while((fscanf(produto,"%s\n%f\n", &prod.descricao,&prod.preco))!=EOF ){
			printf("\n Descricao: %s\n Preco R$: %.2f\n ",prod.descricao,prod.preco);
		}
		system("pause");
		fclose(produto);
			
	}else{
		printf(" Nao ha Produtos cadastrados ou Arquivo inexitente!\n ");
		system("pause");
	}		
}

//Lista dados do cliente
void listarDadosCliente(ClienteCad cliDados){
	
	ClienteCad cli;
	cliente = fopen("cliente.txt","r");
	
	printf("----------------------------------------------\n\tDados do Cliente\n----------------------------------------------\n");
	if(cliente!=NULL){
		rewind(cliente);
		while((fscanf(cliente,"%s\n%s\n%s\n%s\n", &cli.nome,cli.telefone,cli.usu.login,cli.usu.senha))!=EOF ){
			if((strcmp(cliDados.usu.login,cli.usu.login)==0) && (strcmp(cliDados.usu.senha,cli.usu.senha)==0)){
				printf(" Nome: %s\n Telefone: %s\n Usuario: %s\n Senha: %s\n\n ",cli.nome,cli.telefone,cli.usu.login,cli.usu.senha);
			}
		}
		system("pause");
		fclose(cliente);
		
	}else{
		printf(" Nao ha Cliente cadastrados ou Arquivo inexitente!\n ");
		system("pause");
	}		
}

//Listagem de  cliente
void listarClientes(){
	
	ClienteCad cli;
	cliente = fopen("cliente.txt","r");
	
	printf("----------------------------------------------\n\tListagem de Clientes\n----------------------------------------------\n");
	if(cliente!=NULL){
		rewind(cliente);
		while((fscanf(cliente,"%s\n%s\n%s\n%s\n", &cli.nome,cli.telefone,cli.usu.login,cli.usu.senha))!=EOF ){
			printf("\n Nome: %s\n Telefone: %s\n ",cli.nome,cli.telefone);
		
		}
		system("pause");
		fclose(cliente);
		
	}else{
		printf(" Nao ha Cliente cadastrados ou Arquivo inexitente!\n ");
		system("pause");
	}		
}

//Função verifica login existente 
int verificaLoginDuplicado(char login[20], char senha[20]){
	int verificador = 0; 
	
	VendedorCad vend;
	ClienteCad cli;
	vendedor = fopen("vendedor.txt","r");
	cliente = fopen("cliente.txt","r");
	
	if((strcmp(login,"admin")==0) || (strcmp(login,"ADMIN")==0)){
		verificador = 1;
	}

	if(vendedor!=NULL){
		rewind(vendedor);
		while((fscanf(vendedor,"%s\n%s\n%s\n%s\n%s\n", vend.nome,vend.cpf,vend.mat,vend.usu.login,vend.usu.senha))!=EOF ){
			if((strcmp(login,vend.usu.login)==0)){
				verificador = 1;
				fclose(vendedor);
			}
		}
		fclose(vendedor);	
	}else{
		printf(" Nao ha Vendedores cadastrados ou Arquivo inexitente!\n ");
		system("pause");
	}	
	

	if(cliente!=NULL){
		rewind(cliente);
		while((fscanf(cliente,"%s\n%s\n%s\n%s\n", cli.nome,cli.telefone,cli.usu.login,cli.usu.senha))!=EOF ){
			if((strcmp(login,cli.usu.login)==0)){
				verificador = 1;
				fclose(cliente);
			}
		}
		fclose(cliente);	
	}else{
		printf(" Nao ha Clientes cadastrados ou Arquivo inexitente!\n ");
		system("pause");
	}
	
	return verificador;
}

//Procedimento validacao de login
void validaLogin(){
	char login[20],senha[20];
	int i=0, verificaLogin = 0;
	
	
	do{
		system("cls");
		printf("----------------------------------------------\n\tBEM VINDO AO SISTEMA\n----------------------------------------------\n\n");
		printf("\tInforme os Dados de Acesso\n\n\n");
		printf("\tLogin: ");
		fflush(stdin);
		gets(login);
		printf("\tSenha: ");
		fflush(stdin);
		gets(senha);
		
		VendedorCad vend;
		ClienteCad cli;
		
		vendedor = fopen("vendedor.txt","r");
		cliente = fopen("cliente.txt","r");
		
		if(strcmp(login, "admin") == 0){
			
			if (strcmp(senha, "123") == 0){
					verificaLogin = 1;
					menuAdministrador();
			}else{
				verificaLogin = 0;
				printf("\n\tLogin ou senha incorretos!\n\t");
				system("pause");
				validaLogin();	
			}
		}
		
		
		
		if(strcmp(login, "admin") != 0){
			
			if(vendedor!=NULL){
				rewind(vendedor);
				while(!feof(vendedor)){
					fscanf(vendedor,"%s\n%s\n%s\n%s\n%s\n",vend.nome,vend.cpf,vend.mat,vend.usu.login,vend.usu.senha);
					if((strcmp(login,vend.usu.login)==0) && (strcmp(senha,vend.usu.senha)==0)){
						verificaLogin = 1;
						fclose(vendedor);
						system("cls");
						menuVendedor();
					}
				}	
			}		
			fclose(vendedor);
			
			if(cliente!=NULL){
				rewind(cliente);
				while(!feof(cliente)){
					fscanf(cliente,"%s\n%s\n%s\n%s\n",cli.nome,cli.telefone,cli.usu.login,cli.usu.senha);
					if((strcmp(login,cli.usu.login)==0) && (strcmp(senha,cli.usu.senha)==0)){
						verificaLogin = 1;
						fclose(cliente);
						system("cls");
						menuCliente(cli);
					}
				}	
			}		
			fclose(cliente);
			

			if (verificaLogin == 0){
				printf("\n\tLogin ou senha incorretos!\n\t");
				system("pause");
			}
		}
		
		
	}while(verificaLogin !=1);
	

}
	
