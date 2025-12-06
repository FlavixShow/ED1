#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define QUANT_USERS 100
#define INT " %i"
#define FLT " %f"
#define CHA " %c"
#define STR " %[^\n]s"

typedef struct{
	int id;
	char username[100];
	char nome[100];
	char senha[100];
}Usuario;

typedef struct{
	Usuario usuarios[QUANT_USERS];
	int cont;
}DsUsuarios;

typedef struct{
	int id;
	int user_id;
	char conteudo[500];
	char nomeU[100];
}Post;

typedef struct{
	Post posts[200];
	int cont;
	int cont_hist;
}DsPosts;


DsUsuarios criaBase(){
	DsUsuarios base;
	base.cont = 0;
	return base;
}

DsPosts criaBasePost(){
	DsPosts posts;
	posts.cont = 0;
	posts.cont_hist = 1;
	return posts;
}

void input(char tipo[], char texto[], void* var){
	printf("%s", texto);
	scanf(tipo, var);
}

void alert(char texto[]){
	printf("%s Pressione ENTER...", texto);
	while(getchar() != '\n');
	getchar();
	system("clear");
}

int interfaceEntrada(){
	int esc;
	do{
		printf("=REDE SOCIAL=\n");
		printf("1 - Novo Usuário\n");
		printf("2 - Login\n");
		printf("3 - Fechar Aplicação\n");
		input(INT, "Escolha: ", &esc);

		if(esc < 1 || esc > 3){
			alert("Entrada inválida.");
		}
	}while(esc < 1 || esc > 3);
	system("clear");
	return esc;
}

int interfaceLogado(Usuario* usuario){
	int esc;
	do{
		printf("Seja Bem Vindo(a) <<<%s>>>\n", usuario->nome);
		printf("4 - Novo Post\n");
		printf("5 - Timeline\n");
		printf("6 - Profile\n");
		printf("7 - Excluir post\n");
		printf("8 - Alterar dados do usuário\n");
		printf("9 - Logout\n");
		input(INT, "Escolha: ", &esc);

		if(esc < 4 || esc > 9){
			alert("Entrada inválida.");
		}
	}while(esc < 4 || esc > 9);
	system("clear");
	return esc;
}

int interface(int logado, Usuario* usuario){
	if(!logado)
		return interfaceEntrada();
	else
		return interfaceLogado(usuario);
}


int verificaUsername(char username[]){
	for(int i = 0; i < strlen(username); i++){
		if(username[i] == ' '){
			return 1;
		}
	}
	return 0;
}

void novoUsuario(DsUsuarios* base){
	base->usuarios[base->cont].id = base->cont+1;
	do{
		printf("=CADASTRO=\n");
		input(STR,"Insira o username (sem espaços): ", base->usuarios[base->cont].username);
		if(verificaUsername(base->usuarios[base->cont].username)){
			alert("Entrada inválida.");
			continue;
		};
		break;
	}while(1);
	input(STR,"Insira o nome: ", base->usuarios[base->cont].nome);
	input(STR,"Insira a senha: ", base->usuarios[base->cont].senha);
	base->cont += 1;
	system("clear");
}

Usuario* login(int* logado, DsUsuarios* base){
	char username[100], senha[100];
	printf("LOGIN\n");
	input(STR, "Digite o username: ", username);
	input(STR, "Digite a senha: ", senha);
	
	for(int i = 0; i < base->cont; i++){
		if(!strcmp(base->usuarios[i].username, username))
			if(!strcmp(base->usuarios[i].senha, senha)){
				*logado = 1;
				system("clear");
				return &base->usuarios[i];
			}
	}
	alert("Credenciais inválidas");
	system("clear");
	return NULL;
}

void ordena(DsPosts* base){
	for(int i = 1; i < base->cont; i++){
		Post temp = base->posts[i];
		int j = i - 1;
		
		while(j >= 0 && temp.id > base->posts[j].id){
			base->posts[j + 1] = base->posts[j];
			j--;
		}
		base->posts[j + 1] = temp;
	}
	
}

void novoPost(Usuario usuario, DsPosts* base){
	base->posts[base->cont].id += base->cont_hist;
	base->posts[base->cont].user_id = usuario.id;
	strcpy(base->posts[base->cont].nomeU, usuario.nome);
	printf("Faça a Postagem\n\n");
	input(STR, "Digite: ", base->posts[base->cont].conteudo);
	base->cont += 1;
	base->cont_hist +=1;
	ordena(base);
	printf("\n");
}

void timeline(DsPosts base){
	for(int i = 0; i < base.cont; i++){
		printf("Usuário %s diz:\n%s\n\n", base.posts[i].nomeU, base.posts[i].conteudo);
	}
}

void profile(Usuario usuario, DsPosts base){
	for(int i = 0; i < base.cont; i++){
		if(base.posts[i].user_id == usuario.id)
			printf("Usuário %s diz:\n%s\nId do post: %i\n\n", base.posts[i].nomeU, base.posts[i].conteudo, base.posts[i].id);
	}
}


void excluirPost(Usuario usuario, DsPosts* base){
	printf("EXCLUIR POST\n");
	profile(usuario, *base);
	int id;
	input(INT, "Informe o Id do post: ", &id);
	for(int i = 0; i < base->cont; i++){
		if(usuario.id == base->posts[i].user_id && id == base->posts[i].id){
			for(int j = i; j < base->cont; j++){
				base->posts[j] = base->posts[j+1];
			}
			base->cont -= 1;
			alert("Post Excluido.");
			return;
		}
	}
	alert("Post Inexistente.");
}

void alterarPosts(Usuario usuario, DsPosts* base){
	for(int i = 0; i < base->cont; i++){
		if(usuario.id == base->posts[i].user_id){
			strcpy(base->posts[i].nomeU, usuario.nome);
		}	
	}
}

void alterarDadosUsuario(Usuario* usuario, DsPosts* base){
	printf("Alterar Dados (Insira o antigo caso não queira mudar)\n");
	input(STR, "Novo Username: ", usuario->username);
	input(STR, "Novo Nome: ", usuario->nome);
	input(STR, "Nova Senha: ", usuario->senha);
	alterarPosts(*usuario, base);
}

int main(){
	DsUsuarios base_usuarios = criaBase();
	DsPosts base_posts = criaBasePost();
	int logado = 0;
	Usuario* usuarioLogado = NULL;
	do{
		switch(interface(logado, usuarioLogado)){
			case 1: novoUsuario(&base_usuarios);
			break;
			case 2: usuarioLogado = login(&logado, &base_usuarios);
			break;
			case 3: printf("FIM DO PROGRAMA"); return 0;
			break;
			case 4: novoPost(*usuarioLogado, &base_posts);
			break;
			case 5: timeline(base_posts);
			break;
			case 6: profile(*usuarioLogado, base_posts);
			break;
			case 7: excluirPost(*usuarioLogado, &base_posts);
			break;
			case 8: alterarDadosUsuario(usuarioLogado, &base_posts);
			break;
			case 9: logado = 0;
			break;
		}
	}while(1);
}
