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
    
    //declaracao de variaveis
    std::string cnpj, mes, mod;
    bool mes_valido = false;
    bool cnpj_valido = false;

    std::cout << "Digite seu CNPJ: ";

    //tratamento de excecao para entradas invalidas 
    while (true){
     try{ 
      std::cin>>cnpj;

        if(cnpj.size()<14 || cnpj.size()>14){
          throw std::out_of_range ("CNPJ Inválido!! Digite um novo CNPJ com tamanho válido:");
        }

        else{
          for(int i=0; cnpj[i] != '\0'; i++){
              if (!isdigit (cnpj[i])){
                throw std::invalid_argument ("CNPJ Inválido!! Digite um novo CNPJ apenas com números:");
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

    //pergunta o modelo de negocio
    std::cout<<std::endl;
    std::cout<<"Qual é o modelo jurídico da empresa? \n";
    std::cout<<"(1)- Industrial \n"<<"(2)- Comercial \n"<<"(3)- Prestação de Serviço \n";

    //tratamento de excecao para entradas invalidas
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

    //confere o modelo de negocio a ser seguido
    if(mod == "1"){
        std::cout << std::endl
                  << "Informe o mes: ";

        //tratamento de excecao para entrada invalida
        while (true)
        {
            try
            {
                std::cin >> mes;
                if (mes != "1" && mes != "2" && mes != "3" && mes != "4" && mes != "5" && mes != "6" && mes != "7" && mes != "8" && mes != "9" && mes != "10" && mes != "11" && mes != "11")
                {
                    throw std::invalid_argument("O mês digitado não existe! Digite um mês válido (1 à 12): ");
                }

                break;
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        //abre arquivo
        std::fstream in("data/Usuarios_Juridico_Industrial.csv", std::ios::in);

        //verifica abertura
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }


        //variaveis auxiliares
        std::string aux1, aux2;
        
        //percorre arquivo
        while (in.peek() != EOF){
            

            //le dados da linha
            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            //confere igualdade de cnpj informado e lido
            if (aux1 == cnpj){

                //confere se foi achado algum cpf valido

                cnpj_valido = true;
                    if(aux2 == mes){
                    //confere se foi achado algum mes valido com o cpf informado
                    mes_valido = true;

                    //printa 4 linhas
                    for(int i = 0; i < 4;i++){
                        getline(in, aux1, ',');
                        getline(in, aux2, '\n');
                        std::cout << aux1 << ": " << aux2 << std::endl;
                    }

                    //for alinhado para printar 6 linhas de vetor
                    for(int i = 0; i < 6;i++){
                        getline(in, aux1, '\n');
                        for(int j = 0; j < aux1.size(); j++){
                           
                            //if para formatar no prompt corretamente
                            if(aux1[j] == ','){
                                std::cout << " ";
                            }
                            else{
                                std::cout << aux1[j];
                            }
                        }
                        std::cout << std::endl;
                    }
                    //fechamento de arquivo  
                    in.close();
                    return;
                }
            }

            //numero de linhas puladas para caso cnpj ou mes nao tenha sido achado
            for (int i = 0; i < 11; i++)
                getline(in, aux1, '\n');
        }
    }

    //o processo realizado e o mesmo do modelo 1, porem com arquivo comercial sendo percorrido
    else if(mod == "2"){
        std::cout << std::endl
                  << "Informe o mes: ";
        while (true)
        {
            try
            {
                std::cin >> mes;
                if (mes != "1" && mes != "2" && mes != "3" && mes != "4" && mes != "5" && mes != "6" && mes != "7" && mes != "8" && mes != "9" && mes != "10" && mes != "11" && mes != "11")
                {
                    throw std::invalid_argument("O mês digitado não existe! Digite um mês válido (1 à 12): ");
                }

                break;
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        std::fstream in("data/Usuarios_Juridico_Comercial.csv", std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }

        std::string aux1, aux2;

        while (in.peek() != EOF)
        {

            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            if (aux1 == cnpj)
            {
                cnpj_valido = true;
                if (aux2 == mes)
                {
                    mes_valido = true;
                    for (int i = 0; i < 4; i++)
                    {
                        getline(in, aux1, ',');
                        getline(in, aux2, '\n');
                        std::cout << aux1 << ": " << aux2 << std::endl;
                    }
                    for (int i = 0; i < 5; i++)
                    {
                        getline(in, aux1, '\n');
                        for (int j = 0; j < aux1.size(); j++)
                        {
                            if (aux1[j] == ',')
                            {
                                std::cout << " ";
                            }
                            else
                            {
                                std::cout << aux1[j];
                            }
                        }
                        std::cout << std::endl;
                    }
                    in.close();
                    return;
                }
            }
            for (int i = 0; i < 10; i++)
                getline(in, aux1, '\n');
        }
    }

    //o processo realizado e o mesmo do modelo 1, porem com arquivo de prestacao de servico sendo percorrido
    else if(mod == "3"){
        std::cout << std::endl
                  << "Informe o mes: ";
        while (true)
        {
            try
            {
                std::cin >> mes;
                if (mes != "1" && mes != "2" && mes != "3" && mes != "4" && mes != "5" && mes != "6" && mes != "7" && mes != "8" && mes != "9" && mes != "10" && mes != "11" && mes != "11")
                {
                    throw std::invalid_argument("O mês digitado não existe! Digite um mês válido (1 à 12): ");
                }

                break;
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        std::fstream in("data/Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::in);
        if (!in.is_open())
        {
            std::cerr << "FALHA AO ABRIR O ARQUIVO!" << std::endl;
            return;
        }

        std::string aux1, aux2;

        while (in.peek() != EOF)
        {

            getline(in, aux1, ',');
            getline(in, aux2, ',');
            getline(in, aux2, ',');

            if (aux1 == cnpj)
            {
                cnpj_valido = true;
                if (aux2 == mes)
                {
                    mes_valido = true;
                    for (int i = 0; i < 4; i++)
                    {
                        getline(in, aux1, ',');
                        getline(in, aux2, '\n');
                        std::cout << aux1 << ": " << aux2 << std::endl;
                    }
                    for (int i = 0; i < 5; i++)
                    {
                        getline(in, aux1, '\n');
                        for (int j = 0; j < aux1.size(); j++)
                        {
                            if (aux1[j] == ',')
                            {
                                std::cout << " ";
                            }
                            else
                            {
                                std::cout << aux1[j];
                            }
                        }
                        std::cout << std::endl;
                    }
                    in.close();
                    return;
                }
            }
            for (int i = 0; i < 10; i++){
                getline(in, aux1, '\n');
            }
        }
    }
    if(!mes_valido && cnpj_valido==true){
        std::cout << std::endl;
        std::cout << "Mês não registrado no Sistema!" << std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "CNPJ não registrado no Sistema!" << std::endl;

    return;
}