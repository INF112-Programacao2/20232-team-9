#include <iostream>
#include <cstring>
#include "pessoa.h"
#include "pessoajuridica.h"

void confere_nomes (std::string &nome){

  while(true){
    try{
      for (int i=0; nome[i] != '\0'; i++){
        if((nome.at(i) == ' ') && i != 0){
            continue;
        }
        else if(!isalpha (nome[i])){
          throw std::invalid_argument ("Nome inválido!! O nome deve conter apenas letras! Digite novamente:");
          break;
         }
       }

       break;
      }catch (std::invalid_argument &e){
        std::cout<<e.what()<<std::endl;
        getline(std::cin,nome);
      }   
  }

}


int main(){

    std::string nomepessoa, nomeempresa, apelidoempresa, local, cnpj, cpf, opcao;
    int confirmacao, selecionador;

    std::cout<<"Olá cliente! \n";
    std::cout<<"Deseja realizar qual tipo de contabilidade? \n";
    std::cout<<"1- Contabilidade Jurídica. \n";
    std::cout<<"2- Contabilidade Física. \n";
    std::cout<<"Digite 1 para Contabilidade Jurídica ou 2 para Contabilidade Física: \n";   
    while(true){
      try{
        std::cin>>opcao;
        if(opcao != "1" && opcao != "2"){
          throw std::invalid_argument ("Opção inválida!! Digite 1 para Contabilidade Jurídica ou 2 para Contabilidade Física:");
        }

        break;

      }catch(std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;
      }
    }

    if(opcao=="1"){

        std::cout<<std::endl;
        std::cout<<"Bem-vindo, cliente! \n";
        std::cout<<"Iremos iniciar o cadastro. \n";
        std::cout<<"Digite o nome completo do proprietário da empresa: \n";
        std::cin.ignore();
        getline (std::cin, nomepessoa);
        confere_nomes(nomepessoa);
        std::cout<<"Digite o nome da empresa: \n";
        getline (std::cin, nomeempresa);
        std::cout<<"Digite o apelido da empresa: \n";
        getline (std::cin, apelidoempresa);
        std::cout<<"Digite o número correpondente ao estado em que a empresa encontra-se localizada: \n";
        std::cout<<"(1)- MG \n"<<"(2)- SP \n"<<"(3)- RJ \n";
        while(true){
          try{
            std::cin>>opcao;
              if(opcao != "1" && opcao != "2" && opcao != "3"){
                throw std::invalid_argument ("Opção inválida!! Digite uma opção válida: ");
              }

            break;
          }catch(std::invalid_argument &e){
            std::cerr<<e.what()<<std::endl;
          }
        }
        if(opcao=="1"){
          local="MG";
        }
        else if(opcao=="2"){
          local="SP";
        }
        else{
          local="RJ";
        }

        PessoaJuridica juridico (nomepessoa, nomeempresa, apelidoempresa, local);
        std::cout<<"Digite o CNPJ do proprietario: \n";
        juridico.insere_cnpj( );
        std::cout<<"Digite o CPF do proprietario: \n";
        juridico.insere_cpf ( );
        std::cout<<std::endl;
        if(juridico.confirma_cadastro (juridico) == true){
          std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";
        }
        else{
          juridico.edicao_cadastro (juridico);
        }

    }

    else if(opcao=="2"){

        std::cout<<std::endl;
        std::cout<<"Bem-vindo, cliente! \n";
        std::cout<<"Iremos iniciar o cadastro. \n";
        std::cout<<"Digite seu nome completo: \n";
        std::cin.ignore();
        getline (std::cin, nomepessoa);
        confere_nomes(nomepessoa);
        std::cout<<"Digite o número correpondente ao seu estado de residência: \n";
        std::cout<<"(1)- MG \n"<<"(2)- SP \n"<<"(3)- RJ \n";
        while(true){
          try{
            std::cin>>opcao;
              if(opcao != "1" && opcao != "2" && opcao != "3"){
                throw std::invalid_argument ("Opção inválida!! Digite uma opção válida: ");
              }

            break;
          }catch(std::invalid_argument &e){
            std::cerr<<e.what()<<std::endl;
          }
        }
        if(opcao=="1"){
          local="MG";
        }
        else if(opcao=="2"){
          local="SP";
        }
        else{
          local="RJ";
        }

        Pessoa fisico (nomepessoa, local);
        std::cout<<"Digite o CPF do proprietario: \n";
        fisico.insere_cpf ( );
        std::cout<<std::endl;
        if(fisico.confirma_cadastro_fis (fisico) == true){
          std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";
        }
        else{
          fisico.edicao_cadastro_fis (fisico);
        }
    }

 return 0;
}