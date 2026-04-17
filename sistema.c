#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ANIMAIS  100
#define MAX_USUARIOS 100

/* ============================================================
   STRUCT: Cadastro de Animal
   ============================================================ */
struct Cadastro {
    char nome[50];
    char endereco[50];
    char email[40];
    char celular[20];
};

/* ============================================================
   STRUCT: Cadastro de Usuario
   - tipo: 1 = Pessoa Fisica, 2 = Pessoa Juridica
   - documento: armazena CPF ou CNPJ dependendo do tipo
   ============================================================ */
struct Usuario {
    char nome[50];
    char email[40];
    char celular[20];
    int  tipo;           // 1 = Fisica, 2 = Juridica
    char documento[20];  // CPF ou CNPJ
};

/* ============================================================
   VARIAVEIS GLOBAIS
   ============================================================ */
struct Cadastro animais[MAX_ANIMAIS];
int totalAnimais = 0;

struct Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

/* ============================================================
   PROTOTIPOS
   ============================================================ */
void cadastrarAnimal();
void listarAnimais();
void cadastrarUsuario();
void listarUsuarios();

/* ============================================================
   MENU PRINCIPAL
   ============================================================ */
int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        printf("\n========================================\n");
        printf("       SISTEMA DE CONTROLE GERAL        \n");
        printf("========================================\n");
        printf("  --- Animais ---\n");
        printf("  1. Cadastrar Animal\n");
        printf("  2. Listar Animais\n");
        printf("  --- Usuarios ---\n");
        printf("  3. Cadastrar Usuario\n");
        printf("  4. Listar Usuarios\n");
        printf("  0. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do teclado

        switch (opcao) {
            case 1: cadastrarAnimal();  break;
            case 2: listarAnimais();    break;
            case 3: cadastrarUsuario(); break;
            case 4: listarUsuarios();   break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ============================================================
   FUNCOES DE ANIMAL (originais, sem alteracao)
   ============================================================ */
void cadastrarAnimal() {
    if (totalAnimais >= MAX_ANIMAIS) {
        printf("Limite de cadastros de animais atingido!\n");
        return;
    }

    struct Cadastro *a = &animais[totalAnimais];

    printf("\n-- Cadastrar Animal --\n");

    printf("Nome: ");
    fgets(a->nome, sizeof(a->nome), stdin);
    a->nome[strcspn(a->nome, "\n")] = '\0';

    printf("Endereco: ");
    fgets(a->endereco, sizeof(a->endereco), stdin);
    a->endereco[strcspn(a->endereco, "\n")] = '\0';

    printf("Email: ");
    fgets(a->email, sizeof(a->email), stdin);
    a->email[strcspn(a->email, "\n")] = '\0';

    printf("Celular: ");
    fgets(a->celular, sizeof(a->celular), stdin);
    a->celular[strcspn(a->celular, "\n")] = '\0';

    totalAnimais++;
    printf("Animal cadastrado com sucesso!\n");
}

void listarAnimais() {
    if (totalAnimais == 0) {
        printf("\nNenhum animal cadastrado.\n");
        return;
    }

    printf("\n-- Lista de Animais --\n");
    for (int i = 0; i < totalAnimais; i++) {
        printf("\nAnimal %d:\n", i + 1);
        printf("  Nome:     %s\n", animais[i].nome);
        printf("  Endereco: %s\n", animais[i].endereco);
        printf("  Email:    %s\n", animais[i].email);
        printf("  Celular:  %s\n", animais[i].celular);
    }
}

/* ============================================================
   FUNCOES DE USUARIO (novas)
   ============================================================ */
void cadastrarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite de cadastros de usuarios atingido!\n");
        return;
    }

    struct Usuario *u = &usuarios[totalUsuarios];

    printf("\n-- Cadastrar Usuario --\n");

    // Nome
    printf("Nome: ");
    fgets(u->nome, sizeof(u->nome), stdin);
    u->nome[strcspn(u->nome, "\n")] = '\0';

    // Email
    printf("Email: ");
    fgets(u->email, sizeof(u->email), stdin);
    u->email[strcspn(u->email, "\n")] = '\0';

    // Celular
    printf("Celular: ");
    fgets(u->celular, sizeof(u->celular), stdin);
    u->celular[strcspn(u->celular, "\n")] = '\0';

    // Tipo de pessoa: Fisica ou Juridica
    printf("Tipo de pessoa:\n");
    printf("  1. Pessoa Fisica\n");
    printf("  2. Pessoa Juridica\n");
    printf("Escolha: ");
    scanf("%d", &u->tipo);
    getchar(); // Limpar buffer

    // Dependendo do tipo, pede CPF ou CNPJ
    if (u->tipo == 1) {
        printf("CPF (somente numeros): ");
        fgets(u->documento, sizeof(u->documento), stdin);
        u->documento[strcspn(u->documento, "\n")] = '\0';
    } else if (u->tipo == 2) {
        printf("CNPJ (somente numeros): ");
        fgets(u->documento, sizeof(u->documento), stdin);
        u->documento[strcspn(u->documento, "\n")] = '\0';
    } else {
        printf("Tipo invalido! Usuario nao cadastrado.\n");
        return; // Cancela o cadastro se tipo invalido
    }

    totalUsuarios++;
    printf("Usuario cadastrado com sucesso!\n");
}

void listarUsuarios() {
    if (totalUsuarios == 0) {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    printf("\n-- Lista de Usuarios --\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("\nUsuario %d:\n", i + 1);
        printf("  Nome:    %s\n", usuarios[i].nome);
        printf("  Email:   %s\n", usuarios[i].email);
        printf("  Celular: %s\n", usuarios[i].celular);

        // Exibe o tipo e o documento correspondente
        if (usuarios[i].tipo == 1) {
            printf("  Tipo:    Pessoa Fisica\n");
            printf("  CPF:     %s\n", usuarios[i].documento);
        } else {
            printf("  Tipo:    Pessoa Juridica\n");
            printf("  CNPJ:    %s\n", usuarios[i].documento);
        }
    }
}
