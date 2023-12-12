#include <iostream>
#include <cstring>
#include "pessoa.h"


Pessoa::Pessoa (std::string nomepessoa, std::string local):

_nomepessoa(nomepessoa), _local(local) {}



void Pessoa::insere_cpf ( ) {
   
    while (true){
     try{ 
      std::cin>>_cpf;

        if(_cpf.size()<11 || _cpf.size()>11){
          throw std::out_of_range ("CPF Inválido!! Digite um novo CPF com tamanho válido (11):");
        }

        else{
          for(int i=0; _cpf[i] != '\0'; i++){
              if (!isdigit (_cpf[i])){
                throw std::invalid_argument ("CPF Inválido!! Digite um novo CPF apenas com números (11):");
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

}

void Pessoa::edicao_cadastro_fis (Pessoa &fisico){
    std::string opcao;
    bool averigua=false;
    int selecionador;

          while (averigua==false){
            std::cout<<std::endl;
            std::cout<<"Qual dado deseja alterar? \n";
            std::cout<<"1- Nome do proprietário (DIGITE 1) \n";
            std::cout<<"2- Localidade (DIGITE 2) \n";
            std::cout<<"3- CPF (DIGITE 3) \n";
            while(true){
              try{
                std::cin>>opcao;

                if(opcao != "1" && opcao != "2" && opcao != "3"){
                 throw std::invalid_argument ("Opção inválida!! Digite uma opção válida:");
                }
                else{
                  selecionador=stoi(opcao);
                  break;
               }

              }catch(std::invalid_argument &e){
                std::cerr<<e.what()<<std::endl;
                }
            }
            
            switch (selecionador){
                case (1):
                
                  std::cout<<"Digite o novo nome que deseja cadastrar: \n";
                  while(true){
                    try{
                      std::cin.ignore ();
                      getline(std::cin,_nomepessoa);
                       for (int i=0; _nomepessoa[i] != '\0'; i++){
                          if((_nomepessoa.at(i) == ' ') && i != 0){
                            continue;
                          }
                          else if(!isalpha (_nomepessoa[i])){
                            throw std::invalid_argument ("Nome inválido!! O nome deve conter apenas letras! Digite novamente:");
                            break;
                          }
                        }

                        break;
                     }catch (std::invalid_argument &e){
                        std::cout<<e.what()<<std::endl;
                      }   
                  }
                  break;

                case(2):

                  std::cout<<"Digite o número correpondente ao novo estado de residência: \n";
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
                    _local="MG";
                  }
                  else if(opcao=="2"){
                   _local="SP";
                  }
                  else{
                   _local="RJ";
                  }
                  break;

                case(3): 

                  std::cout<<"Digite o novo CPF: \n";
                  fisico.insere_cpf ( );
                  break;  

            }
                averigua=fisico.confirma_cadastro_fis (fisico);

                if(averigua==true){
                  std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";
                }
        }
    }



bool Pessoa::confirma_cadastro_fis (Pessoa &fisico){
  
  std::string opcao;

    std::cout<<std::endl;
    std::cout<<"NOME: "<<fisico.get_nomepessoa()<<" | CPF: "<<fisico.get_cpf()<<" | LOCALIDADE: "<<fisico.get_local();
    std::cout<<std::endl;
    std::cout<<"Você confirma os dados inseridos no cadastro? \n";
    std::cout<<"1- Sim. \n";
    std::cout<<"2- Não. \n";
    std::cout<<"Digite 1 para SIM ou 2 para NÃO: \n";
     while(true){
       try{
        std::cin>>opcao;

          if(opcao != "1" && opcao != "2"){
            throw std::invalid_argument ("Opção inválida!! Digite 1 para SIM ou 2 para NÃO:");
          }
            break;
        }catch(std::invalid_argument &e){
          std::cerr<<e.what()<<std::endl;
        }
       }
    
    if(opcao=="1"){
      return true;
    }
    else{
      return false;
    }   

}

void Pessoa::tipo_pessoa (){
 std::string opcao;
  std::cout<<std::endl;
  std::cout<<"Digite o número correspondente ao tipo de pessoa física ao qual se enquadra: \n";
  std::cout<<"(1) - Empregado. \n"<<"(2) - Contribuinte Individual. \n"<<"(3) - Contribuinte Facultativo. \n"<<"(4) - Microempreendedor \n";
  while(true){
   try{
     std::cin>>opcao;
     if(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4"){
       throw std::invalid_argument ("Opção inválida!! Digite uma opção válida: ");
     }
       break;
    }catch(std::invalid_argument &e){
      std::cerr<<e.what()<<std::endl;
    }
  }
  if(opcao=="1"){
    _tipo_pessoa="Empregado";
  }
  else if(opcao=="2"){
    _tipo_pessoa="Contribuinte Individual";
  }
  else if(opcao=="3"){
    _tipo_pessoa="Contribuinte Facultativo";
  }
  else{
    _tipo_pessoa="Microempreendedor";
  }
}

std::string Pessoa::get_nomepessoa (){

    return _nomepessoa;

}


std::string Pessoa::get_cpf(){

    return _cpf;

}


std::string Pessoa::get_local(){

    return _local;

}

std::string Pessoa::get_tipo_pessoa (){

    return _tipo_pessoa;

}


void Pessoa::set_nomepessoa (std::string nomepessoa){

    _nomepessoa = nomepessoa;

}


void Pessoa::set_local (std::string local){

    _local = local;

}

void Pessoa::set_cpf (std::string cpf){

    _cpf = cpf;

}

void Pessoa::set_tipo_pessoa (std::string tipo_pessoa){

    _tipo_pessoa = tipo_pessoa;

}