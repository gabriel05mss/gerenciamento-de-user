#include <iostream>
#include <vector>
#include <string>
using namespace std;
// declarando variaveis
string name;
string email;
string email_login;
int senha;
int senha_login;
// estrutura de usuarios
struct User {
    string name;
    string email;
    int senha;
};
// criar classe
class SistemaUser{
private:
        vector<User>Usuarios;
public:
    //adicionar usuario 
    void AddUser(const string name,const string email,const int senha) {
        User Usuario ={name,email,senha};
        Usuarios.push_back(Usuario);
        cout<< "Novo usuario adicionado"<< endl;
    }
    //mostrar ja cadastrados
    void MostrarAtivos() {
        if (Usuarios.empty()) {
            cout<<" Nenhum usuario cadastrado"<<endl;
            return;
        }
        cout<<"lista de usuarios: "<<endl;
        User Usuario;
        for(const auto& Usuario : Usuarios) {
            cout<<"Nome: "<< Usuario.name << endl;
            cout<< "email: "<< Usuario.email << endl;
        }
    }
    //sistema de login virificar se email e senha inputados estam no vetor usuarios
    bool contem(const string email_login , const int senha_login) {
    for(const auto& Usuario : Usuarios) {
        if(email_login == Usuario.email ) {
            if(senha_login == Usuario.senha) {
               return true; 
                }
            
            }

        }
    return false;
    }
};



int main() {
    SistemaUser sistema;
    sistema.AddUser("Joao", "joao@email.com", 2552);
    sistema.AddUser("Maria", "maria@email.com", 3003);
 cout << "login" << endl;
 cout << "email: ";
 cin>> email_login;
 cout << "senha: ";
 cin>> senha_login;
 if(sistema.contem(email_login , senha_login)) {
    cout << "login feito" << endl;
 } else {
    cout << "----!!OCORREU UM ERRO!!----"<< endl;
    cout << "--As possiveis causas sao:" << endl;
    cout << "-> Email ou senha estao errados" << endl;
    cout << "-> Voce nao e cadastrado no sistema" << endl;
 }
return 0;
}