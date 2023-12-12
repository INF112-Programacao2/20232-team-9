#include <iostream>
#include <cstring>
#include "pessoajuridica.h"
#include "pessoa.h"


PessoaJuridica::PessoaJuridica(std::string nomepessoa, std::string nomeempresa, std::string apelidoempresa, std::string local):

Pessoa (nomepessoa, local), _nomeempresa (nomeempresa), _apelidoempresa (apelidoempresa) {}


void PessoaJuridica::insere_cnpj ( ){

    while (true){
     try{ 
      std::cin>>_cnpj;

        if(_cnpj.size()<14 || _cnpj.size()>14){
          throw std::out_of_range ("CNPJ Inválido!! Digite um novo CNPJ com tamanho válido (14):");
        }

        else{
          for(int i=0; _cnpj[i] != '\0'; i++){
              if (!isdigit (_cnpj[i])){
                throw std::invalid_argument ("CNPJ Inválido!! Digite um novo CNPJ apenas com números (14):");
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



void PessoaJuridica::edicao_cadastro (PessoaJuridica &juridico){
    std::string opcao;
    bool averigua=false;
    int selecionador;

          while (averigua==false){
            std::cout<<std::endl;
            std::cout<<"Qual dado deseja alterar? \n";
            std::cout<<"1- Nome do proprietário (DIGITE 1) \n";
            std::cout<<"2- Nome da empresa (DIGITE 2) \n";
            std::cout<<"3- Apelido da empresa (DIGITE 3) \n";
            std::cout<<"4- Localidade (DIGITE 4) \n";
            std::cout<<"5- CNPJ (DIGITE 5) \n";
            std::cout<<"6- CPF (DIGITE 6) \n";
            while(true){
              try{
                std::cin>>opcao;

                if(opcao != "1" && opcao != "2" && opcao != "3" && opcao != "4" && opcao != "5" && opcao !="6"){
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
                
                  std::cout<<"Digite o novo nome do proprietário: \n";
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

                case (2):

                  std::cout<<"Digite o novo nome da empresa: \n";
                  std::cin.ignore ();
                  getline (std::cin, _nomeempresa); 
                  break;

                case (3):

                  std::cout<<"Digite o novo apelido da empresa: \n";
                  std::cin.ignore ();
                  getline (std::cin, _apelidoempresa); 
                  break;

                case(4):

                  std::cout<<"Digite o número correpondente ao novo estado em que a empresa encontra-se localizada: \n";
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

                case(5): 

                  std::cout<<"Digite o novo CNPJ: \n"; 
                  juridico.insere_cnpj ( );
                  break;

                default:
                  std::cout<<"Digite o novo CPF: \n";
                  juridico.insere_cpf ( );
                  break;  
            }
                averigua=juridico.confirma_cadastro (juridico);

                if(averigua==true){
                  std::cout<<"Cadastro realizado com sucesso! Obrigado!! \n";
                }
        }
    }



bool PessoaJuridica::confirma_cadastro (PessoaJuridica &juridico){
  
  std::string opcao;

    std::cout<<std::endl;
    std::cout<<"NOME: "<<juridico.get_nomepessoa()<<" | CNPJ: "<<juridico.get_cnpj()<<" | CPF: "<<juridico.get_cpf()
    <<" | NOME EMPRESA: "<<juridico.get_nomeempresa()<<" | APELIDO EMPRESA: "<<juridico.get_apelidoempresa()<<
    " | LOCALIDADE: "<<juridico.get_local();
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


std::string PessoaJuridica::get_nomeempresa (){

    return _nomeempresa;

}


std::string PessoaJuridica::get_apelidoempresa(){

    return _apelidoempresa;

}


std::string PessoaJuridica::get_cnpj(){

    return _cnpj;

}


void PessoaJuridica::set_nomeempresa (std::string nomeempresa){

    _nomeempresa = nomeempresa;

}

void PessoaJuridica::set_apelidoempresa (std::string apelidoempresa){

    _apelidoempresa = apelidoempresa;

}

void PessoaJuridica::set_cnpj(std::string cnpj){
  _cnpj = cnpj;
}

void PessoaJuridica::set_modelo_negocio(std::string modelo_empresa){
  _modeloempresa = modelo_empresa;
}

void PessoaJuridica::modelo_negocio (){
  std::string opcao;

  std::cout<<"Qual é o modelo jurídico da empresa? \n";
  std::cout<<"(1)- Industrial \n"<<"(2)- Comercial \n"<<"(3)- Prestação de Serviço \n";
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
    _modeloempresa="Industrial";
  } 
  else if(opcao=="2"){
    _modeloempresa="Comercial";
  } 
  else{
    _modeloempresa="Prestação de Serviço";
  }

}


std::string PessoaJuridica::get_modelo_negocio (){

  return _modeloempresa;

}

