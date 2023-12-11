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

    std::cout << "Digite seu CPF: ";
    while (true){
     try{ 
      std::cin>>cpf;

        if(cpf.size()<11 || cpf.size()>11){
          throw std::out_of_range ("CPF Inválido!! Digite um novo CPF com tamanho válido:");
        }

        else{
          for(int i=0; cpf[i] != '\0'; i++){
              if (!isdigit (cpf[i])){
                throw std::invalid_argument ("CPF Inválido!! Digite um novo CPF apenas com números:");
                break;
              }
          }
        }

        break;

     }catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;

     }catch (std::out_of_range &e2){
        std::cerr<<e2.what()<<std::endl;
     }    
    }

    std::cout << std::endl << "Informe o mes: ";
     while (true){
     try
     {
      std::cin>>mes;
      if(mes != "1" && mes != "2" && mes != "3" && mes != "4" && mes != "5" && mes != "6" && mes != "7" && mes != "8" && mes != "9" && mes != "10" && mes != "11" && mes != "11"){
        throw std::invalid_argument ("O mês digitado não existe! Digite um mês válido (1 à 12): ");
      }

      break;
     }
     catch(const std::invalid_argument& e)
     {
        std::cerr << e.what() << '\n';
     }
    }
    std::cout<<std::endl;
    std::cout<<"Qual é o modelo jurídico da empresa? \n";
    std::cout<<"(1)- Industrial \n"<<"(2)- Comercial \n"<<"(3)- Prestação de Serviço \n";
    while(true){
      try{
        std::cin>>mod;
        if(mod != "1" && mod != "2" && mod != "3"){
          throw std::invalid_argument ("Opção inválida!! Digite uma opção válida: ");
        }

         break;
        }catch(std::invalid_argument &e){
          std::cerr<<e.what()<<std::endl;
      }
    }
    std::cout << std::endl;

    if(mod == "1"){
        std::fstream in("data/Usuarios_Juridico_Industrial.csv", std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }
        
        std::string aux1, aux2;

        while (in.peek() != EOF){

            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            if (aux1 == cpf && aux2 == mes){
                for(int i = 0; i < 4;i++){
                    getline(in, aux1, ',');
                    getline(in, aux2, '\n');
                    std::cout << aux1 << ": " << aux2 << std::endl;
                }
                for(int i = 0; i < 6;i++){
                    getline(in, aux1, '\n');
                    for(int j = 0; j < aux1.size(); j++){
                        if(aux1[j] == ','){
                            std::cout << " ";
                        }
                        else{
                            std::cout << aux1[j];
                        }
                    }
                    std::cout << std::endl;
                }
                in.close();
                return;
            }
            for(int i = 0; i < 11; i++) getline(in, aux1, '\n');
        }
        
    }
    else if(mod == "2"){
        std::fstream in("data/Usuarios_Juridico_Comercial.csv", std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }
        
        std::string aux1, aux2;


        while (in.peek() != EOF){

            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            if (aux1 == cpf && aux2 == mes){
                for(int i = 0; i < 4;i++){
                    getline(in, aux1, ',');
                    getline(in, aux2, '\n');
                    std::cout << aux1 << ": " << aux2 << std::endl;
                }
                for(int i = 0; i < 5;i++){
                    getline(in, aux1, '\n');
                    for(int j = 0; j < aux1.size(); j++){
                        if(aux1[j] == ','){
                            std::cout << " ";
                        }
                        else{
                            std::cout << aux1[j];
                        }
                    }
                    std::cout << std::endl;
                }
                in.close();
                return;
                
            }
        }
        for(int i = 0; i < 8; i++) getline(in, aux1, '\n');  
    }
    else if(mod == "3"){
        std::fstream in("data/Usuarios_Juridico_Prestacao_de_Servico", std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }
        
        std::string aux1, aux2;

        while (in.peek() != EOF){

            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            if (aux1 == cpf && aux2 == mes){
                for(int i = 0; i < 4;i++){
                    getline(in, aux1, ',');
                    getline(in, aux2, '\n');
                    std::cout << aux1 << ": " << aux2 << std::endl;
                }
                for(int i = 0; i < 5;i++){
                    getline(in, aux1, '\n');
                    for(int j = 0; j < aux1.size(); j++){
                        if(aux1[j] == ','){
                            std::cout << " ";
                        }
                        else{
                            std::cout << aux1[j];
                        }
                    }
                    std::cout << std::endl;
                }
                in.close();
                return;
                
            }
        }
        for(int i = 0; i < 8; i++) getline(in, aux1, '\n');
        
    }

    return;
}