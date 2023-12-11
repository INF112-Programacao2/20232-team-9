#include <iostream>
#include <bits/stdc++.h>
#include "pessoa.h"
#include "contabilidade_fisica.h"
#include "recebe_arquivo.h"
#include "estatisticosfisico.h"


void EstatisticosFisico::imposto_renda_anual_fisico(){ 
    std::string cpf, ano;
    
    std::cout << "Digite seu CPF: ";
    std::cin >> cpf;

    std::cout << std::endl << "Digite o ano: ";
    std::cin >> ano;
    std::cout << std::endl;

    std::fstream in("Usuarios_Fisico.csv", std::ios::in);

    std::string aux1, aux2;

    while(in.peek() != EOF){
        getline(in, aux1, ',');
        getline(in, aux2, ',');
        getline(in, aux2, '\n');
        
        std::cout << "Dados " << aux2 << ": " << std::endl;

        if(cpf == aux1 && ano == aux2){
            for(int i = 0; i < 6; i++){
                getline(in, aux1, ',');
                getline(in, aux2, '\n');
                std::cout << aux1 << ": " << aux2 << std::endl;
            }
            break;
        }
    }


}

