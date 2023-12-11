#include <iostream>
#include <bits/stdc++.h>
#include "pessoa.h"
#include "contabilidade_fisica.h"
#include "recebe_arquivo.h"
#include "estatisticosfisico.h"


void EstatisticosFisico::imposto_renda_anual_fisico(){ 
    std::string cpf, ano;
    int ano_int;
    
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
    std::cout << std::endl << "Digite o ano: ";
    while (true)
    {
        try
        { // tratamento de exceção para entradas inválidas
            std::cin >> ano;
            ano_int=stoi(ano);
            
            if (ano_int < 2010 || ano_int > 2150)
            {
                throw std::invalid_argument("O ano contábil deve ser um ano válido(entre 2010 e 2150)! Digite novamente: ");
            }
            break;
        }
        catch (std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
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

