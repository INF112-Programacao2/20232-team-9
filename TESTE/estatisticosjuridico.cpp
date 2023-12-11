// analise das demonstrações contábeis
#include <iostream>
#include <bits/stdc++.h>
#include "pessoajuridica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_prestservico.h"
#include "juridica_industrial.h"
#include "estatisticosjuridico.h"

void EstatisticosJuridico::dados_mensal(){
    std::string cpf, mes;
    int mod;
    std::fstream in;

    std::cout << "Informe o CPF: ";
    std::cin >> cpf;

    std::cout << std::endl << "Informe o mes: ";
    std::cin >> mes;

    std::cout << std::endl << "Informe o Modelo de Negócio:" << std::endl;
    std::cout << "(1) - Industrial" << std::endl;
    std::cout << "(2) - Comercial" << std::endl;
    std::cout << "(3) - Prestação de Serviço" << std::endl;
    std::cin >> mod;

    std::cout << std::endl;

    if(mod == 1){
        std::fstream in("Usuarios_Juridico_Industrial.csv", std::ios::in);
    }
    else if(mod == 2){
        std::cout << "Entrei aqui" << std::endl;
        std::fstream in("Usuarios_Juridico_Comercial.csv", std::ios::in);
    }
    else if(mod == 3){
        std::fstream in("Usuarios_Juridico_Prestacao_de_Servico", std::ios::in);
    }

    std::cout << mod << std::endl;
    if(!in.is_open()){
        std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
        return;
    }


    std::string aux1, aux2;

    while(in.peek() != EOF){
        
        getline(in, aux1, ',');
        getline(in, aux2, ',');
        getline(in, aux2, ',');

        if(aux1 == cpf && aux2 == mes){
            
            getline(in, aux1, '\n');

            for(int i = 0; i < 9; i++){
                while(aux1 != "//"){
                    getline(in, aux1, ',');
                    if(aux1 != "//"){
                        getline(in, aux2, ',');
                        std::cout << aux1 << aux2;
                    }
                    
                }
            }
            break;
        }
    }
}