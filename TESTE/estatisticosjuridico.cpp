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
    std::string cpf, mes, mod;
    std::fstream in;

    std::cout << "Informe o CPF: ";
    std::cin >> cpf;

    std::cout << std::endl << "Informe o mes: ";
    std::cin >> mes;

    std::cout << std::endl << "Informe o modelo: ";
    std::cin >> mod;

    std::cout << std::endl;

    if (mod == "Industrial")
    {
        std::fstream in("Usuarios_Juridico_Industrial.csv", std::ios::in);
    }
    else if (mod == "Comercial")
    {
        std::fstream in("Usuarios_Juridico_Comercial.csv", std::ios::in);
    }
    else if (mod == "Prestação de Serviço")
    {
        std::fstream in("Usuarios_Juridico_Prestacao_de_Servico", std::ios::in);
    }

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