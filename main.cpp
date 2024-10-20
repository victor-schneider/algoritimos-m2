#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "usuarios.cpp"
#include "tarefas.cpp"
#include "equipes.cpp"
#include "arquivos.cpp"

using namespace std;
using json = nlohmann::json;

// criar equipes e designar ujsuarios e tarefas a elas por id
// impedir de criar usuarios se não existirem equipes

int main() {
    string caminhoUsuarios = "usuarios.json";
    string caminhoTarefas = "tarefas.json";
    string caminhoEquipes = "equipes.json";
    json usuarios = carregarArquivo(caminhoUsuarios);
    json tarefas = carregarArquivo(caminhoTarefas);
    json equipes = carregarArquivo(caminhoEquipes);

    int opcao;

    do {
        cout << "1. Criar Usuário\n2. Listar Usuários\n3. Modificar Usuário\n4. Deletar Usuário\n";
        cout << "5. Criar Tarefa\n6. Listar Tarefas\n7. Modificar Tarefa\n8. Deletar Tarefa\n";
        cout << "0. Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int id;
                string nome, equipe, funcao;
                cout << "ID do Usuário: ";
                cin >> id;
                cin.ignore();
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Equipe: ";
                getline(cin, equipe);
                cout << "Função: ";
                getline(cin, funcao);
                usuarios.push_back(criarUsuario(id, nome, equipe, funcao));
                salvarArquivo(caminhoUsuarios, usuarios);
                break;
            }
            case 2:
                imprimirUsuarios(usuarios);
                break;
            case 3: {
                int id;
                cout << "ID do Usuário a modificar: ";
                cin >> id;
                modificarUsuario(id, usuarios);
                salvarArquivo(caminhoUsuarios, usuarios);
                break;
            }
            case 4: {
                int id;
                cout << "ID do Usuário a deletar: ";
                cin >> id;
                usuarios = deletarUsuario(id, usuarios);
                salvarArquivo(caminhoUsuarios, usuarios);
                break;
            }
            case 5: {
                int id, prioridade;
                string nome, equipe, prazo, status;
                cout << "ID da Tarefa: ";
                cin >> id;
                cin.ignore();
                cout << "Nome da Tarefa: ";
                getline(cin, nome);
                cout << "Equipe designada: ";
                getline(cin, equipe);
                cout << "Prioridade (1-5): ";
                cin >> prioridade;
                cin.ignore();
                cout << "Prazo (YYYY-MM-DD): ";
                getline(cin, prazo);
                cout << "Status: ";
                getline(cin, status);
                tarefas.push_back(criarTarefa(id, nome, equipe, prioridade, prazo, status));
                salvarArquivo(caminhoTarefas, tarefas);
                break;
            }
            case 6:
                imprimirTarefas(tarefas);
                break;
            case 7: {
                int id;
                cout << "ID da Tarefa a modificar: ";
                cin >> id;
                modificarTarefa(id, tarefas);
                salvarArquivo(caminhoTarefas, tarefas);
                break;
            }
            case 8: {
                int id;
                cout << "ID da Tarefa a deletar: ";
                cin >> id;
                tarefas = deletarTarefa(id, tarefas);
                salvarArquivo(caminhoTarefas, tarefas);
                break;
            }
            case 9: {
                int id;
                string nome;
                cout << "ID da equipe: ";
                cin >> id;
                cin.ignore();
                cout << "Nome da equipe: ";
                getline(cin, nome);
                equipes.push_back(criarEquipe(id, nome));
                salvarArquivo(caminhoEquipes, equipes);
            }
        }
    } while (opcao != 0);

    return 0;
}