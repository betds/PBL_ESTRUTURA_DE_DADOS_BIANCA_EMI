#include <iostream>
#include <string>
#include <vector>
#include "conio.h"

#define MAX 10
using namespace std;

struct Player
{
	int id;
	string name;
	int level;
	int score;
	int age;
};

int main()
{
	Player newPlayer;
	bool open = true;
	bool structure = true;
	int selection = 0;
	int selection2 = 0;
	int getKey = 0;
	int registered = 0;
	int index = 0;
	int error = 0;
	bool outRegister = false;

	while (open)
	{
		Player player[MAX];
		vector<Player> playerD;

		for (int i = 0; i < MAX; i++) {
			player[i].id = -1;
			player[i].name = "";
			player[i].age = 0;
			player[i].level = 0;
			player[i].score = -1;
		}
		newPlayer.id = 0;
		newPlayer.name = "none";
		newPlayer.age = 0;
		newPlayer.level = 0;
		newPlayer.score = 0;
		
		playerD.push_back(newPlayer);

		system("cls");
		cout << "Selecione uma opcao:" << endl;
		cout << (selection2 == 0 ? "[" : "") << "1. Array[10]" << (selection2 == 0 ? "]" : "") << endl;
		cout << (selection2 == 1 ? "[" : "") << "2. Alocacao Dinamica" << (selection2 == 1 ? "]" : "") << endl;
		cout << (selection2 == 2 ? "[" : "") << "3. Sair" << (selection2 == 2 ? "]" : "") << endl;
		getKey = _getche();

		if (getKey == 72) selection2--;
		if (getKey == 80) selection2++;
		if (selection2 < 0) selection2 = 2;
		if (selection2 > 2) selection2 = 0;

		if (getKey == 13) {
			switch (selection2)
			{
				// Array[10]
			case 0:
#pragma region ARRAY
				while (structure)
				{
					system("cls");
					cout << "Selecione uma opcao:" << endl;
					cout << (selection == 0 ? "[" : "") << "1. Cadastrar um novo Player" << (selection == 0 ? "]" : "") << endl;
					cout << (selection == 1 ? "[" : "") << "2. Listar todos os Players" << (selection == 1 ? "]" : "") << endl;
					cout << (selection == 2 ? "[" : "") << "3. Buscar um Player" << (selection == 2 ? "]" : "") << endl;
					cout << (selection == 3 ? "[" : "") << "4. Excluir um Player" << (selection == 3 ? "]" : "") << endl;
					cout << (selection == 4 ? "[" : "") << "5. Voltar para o menu anterior" << (selection == 4 ? "]" : "") << endl;
					cout << (selection == 5 ? "[" : "") << "6. Sair" << (selection == 5 ? "]" : "") << endl;
					getKey = _getche();

					if (getKey == 72) selection--;
					if (getKey == 80) selection++;
					if (selection < 0) selection = 5;
					if (selection > 5) selection = 0;

					if (getKey == 13) {
						system("cls");
						switch (selection)
						{
							// Cadastrar um novo Player
						case 0:
							outRegister = false;
							cout << "[CADASTRO]" << endl;
							if (registered >= 10) {
								cout << "Nao existem vagas disponiveis para novos cadastros. Remova algum usuario para cadastrar um novo." << endl;
								getKey = _getche();
							}
							else {
								for (int i = 0; i < MAX; i++) {
									if (player[i].name == "" && outRegister == false) {
										outRegister = true;
										cout << "ID: " << i + 1 << endl;
										player[i].id = i + 1;
										cout << "Nome: ";
										cin >> player[i].name;
										cout << "Idade: ";
										error = 0;
										while (player[i].age < 0 || player[i].level > 111)
										{
											if (error > 0)
												cout << "Valor invalido, insira um novo valor: ";
											cin >> player[i].age;
											error++;
										}
										cin >> player[i].age;
										cout << "Nivel entre 1 a 5";
										cout << endl;
										cout << "Nivel: ";
										error = 0;
										while (player[i].level < 1 || player[i].level > 5)
										{
											if (error > 0)
												cout << "Valor invalido, insira um novo valor: ";
											cin >> player[i].level;
											error++;
										}
										cout << "Score: ";
										cin >> player[i].score;
										cout << "Usuario registrado com sucesso!" << endl;
										registered++;
									}
								}
							}

							getKey = _getche();
							break;

							// Listar todos os players
						case 1:
							cout << "[LISTA]" << endl << endl;
							for (int i = 0; i < 10; i++) {
								cout << (player[i].id < 10 ? "0" : "")
									<< player[i].id
									<< ": " << player[i].name
									<< ", " << player[i].age << " anos "
									<< ", score: " << player[i].score << endl;
							}
							getKey = _getche();
							break;

							// Buscar um determinado player
						case 2:
							cout << "[BUSCA]" << endl;
							cout << "Qual indice voce quer pesquisar? (De 1 a 10)" << endl;
							do {
								cin >> index;
							} while (index < 1 || index > 10);
							index--;
							if (player[index].id != 0) {
								cout << "ID: " << player[index].id << endl;
								cout << "Nome: " << player[index].name << endl;
								cout << "Idade: " << player[index].age << endl;
								cout << "Nivel: " << player[index].level << endl;
								cout << "Score: " << player[index].score << endl;
							}
							else {
								cout << "Player nao localizado." << endl;
							}
							index = 0;
							getKey = _getche();
							break;

							// Excluir um elemento
						case 3:
							cout << "[EXCLUSAO]" << endl;
							cout << "Qual indice voce quer excluir? (De 1 a 10)" << endl;
							do {
								cin >> index;
							} while (index < 1 || index > 10);
							index--;
							if (player[index].id != 0)
							{
								cout << "ID: " << player[index].id << endl;
								cout << "Nome: " << player[index].name << endl;
								cout << "Score: " << player[index].score << endl;
								cout << "Idade: " << player[index].age << endl;
								player[index].id = 0;
								player[index].name = "";
								player[index].score = 0;
								player[index].level = 0;
								player[index].age = 0;
								registered--;
								cout << endl;
								cout << "Usuario removido com sucesso." << endl;
								index = 0;
							}
							getKey = _getche();
							break;

							// Voltar para o primeiro menu
						case 4:
							structure = false;
							break;

							// Fechar o programa
						case 5:
							return 0;
							break;
						default:
							break;
						}
					}
				}
#pragma endregion
				break;
				// Alocacao Dinamica
			case 1:
#pragma region ALOCAÇÃO DINÂMICA
				while (structure)
				{
					system("cls");
					cout << "Selecione uma opcao:" << endl;
					cout << (selection == 0 ? "[" : "") << "1. Cadastrar um novo Player" << (selection == 0 ? "]" : "") << endl;
					cout << (selection == 1 ? "[" : "") << "2. Listar todos os Players" << (selection == 1 ? "]" : "") << endl;
					cout << (selection == 2 ? "[" : "") << "3. Buscar um Player" << (selection == 2 ? "]" : "") << endl;
					cout << (selection == 3 ? "[" : "") << "4. Excluir um Player" << (selection == 3 ? "]" : "") << endl;
					cout << (selection == 4 ? "[" : "") << "5. Voltar para o menu anterior" << (selection == 4 ? "]" : "") << endl;
					cout << (selection == 5 ? "[" : "") << "6. Sair" << (selection == 5 ? "]" : "") << endl;
					getKey = _getche();

					if (getKey == 72) selection--;
					if (getKey == 80) selection++;
					if (selection < 0) selection = 5;
					if (selection > 5) selection = 0;

					if (getKey == 13) {
						system("cls");
						switch (selection)
						{
							// Cadastrar um novo Player
						case 0:
							cout << "[CADASTRO]" << endl;
							cout << "ID: " << playerD.size() + 1 << endl;
							newPlayer.id = playerD.size() + 1;
							cout << "Nome: ";
							cin >> newPlayer.name;
							cout << "Idade: ";
							error = 0;
							while (newPlayer.age < 1 || newPlayer.age > 111)
							{
								if (error > 0)
									cout << "Valor invalido, insira um novo valor: ";
								cin >> newPlayer.age;
								error++;
							}
							cout << endl;
							cout << "Nivel entre 1 a 5";
							cout << endl;
							cout << "Nivel: ";
							error = 0;
							while (newPlayer.level < 1 || newPlayer.level > 5)
							{
								if (error > 0)
									cout << "Valor invalido, insira um novo valor: ";
								cin >> newPlayer.level;
								error++;
							}
							cout << endl;
							cout << "Score: ";
							cin >> newPlayer.score;
							cout << endl;
							cout << "Usuario registrado com sucesso!" << endl;
							playerD.push_back(newPlayer);
							getKey = _getche();

							break;

							// Listar todos os players
						case 1:
							cout << "[LISTA]" << endl << endl;
							for (int i = 0; i < playerD.size(); i++) {
								cout << (playerD.at(i).id < 10 ? "0" : "")
									<< playerD.at(i).id << ": "
									<< playerD.at(i).name
									<< ", " << playerD.at(i).age << "anos "
									<< ", score: " << playerD.at(i).score << endl;

							}
							getKey = _getche();
							break;

							// Buscar um determinado player
						case 2:
							cout << "[BUSCA]" << endl;
							cout << "Qual indice voce quer pesquisar? (De 1 " << playerD.size() << ")" << endl;
							do {
								cin >> index;
							} while (index < 1 || index > 10);
							index--;
							if (playerD.at(index).id != 0) {
								cout << "ID: " << playerD.at(index).id << endl;
								cout << "Nome: " << playerD.at(index).name << endl;
								cout << "Idade: " << playerD.at(index).name << endl;
								cout << "Nivel: " << playerD.at(index).name << endl;
								cout << "Score: " << playerD.at(index).score << endl << endl;
							}
							else {
								cout << "Usuario nao localizado." << endl;
							}
							index = 0;
							getKey = _getche();
							break;

							// Excluir um elemento
						case 3:
							cout << "[EXCLUSAO]" << endl;
							if (playerD.size() == 1)
							{
								cout << "Nao ha player para voce excluir" << endl;

							}
							else
							{
								cout << "Qual indice voce quer excluir? (De 1 " << playerD.size() << ")" << endl;
								do {
									cin >> index;
								} while (index < 1 || index > 10);
								if (playerD.at(index).id != 0) {
									cout << "ID: " << playerD.at(index).id << endl;
									cout << "Nome: " << playerD.at(index).name << endl;
									cout << "Idade: " << playerD.at(index).age << endl;
									cout << "Nivel: " << playerD.at(index).level << endl;
									cout << "Score: " << playerD.at(index).score << endl;
									playerD.erase(playerD.begin() + index);
									cout << endl;
									cout << "Usuario removido com sucesso." << endl;
									index = 0;
								}
							}
							getKey = _getche();
							break;

							// Voltar para o primeiro menu
						case 4:
							structure = false;
							break;

							// Fechar o programa
						case 5:
							return 0;
							break;
						default:
							break;
						}

					}
				}
#pragma endregion
				break;

				// Sair
			case 2:
				return 0;
				break;
			default:
				break;
			}
		}
	}
}
