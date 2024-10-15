#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

json criarUsuario(int id, string nome, int idade, char sexo){
    json usuario;
    usuario["id"] = id;
    usuario["nome"] = nome;
    usuario["idade"] = idade;
    usuario["sexo"] = sexo;
    return usuario;
}

json deletarUsuario(int id = 0, string nome = "", json usuarios){
    json usuario = json::array();
    for (json usuario : usuarios){
        
    }
}

int main(){
    ifstream arquivoEntrada;
    ofstream arquivoSaida;
    string nome;
    int idade, id;
    char sexo;

    arquivoEntrada.open("C:/Users/allan.slomski/Documents/teste/teste.json");
    arquivoSaida.open("C:/Users/allan.slomski/Documents/teste/teste.json", ios::app);

    json usuarios = json::array();
    arquivoEntrada >> usuarios;
    
    cout << "Nome: " << endl;
    getline(cin, nome);
    cout << "Idade: " << endl;
    cin >> idade;
    cout << "Sexo: " << endl;
    cin >> sexo;

    criarUsuario(1, nome, idade, sexo);


    arquivoSaida << usuarios.dump(4);

}