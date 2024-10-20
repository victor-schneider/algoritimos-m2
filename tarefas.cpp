#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include "tarefas.hpp"

//tranferir tarefas de uma equipe para outra atraves do id da equipe no array de tarefa

// Função para criar uma nova tarefa
json criarTarefa(int id, string nome, string equipe, int prioridade, string prazo, string status) {
    json tarefa;
    tarefa["id"] = id;
    tarefa["nome"] = nome;
    tarefa["equipe"] = equipe; // pesquisar id ou nome da equipe qnd for adicionar a tarefa, como no trabalho da biblioteca
    tarefa["prioridade"] = prioridade;
    tarefa["prazo"] = prazo;
    tarefa["status"] = status;
    return tarefa;
}

// Função para deletar uma tarefa pelo ID
json deletarTarefa(int id, json& tarefas) {
    json tarefasAtualizadas = json::array();
    for (auto& tarefa : tarefas) {
        if (tarefa["id"] != id) {
            tarefasAtualizadas.push_back(tarefa);  // Mantém as outras tarefas
        }
    }
    return tarefasAtualizadas;
}

// Função para modificar uma tarefa
void modificarTarefa(int id, json& tarefas) {
    for (auto& tarefa : tarefas) {
        if (tarefa["id"] == id) {
            cout << "Novo nome da tarefa: ";
            string novoNome;
            cin.ignore();
            getline(cin, novoNome);
            cout << "Nova equipe designada: ";
            string novaEquipe;
            getline(cin, novaEquipe);
            cout << "Nova prioridade (1-5): ";
            int novaPrioridade;
            cin >> novaPrioridade;
            cout << "Novo prazo (YYYY-MM-DD): ";
            string novoPrazo;
            cin.ignore();
            getline(cin, novoPrazo);
            cout << "Novo status: ";
            string novoStatus;
            getline(cin, novoStatus);
            // Atualizando os dados da tarefa
            tarefa["nome"] = novoNome;
            tarefa["equipe"] = novaEquipe;
            tarefa["prioridade"] = novaPrioridade;
            tarefa["prazo"] = novoPrazo;
            tarefa["status"] = novoStatus;
            cout << "Tarefa atualizada com sucesso!" << endl;
            return;
        }
    }
    cout << "Tarefa não encontrada!" << endl;
}

// Função para imprimir todas as tarefas
void imprimirTarefas(const json& tarefas) {
    cout << "Lista de Tarefas: " << endl;
    for (const auto& tarefa : tarefas) {
        cout << "ID: " << tarefa["id"] << ", Nome: " << tarefa["nome"]
             << ", Equipe: " << tarefa["equipe"] << ", Prioridade: " << tarefa["prioridade"]
             << ", Prazo: " << tarefa["prazo"] << ", Status: " << tarefa["status"] << endl;
    }
}